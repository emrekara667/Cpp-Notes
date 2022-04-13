#include "employee.h"
#include <iostream>

using namespace std;


Employee::Employee(const string &first, const string &last, const string &ssn)
    :firstName(first),lastName(last),socialSecurityNumber(ssn)
{

}

 std::string Employee::getFirstName() const
{
    return firstName;
}

void Employee::setFirstName(const std::string &newFirstName)
{
    firstName = newFirstName;
}

 std::string Employee::getLastName() const
{
    return lastName;
}

void Employee::setLastName(const std::string &newLastName)
{
    lastName = newLastName;
}

 std::string Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber;
}

void Employee::setSocialSecurityNumber(const std::string &newSocialSecurityNumber)
{
    socialSecurityNumber = newSocialSecurityNumber;
}


void Employee::print() const{
    cout<<getFirstName()<<endl
       <<getLastName()<<endl
      <<getSocialSecurityNumber()<<endl;
}






