#include "commisionemployee.h"
using namespace std;
#include <string>
#include <stdexcept>
#include <iostream>

CommisionEmployee::CommisionEmployee(const string &first, const string &last, const string &ssn, double sales, double rate)
    :Employee(first, last, ssn)
{
    setCommissionRate(rate);
    setGrossSales(sales);

}

double CommisionEmployee::getGrossSales() const
{
    return grossSales;
}

void CommisionEmployee::setGrossSales(double newGrossSales)
{
    if(newGrossSales >= 0.0)
        grossSales = newGrossSales;
    else
        throw invalid_argument("Gross sales msut be > 0");
}

double CommisionEmployee::getCommissionRate() const
{
    return commissionRate;
}

void CommisionEmployee::setCommissionRate(double newCommissionRate)
{
    if(newCommissionRate > 0.0 && newCommissionRate < 1.0)
        commissionRate = newCommissionRate;
    else
        throw invalid_argument("Rate must be 1 - 0 interval");
}

double CommisionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
}

void CommisionEmployee::print() const
{
    Employee::print();
    cout<<getCommissionRate()<<endl
       <<getGrossSales()<<endl;
}







