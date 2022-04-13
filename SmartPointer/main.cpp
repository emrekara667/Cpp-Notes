#include <iostream>

using namespace std;

class Renctangle{
private:
    int lengtyh;
    int hheight;
};


void fun(){
    Renctangle* p = new Renctangle(); //Memory leak


int main()
{
    while(1){
        fun();
    }
    cout << "Hello World!" << endl;
    return 0;
}
