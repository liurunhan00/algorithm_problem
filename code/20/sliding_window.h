#pragma once
#include <bits/stdc++.h>
struct MyQueue {
    std::deque<int> myqueue ;
    void push(int val) {
       while (!myqueue.empty() && val > myqueue.back()) {
           myqueue.pop_back();
       } 
       myqueue.push_back(std::move(val));
    }
    void pop(int val) {
        if (!myqueue.empty() && val == myqueue.front()) {
            myqueue.pop_front();
        } 
    }
    int front() {
        return myqueue.front();
    }
};
