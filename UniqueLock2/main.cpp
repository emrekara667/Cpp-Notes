#include <iostream>
#include<thread>
#include <mutex>
#include <fstream>
using namespace std;

class LogFile{


    std::mutex _mu;
    std::once_flag _flag;
    ofstream _f;
public:
    LogFile(){

    }

    void shared_print(string id, int value){


       // {
        //   std::unique_lock<mutex> locker2(_mu_open);
         //  if(!_f.is_open()){
          //      _f.open("log.txt");
        //}
        //}

        std::call_once(_flag, [&](){ _f.open("log.txt");}); //File will be opened only once by one

        std::unique_lock<mutex> locker(_mu, std::defer_lock);
        cout<<id<< " : " << value <<endl;







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
