#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "employee.h"
#include <string>

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const std::string &, const std::string &,const std::string &, double = 0.0);

    virtual ~SalariedEmployee(){};


    double getWeeklySalary() const;
    void setWeeklySalary(double newWeeklySalary);

    virtual void print() const override; // virtual keyword redundant
    virtual double earnings() const override; // virtual keyword


private:
    double weeklySalary;
};

#endif // SALARIEDEMPLOYEE_H
