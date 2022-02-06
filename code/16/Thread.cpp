#include <chrono>
#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
std::atomic<int> at_int;
int unat_int;
std::mutex mtx;
std::condition_variable cr;
char ch = 0;
void print(char ch_, int t){
    int cicle = 10;
    char ch__ = ch_ - 'A';
    for(int i = 0; i < cicle ; ++i) {
        std::unique_lock<std::mutex> u_lock(mtx);
        cr.wait(u_lock, [&](){return ch__ == ch;});
        std::cout << (char)('A' + ch__) << "原子操作:" << at_int.fetch_add(1) <<  std::endl;
        // std::this_thread::sleep_for(std::chrono::microseconds(10));
        // std::cout << (char)('A' + ch__) << "非原子操作:" << unat_int++ <<  std::endl;
        // std::this_thread::sleep_for(std::chrono::microseconds(10));
        ch = (ch + 1) % 3;
        cr.notify_all();
    }
}
int main() {
    std::vector<std::thread> v;
    v.push_back(std::thread(print,'A', 1));
    v.push_back(std::thread(print,'B', 2));
    v.push_back(std::thread(print,'C', 3));
    v.push_back(std::thread([&](){
        while(1)
        std::cout << unat_int++ << " " << "thread4" << std::endl;
    }));
    v.push_back(std::thread([&](){
        while(1)
        std::cout << unat_int++ << " " << "thread5" << std::endl;
    }));
    for(auto &t: v){
        t.join();
    }
    std::cout << at_int.load() << std::endl;
}
