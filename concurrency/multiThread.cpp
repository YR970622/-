#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
using namespace std;

mutex mtx;
condition_variable cv;
int ready=0;

void func(int i,char c){
    unique_lock<mutex> locker(mtx);
    int cnt=0;
    while(cnt<10){
        while(ready!=i){
            cv.wait(locker);
        }

        cout<<c<< "thread_id:"<< this_thread::get_id()<<endl;
        cnt++;
        ready=(ready+1)%3;
        cv.notify_all();
    }
}

int main(){
    vector<thread> threads;
    for(int i=0;i<3;++i){
        threads.emplace(func,i,'A'+i);
    }

    for(int i=0;i<3;++i){
        threads[i].join();
    }
}