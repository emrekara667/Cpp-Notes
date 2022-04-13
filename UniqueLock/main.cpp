#include <iostream>
#include<thread>
#include <mutex>
#include <fstream>
using namespace std;

class LogFile{


    std::mutex _mu;
    ofstream _f;
public:
    LogFile(){
        _f.open("log.txt");
    }

    void shared_print(string id, int value){
        //std::lock_guard<mutex> locker(_mu);
        std::unique_lock<mutex> locker(_mu, std::defer_lock);

        locker.lock();
        cout<<id<< " : " << value <<endl;
        locker.unlock();


        locker.lock();
        cout<<id<< " : " << value <<endl;
        locker.unlock();

        locker.lock();

        std::unique_lock<mutex> locker2 = std::move(locker);







    }

};

void function_t1(LogFile &log){
    for(int i = 0; i < 100; i++ )
        log.shared_print(string("From t1") ,i);
}


int main()
{

    LogFile log;
    std::thread t1(function_t1, std::ref(log));

    for(int i = 0; i < 100; i++)
        log.shared_print("From main", i);



    t1.join();


    return 0;
}
