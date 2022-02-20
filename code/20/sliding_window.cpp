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


// 长度最小的子数组
// sum >= target 
int minSubArrayLen(int target, vector<int>& nums) {
    int minL = INT_MAX;
    int curSum = 0;
    int slow = 0;
    for (int fast = 0; fast < nums.size(); ++fast) {
        curSum += nums[fast];
        while (fast > slow && curSum >= target) {
            minL = min(minL, fast - slow + 1);
            curSum -= nums[slow];
            slow++;
        }
    }
    return minL == INT_MAX ? -1: minL;
}

// 值和下标之差都在给定的范围内
/* 给你一个整数数组 nums 和两个整数 k 和 t 。
 * 请你判断是否存在 两个不同下标 i 和 j，
 * 使得 abs(nums[i] - nums[j]) <= t 
 * ，同时又满足 abs(i - j) <= k 。
*/

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int left = 0, right = k - 1;
    
int main() {
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    auto res = maxSlidWindow(nums, 3);    
    for (auto&r: res) {
        cout << r << endl;
    }
}
