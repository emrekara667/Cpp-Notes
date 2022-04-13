#ifndef COMMISIONEMPLOYEE_H
#define COMMISIONEMPLOYEE_H

#include "employee.h"
#include <string>

class CommisionEmployee : public Employee
{
public:
    CommisionEmployee(const std::string &,const std::string & ,const std::string &, double = 0.0, double = 0.0);
    ;
    virtual ~CommisionEmployee(){};


    virtual double earnings()const override; //pure virtual
    virtual void print() const override; //virtual


    double getGrossSales() const;
    void setGrossSales(double newGrossSales);

    double getCommissionRate() const;
    void setCommissionRate(double newCommissionRate);

private:
    double grossSales;
    double commissionRate;
};

#endif // COMMISIONEMPLOYEE_H
