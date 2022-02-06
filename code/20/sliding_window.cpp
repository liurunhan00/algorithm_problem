#include <bits/stdc++.h>
#include "sliding_window.h"
using namespace std;
// 滑动窗口最大值
vector<int> maxSlidWindow(vector<int>& nums, int k) {
    MyQueue my_q;
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        my_q.push(nums[i]);
    }
    res.push_back(std::move(my_q.front()));
    for (int i = k; i < nums.size(); ++i) {
        my_q.pop(nums[i - k]);
        my_q.push(nums[i]);
        res.push_back(std::move(my_q.front()));
    }
    return res;
}
                  
int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto res = maxSlidWindow(nums, 3);    
    for (auto&r: res) {
        cout << r << endl;
    }
}
