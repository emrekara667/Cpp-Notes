#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include "commisionemployee.h"

class BasePlusCommissionEmployee : public CommisionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string &, const std::string &, const std::string &, double = 0.0,
                               double = 0.0, double =0.0);

    virtual ~BasePlusCommissionEmployee(){};

    double getBaseSalary() const;
    void setBaseSalary(double newBaseSalary);

    virtual void print()const override;
    virtual double earnings()const override;

private:
    double baseSalary;

};

#endif // BASEPLUSCOMMISSIONEMPLOYEE_H
