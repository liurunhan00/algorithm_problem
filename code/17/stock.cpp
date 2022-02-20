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
   return 0; 
}





// 最少的硬币数目
// [1, 2, 5] amount = 11
int coinChange(vector<int> &coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;
    for (auto &coin: coins) {
        for (int i = 1; i < amount + 1; ++i) {
            dp[i] = min(dp[i], 1 + dp[i - coin]);
        }
    }
    return dp[amount] == INT_MAX ? -1: dp[amount];
}

// 粉刷房子
// dp[n][3] 左右两端与中间颜色不同 求最小的cost
int minCost(vector<vector<int>>& costs) {
    vector<vector<int>> dp(costs.size(), vector<int>(3, 0));
    // dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
    dp[0][0] = costs[0][0], dp[0][1] = costs[0][1], dp[0][2] = costs[0][2];
    for (int i = 1; i < costs.size(); ++i) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + costs[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + costs[i][1];
        dp[i][2] = min(dp[i-1][1], dp[i-1][0]) + costs[i][2];
    }
    int ans = min(dp[costs.size()-1][0], dp[costs.size()-1][1]);
    ans = min(ans, dp[costs.size()-1][2]);
    return ans;
}

// 翻转字符串求左0右1的翻转最小次数
int minFlipsMonoIncr(string s) {
    int n = s.size();
    vector<int> dp1(n+1, 0);
    vector<int> dp2(n+1, 0);
    for (int i = 1; i < n + 1; ++i) {
        dp1[i] = dp1[i-1] + s[i-1] == '0'? 1: 0;
        dp2[i] = dp2[i-1] + s[i-1] == '1'? 1: 0;
    }
    // 左0右1
    int res = INT_MAX;
    for (int i = 0; i < n + 1; ++i) 
        // 统计左1右0就是翻转数
        res = min(dp2[i] + dp1[n] - dp1[i], res);
    return res;
}


// 打家劫舍1
// 唯一制约因素就是相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// ----------
int rob(vector<int>& nums) {
    vector<int> dp(nums.size()+1,0);
    dp[0] = nums[0];
    dp[1] = (nums[1],nums[0]);
    for (int i = 2; i < nums.size(); ++i)
        dp[i] = dp[i-2] + nums[i], dp[i-1];
    dp[nums.size()] = max(dp[nums.size()-1], dp[nums.size()-2]);
    return dp[nums.size()];
}
