#ifndef BASEPLUSCOMMISSIONEMPLOYEE_H
#define BASEPLUSCOMMISSIONEMPLOYEE_H

#include <string>

#include "commissionemployee.h"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string &, const std::string &, const std::string &,
                               double = 0.0, double = 0.0, double = 0.0 );

    double getBaseSalary() const;
    void setBaseSalary(double newBaseSalary);

    virtual double earnings()const override;
    virtual void print()const override;
private:
    double baseSalary;

};

#endif // BASEPLUSCOMMISSIONEMPLOYEE_H
