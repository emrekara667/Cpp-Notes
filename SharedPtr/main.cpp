#include <iostream>
#include <memory>

using namespace std;

class Renctangle{

    int lenght;
    int breadth;
public:
    Renctangle(int l ,int b){
        lenght = l;
        breadth = b;
    }

    int area(){
        return lenght * breadth;
    }
};

int main()
{

    shared_ptr<Renctangle> P1(new Renctangle(10, 5));

    cout<< P1->area()<<endl;

    shared_ptr<Renctangle> P2(P1);

    cout<<P2->area()<<endl;

    cout<<P1.use_count()<<endl;
    cout<<P2.use_count()<<endl;

    return 0;
}
