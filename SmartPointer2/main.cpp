#include <iostream>

using namespace std;

class Rectangle {
private:
    int length;
    int breadth;
};

class SmartPointer{
    Rectangle* ptr;
public:
    explicit SmartPointer(Rectangle* p = NULL)
    {
        ptr = p;
    }

    ~SmartPointer(){
        delete(ptr);
    }

    Rectangle& operator*()
    {return *ptr;}
};



void fun(){

   // SmartPointer ptr(new int());
 Rectangle* ptr = new Rectangle();
   // *ptr = 20;
    //cout<< *ptr<<endl;
   //SmartPointer ptr(new Rectangle());
}

int main()
{
    while(1){
        fun();
    }
    return 0;
}
