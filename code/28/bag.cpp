#include <bits/stdc++.h>
using namespace std;
// 背包问题
// f(k, w) = f(k-1, w) 装不下
// f(k, w) = max (f(k-1, w), f(k-1, w-w(k)) + w(k-1))
// 分割等和子集
// 给定一个非空的正整数数组 nums ，请判断能否将这些数字分成元素和相等的两部分。
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (auto &n: nums) sum += n;
    if ((sum & 1) == 1) return false;
    int target = sum / 2;
    // 转化成0-1背包
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(target+1, 0));
    for (int i = 1; i <= n; ++i) {
        // i,j 为0时一定为0
        // dp[i][j] ==> nums选择i个数相加得到不超过j的最大值
        for (int j = 1; j <= target; ++j) {
            // 不选dangqianshuzi
            dp[i][j] = dp[i-1][j];
            if (j >= nums[i]) {
                // j >= nums[i]表示可以添加
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-nums[i]] + nums[i-1]);
            }
        }
    }
    return dp[n][target] == target;
}
