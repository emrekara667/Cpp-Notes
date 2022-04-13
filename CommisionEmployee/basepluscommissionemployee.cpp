#include "basepluscommissionemployee.h"
#include <iostream>
#include <stdexcept>

using namespace std;

BasePlusCommissionEmployee::BasePlusCommissionEmployee(
        const string &first, const string &last, const string &ssn,
                                       double sales, double rate, double salary)
    :CommissionEmployee(first,last,ssn, sales, rate)
{
    setBaseSalary(salary);
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

void BasePlusCommissionEmployee::setBaseSalary(double salary)
{

    if(salary >= 0.0 ){
        baseSalary = salary;
    }else
        throw invalid_argument("salar must be > 0");
}

double BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings();
}

void BasePlusCommissionEmployee::print() const
{

    CommissionEmployee::print();
    cout<<getBaseSalary()<<endl;
}




