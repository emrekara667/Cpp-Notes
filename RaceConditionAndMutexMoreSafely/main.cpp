#include <iostream>
#include<thread>
#include <mutex>
#include <fstream>
using namespace std;

class LogFile{
    std::mutex m_mutex;
    ofstream f;
public:
    LogFile(){
        f.open("log.txt");
    } //need destructor to close file
    void shared_print(string id, int value){
        std::lock_guard<mutex> locker(m_mutex);
        f<<"From" << id <<  " : " << value<< endl;
    }
    //Never return f to outside world
     //ofstream& getStream(){return f;}

    //Never pass f as an argument to user provided function

};


void function_1(LogFile& log){
    for(int i = 0; i >-100; i--)
        log.shared_print(string("From t1"), i);
}

int main()
{

    LogFile log;
std::thread t1(function_1, std::ref(log));

for(int i = 0; i < 100; i++)
    log.shared_print(string("From main : "), i);

t1.join();



    return 0;
}
