#include <iostream>
#include <future>
#include <mutex>
#include <condition_variable>
//#include <promise>


using namespace std;



int factorial(std::future<int>& f){
    int res = 1;
    int N = f.get();
    for(int i = N; i > 1; i--)
        res *= i;

    cout<< "Result is:" <<res <<endl;
    return res;
}


int main()
{
    cout << "Hello World!" << endl;

    int x;

    std::promise<int> p;
    std::future<int> f = p.get_future();
    std::future<int> fu = std::async( factorial, std::ref(f));
    //std::future<int> fu = std::async(std::launch::async | std::launch::deferred, factorial, 4);

    p.set_value(3);

    x = fu.get();
    cout<<x<<endl;

   // fu.get(); //second calling cause crash
    return 0;
}
