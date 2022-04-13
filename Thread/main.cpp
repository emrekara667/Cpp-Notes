#include <iostream>
#include <thread>

using namespace std;

void function_1(){
    cout<<"funnction_1 thread start"<<endl;
}


int main()
{
    cout << "main thread start" << endl;


    thread t1(function_1);





    t1.join();





    cout << "main thread end" << endl;
    return 0;
}
