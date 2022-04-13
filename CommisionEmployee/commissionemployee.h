#ifndef COMMISSIONEMPLOYEE_H
#define COMMISSIONEMPLOYEE_H

#include <string>


class CommissionEmployee
{
public:
    CommissionEmployee(const std::string &, const std::string & , const std::string &, double = 0.0, double = 0.0);

    std::string getFirstName() const;
    void setFirstName(const std::string &newFirstName);

    std::string getLastName() const;
    void setLastName(const std::string &newLastName);

    std::string getSocialSecurityNumber() const;
    void setSocialSecurityNumber(const std::string &newSocialSecurityNumber);

    double getGrossSales() const;
    void setGrossSales(double newGrossSales);

    double getCommissionRate() const;
    void setCommissionRate(double newCommissionRate);

    virtual double earnings() const;

    virtual void print()const;

private:
    std::string firstName;
    std::string lastName;
    std::string socialSecurityNumber;
    double grossSales;
    double commissionRate;
};

#endif // COMMISSIONEMPLOYEE_H
