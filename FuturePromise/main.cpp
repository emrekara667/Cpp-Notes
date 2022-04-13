#include <iostream>
#include <future>
#include <mutex>
#include <condition_variable>


using namespace std;


std::mutex mu;
std::condition_variable cond;

void factorial(int N, int& x){
    int res = 1;
    for(int i = N; i > 1; i--)
        res *= i;

    cout<< "Result is:" <<res <<endl;
    x = res;
}


int main()
{
    cout << "Hello World!" << endl;

    int x;
    std::thread t1(factorial, std::ref(x));


    t1.join();
    return 0;
}
