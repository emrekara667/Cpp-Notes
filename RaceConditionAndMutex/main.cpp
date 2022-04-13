#include <iostream>
#include<thread>
#include <mutex>


using namespace std;

std::mutex mu;
void print(string msg,int  i){

    std: :lock_guard<std::mutex> guard(mu);

    // mu.lock();
    cout<<msg<<" "<<i<<endl;
   // mu.unlock();
}

void function_1(){
    for(int i = 0; i > -100; i--)
       print(string("From t1"),i);
}

int main()
{
    std::thread t1(function_1);

    for(int i = 0; i<100; i++)
       print(string("From main"), i);


    t1.join();
    return 0;
}
