#include <iostream>
#include<thread>
#include <mutex>
#include <fstream>
using namespace std;

class LogFile{
    std::mutex _mu;
    std::mutex _mu2;
    ofstream _f;
public:
    LogFile(){
        _f.open("log.txt");
    }
    void shared_print(string id, int value){
        std::lock_guard<mutex> locker(_mu);
        std::lock_guard<mutex> locker2(_mu2);
       cout<<"From" << id <<  " : " << value<< endl;
    }

    void shared_print2(string id, int value){
        {
        std::lock_guard<mutex> locker2(_mu2);
        }
        {
        std::lock_guard<mutex> locker(_mu);
        }
       cout<<"From" << id <<  " : " << value<< endl;
    }
};


void function_1(LogFile& log){
    for(int i = 0; i >-1000; i--)
        log.shared_print(string("From t1"), i);
}

int main()
{

    LogFile log;
    std::thread t1(function_1, std::ref(log));

    for(int i = 0; i < 1000; i++)
        log.shared_print2(string("From main : "), i);

    t1.join();


    return 0;
}
