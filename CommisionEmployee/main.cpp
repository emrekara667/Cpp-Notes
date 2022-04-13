#include <iostream>
#include<iomanip>

using namespace std;

#include "commissionemployee.h"
#include "basepluscommissionemployee.h"
using namespace std;

int main()
{

    CommissionEmployee commissionEmployee("emre","kara","11-22",10000,.06);

    CommissionEmployee *commisionEmployeePtr = nullptr;

    BasePlusCommissionEmployee basePlusCommisionEmployee("hakan","onur","22-33",10000,.06,5000);

    BasePlusCommissionEmployee *basePlusCommissionEmployeePtr = nullptr;

    cout<<fixed<<setprecision(2);

    commisionEmployeePtr = &basePlusCommisionEmployee;

    commisionEmployeePtr->print();
    cout<<commisionEmployeePtr->earnings();





    return 0;
}
