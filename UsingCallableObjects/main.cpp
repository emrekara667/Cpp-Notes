#include <iostream>
#include <future>
#include <mutex>
#include <condition_variable>
#include <thread>
using namespace std;

class A{
    void f(int x, char c){}
    long g(double x){return 0;}
    int operator()(int N){return 0;}
};

int main()
{
    cout << "Hello World!" << endl;


    A a;
    std::thread t1(a, 6);
    std::async(std::launch::async, a, 6);


    return 0;
}
