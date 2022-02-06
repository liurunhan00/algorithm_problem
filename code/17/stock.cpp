#include <bits/stdc++.h>
#include <vector>
using namespace std;

// 买卖1
int maxProfit1(vector<int> &nums) {
    int maxP = 0;
    int minP = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        maxP = max(nums[i] - minP, maxP);
        minP = min(nums[i], minP);
    }
    return maxP;
}

// 买卖2
// 不含冷冻期随便卖卖 当天卖出后不能再买
int maxProfit2(vector<int> &nums) {
    int maxP = 0;
    int minP = nums[0];
    for(int i = 0; i < nums.size(); ++i) { 
        if(nums[i] > minP) {
            maxP += nums[i] - minP;
        } 
        minP = nums[i];
    }
    return maxP;
}

// 买卖3
// 最多可两次买卖求最大
int maxProfit3(vector<int> &nums) {
    
}






