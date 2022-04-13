#include <iostream>
#include<thread>
using namespace std;

void function_1(){
    cout<<"Beatuy is only skin-deep"<<endl;
}


class Fctor{
public:
    void operator()(string& msg){
        cout<<"t1 says : " <<msg<<endl;
        msg = "Trust is the mother of deceit";
    }
};

int main()
{
   cout<< std::thread::hardware_concurrency()<<endl;
    cout << "main thread start" << endl;

    cout<<"id : "<<std::this_thread::get_id()<<endl;
    string s = "Where there is  no trust, there is no love";
    thread t1((Fctor()),std::ref(s)); // adding paranthes it explicitly that this is constructing a functor
    //and pass is as parameter to constructur of t1

     cout<<"id : "<<t1.get_id()<<endl;

    std::thread t2 = std::move(t1);

    t2.join();

    cout<<"from main : " << s<<endl;
    cout << "main thread end" << endl;
    return 0;
}
