#include <iostream>
#include <memory>

using namespace std;

char *y;
std::shared_ptr<string> sy = std::make_shared<string>();

void useSmartPointer()
{
    std::shared_ptr<string> sx = std::make_shared<string>();
    *sx = "smart hello";
    cout<< *sx << endl;
    sy = sx;
}

void useRawPointer(){
    char *x = new char[5];
    x = "hello";
    cout<<x<<endl;
    y = x;
}


int main()
{
    useRawPointer();
    cout<<"y : "<< y << endl;

    useSmartPointer();
    cout<< " sy" << *sy << endl;

    return 0;
}
