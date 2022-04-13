#include <iostream>
#include <memory>
using namespace std;

int main()
{

    std::shared_ptr<int> shared1 = std::make_shared<int>();
    std::shared_ptr<int> shared2 = std::make_shared<int>();

    *shared1 = 1453;
    shared2 = shared1;

    cout<< "shared count1 : " << shared1.use_count()<<endl;

    shared2.reset();

    cout<< "shared count1 : " << shared1.use_count()<<endl;


    return 0;
}
