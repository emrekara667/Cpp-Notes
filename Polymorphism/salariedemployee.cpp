#include "salariedemployee.h"
#include <stdexcept>
#include <iostream>
using namespace std;

SalariedEmployee::SalariedEmployee(const string &first,const string &last,const string &ssn, double salary)
    :Employee(first, last, ssn)
{
    setWeeklySalary(salary);

}

double SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary;
}

void SalariedEmployee::setWeeklySalary(double newWeeklySalary)
{
   if(newWeeklySalary >= 0.0)
        weeklySalary = newWeeklySalary;
   else
       throw invalid_argument("Salary must be > 0");
}


double SalariedEmployee::earnings()const
{
    return getWeeklySalary();
}

void SalariedEmployee::print() const
{
    Employee::print();
    cout<<getWeeklySalary()<<endl;
}





