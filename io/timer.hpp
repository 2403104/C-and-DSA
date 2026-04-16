#pragma once
#include<chrono>
#include<fstream>
using namespace std;

class Timer{
    chrono::high_resolution_clock::time_point start_time;
    public:
    Timer(){
        start_time=chrono::high_resolution_clock::now();
    }
    ~Timer(){
        auto end_time=chrono::high_resolution_clock::now();
        chrono::duration<double,milli>duration=end_time-start_time;
        ofstream timefile("time.txt");
        timefile<<duration.count()<<" ms"<<endl;
        timefile.close();
    }
};