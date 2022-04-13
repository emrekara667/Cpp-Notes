#include <iostream>
#include<thread>
using namespace std;

void function_1(){
    cout<<"Beatuy is only skin-deep"<<endl;
}


class Fctor{
public:
    void operator()(){
        for(int i = 0; i > -100; i--){
            cout<<"from t1 : "<<i<<endl;
        }
    }
};

int main()
{
    cout << "main thread start" << endl;
    Fctor fct;

    thread t1(fct);
    //Using RAII
    //Wrapper w(t1



    try {
        for(int i = 0; i < 100; i++)
            cout<<"from main: "<< i << endl;
    }  catch (...) {
        t1.join();
        throw;
    }

    t1.join();



    cout << "main thread end" << endl;
    return 0;
}
