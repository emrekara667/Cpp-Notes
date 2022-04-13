
#include <iostream>
#include <stdexcept>
#include "commissionemployee.h"

using namespace std;

CommissionEmployee::CommissionEmployee(
        const string &first, const string &last, const string &ssn, double sales, double rate
        ):firstName(first),lastName(last),socialSecurityNumber(ssn)
{
    setGrossSales(sales);
    setCommissionRate(rate);
}

 std::string CommissionEmployee::getFirstName() const
{
    return firstName;
}

void CommissionEmployee::setFirstName(const std::string &newFirstName)
{
    firstName = newFirstName;
}

 std::string CommissionEmployee::getLastName() const
{
    return lastName;
}

void CommissionEmployee::setLastName(const std::string &newLastName)
{
    lastName = newLastName;
}

 std::string CommissionEmployee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void CommissionEmployee::setSocialSecurityNumber(const std::string &newSocialSecurityNumber)
{
    socialSecurityNumber = newSocialSecurityNumber;
}

double CommissionEmployee::getGrossSales() const
{
    return grossSales;
}

void CommissionEmployee::setGrossSales(double sales)
{
    if(sales >= 0.0){
        grossSales = sales;
    }else
        throw invalid_argument("Gross sales must be >= 0");
}

double CommissionEmployee::getCommissionRate() const
{
    return commissionRate;
}

void CommissionEmployee::setCommissionRate(double rate)
{
    if(rate > 0.0 && rate < 1.0)
        commissionRate = rate;
    else
        throw  invalid_argument("commision ratye must be > 1.0 < 0");
}


double CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
}

void CommissionEmployee::print() const
{
    cout<<getFirstName()<<endl
       <<getLastName()<<endl
      <<getSocialSecurityNumber()<<endl
     <<getGrossSales()<<endl
    <<getCommissionRate()<<endl;
}


