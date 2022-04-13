#include <iostream>
#include <iomanip>
#include <vector>

#include "commisionemployee.h"
#include "employee.h"
#include "salariedemployee.h"
#include "basepluscommissionemployee.h"
using namespace std;


void virtualViaPointer(const Employee * const);
void virtualViaReference(const Employee &);

int main()
{
    /*
    cout << "Hello World!" << endl;
   SalariedEmployee salariedEmployee("emre","kara","111",4000);
   CommisionEmployee commisionEmployee("hakan", "onur","222", 1000.0, 0.1);
   BasePlusCommissionEmployee basePlusCommissionEmployee("sema", "toltar", "333",1000.0, 0.1, 4000);

   salariedEmployee.print();
   cout<<"Salaried employee earnings : "<<salariedEmployee.earnings()<<endl;
   commisionEmployee.print();
   cout<<"commision employee earnings : "<<commisionEmployee.earnings()<<endl;
   basePlusCommissionEmployee.print();
   cout<<"Base plus commsion employee earnings : "<<basePlusCommissionEmployee.earnings()<<endl; //static binding

   vector <Employee *> employees(3); //dynamic binding

   employees[0] = &salariedEmployee;
   employees[1] = &commisionEmployee;
   employees[2] = &basePlusCommissionEmployee;

   cout<<"-------------------------------------------------"<<endl;
   for(const Employee *employeePtr : employees)
   virtualViaPointer(employeePtr);

   cout<<"-------------------------------------------------"<<endl;
   for(const Employee *employeePtr : employees)
       virtualViaReference(*employeePtr); //note dereferencing

*/

    cout<<fixed<<setprecision(2);


    vector<Employee *> employees(3);

    employees[0] = new  SalariedEmployee("emre","kara","111",4000);
    employees[1] = new  CommisionEmployee("hakan", "onur","222", 1000.0, 0.1);
    employees[2] = new  BasePlusCommissionEmployee("sema", "toltar", "333",1000.0, 0.1, 4000);

    for(Employee *employeePtr: employees)
    {
       employeePtr->print();
       cout<<endl;

       BasePlusCommissionEmployee *derivedPtr = dynamic_cast<BasePlusCommissionEmployee *>(employeePtr);

       if(derivedPtr != nullptr)
       {
           double oldBaseSalary = derivedPtr->getBaseSalary();
           cout<<"old basse salary" <<oldBaseSalary<<endl;
           derivedPtr->setBaseSalary(1.10 * oldBaseSalary);
           cout<<"new Basse salary " << derivedPtr->getBaseSalary();
       }
       cout<<"earned"<<employeePtr->earnings()<<endl;
    }

    for(const Employee *employeePtr : employees){
        cout<<"deleting object of" <<typeid(*employeePtr).name()<<endl;

        delete employeePtr;
    }

    return 0;
}


void virtualViaPointer(const Employee * const baseClassPtr){
    baseClassPtr->print();
    cout<<"earnings "<< baseClassPtr->earnings()<<endl;
}

void virtualViaReference(const Employee &baseClassReference){
    baseClassReference.print();
    cout<<"earnings"<<baseClassReference.earnings()<<endl;
}
