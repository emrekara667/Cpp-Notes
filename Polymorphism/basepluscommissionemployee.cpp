#include "basepluscommissionemployee.h"
using namespace std;
#include <iostream>
#include <stdexcept>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const string &first, const string &last, const string &ssn
                                                       , double sales, double rate , double salary)
    :CommisionEmployee(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
}

double BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary;
}

void BasePlusCommissionEmployee::setBaseSalary(double newBaseSalary)
{
    if(newBaseSalary >= 0.0){
        baseSalary = newBaseSalary;
    }
    else
        throw  invalid_argument("Salary must be >= 0");
}

double BasePlusCommissionEmployee::earnings()const
{
    return CommisionEmployee::earnings() + getBaseSalary();
}

void BasePlusCommissionEmployee::print() const
{
    cout<<"Base salaried"<<endl;
    CommisionEmployee::print();
    cout<<getBaseSalary()<<endl;
}
