#include <iostream>
#include <memory>

using namespace std;

class Renctangle{
    int length;
    int breadth;

public:
    Renctangle(int l, int b){
        length = l;
        breadth = b;
    }

    int area(){
        return length * breadth;
    }
};

int main()
{

    unique_ptr<Renctangle> P1(new Renctangle(10,5));

    cout<<P1->area()<<endl;

     unique_ptr<Renctangle> P2;
    //unique_ptr<Renctangle> P2(P1);

    P2 = move(P1);

    cout<<P2->area()<<endl;


    return 0;
}
