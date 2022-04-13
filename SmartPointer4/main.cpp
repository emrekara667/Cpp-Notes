#include <iostream>
#include <memory>

using namespace std;


char *y;
std::unique_ptr<string> sy = std::make_unique<string>();

void useRawPointer(){
    char *x = new char[5];
    x = "hello";
    cout<<x<<endl;
    y = x;
}

void useSmartPointer(){
    std::unique_ptr<string> sx = std::make_unique<string>();
    *sx = "smart hello";
    cout<<*sx<<endl;
    sy.reset(sx.get());
}

int main()
{

    useRawPointer();
    cout<<"y: " <<y <<endl;
    useSmartPointer();
    cout<<"sy : "<< *sy <<endl;
    return 0;
}
