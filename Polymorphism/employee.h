#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>



class Employee
{
public:
    Employee(const std::string &,const std::string &, const std::string & );

    virtual ~Employee(){}


    std::string getFirstName() const;
    void setFirstName(const std::string &newFirstName);

     std::string getLastName() const;
    void setLastName(const std::string &newLastName);

    std::string getSocialSecurityNumber() const;
    void setSocialSecurityNumber(const std::string &newSocialSecurityNumber);

    virtual double earnings()const = 0; //pure virtual
    virtual void print() const; //virtual

private:
     std::string firstName;
     std::string lastName;
     std::string socialSecurityNumber;
};

#endif // EMPLOYEE_H
