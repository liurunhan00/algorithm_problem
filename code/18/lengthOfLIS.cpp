#include <bits/stdc++.h>
#include <stdexcept>
#include <vector>
using namespace std;

// 最长递增子序列
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int maxl = 1;
    vector<int> dp(n, 1);
    for(int i = 0; i < nums.size(); ++i) {
        for(int j = i + 1; j < nums.size(); ++j) {
            if(nums[j] > nums[i]) dp[j] = max(dp[j], dp[i] + 1);
            maxl = max(maxl, dp[j]);
        }
    }
    return maxl;
}
// 二分 + dp
// dp[i]: 所有长度为i + 1的递增子序列中最小的那个序列尾数
// num > dp[maxL] num放到dp数组尾部 maxL++ 
// dp[i-1] < num < dp[i] 更新dp[i]
int lengthOfLIS_binary(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 0);
    int maxL = 0;
    for(auto &n: nums) {
        int lo = 0, hi = maxL;
        while(lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if(dp[mid] < n) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        dp[lo] = n;
        // num > dp[hi] 更新
        if(lo == maxL)
            maxL++;
    }
    return maxL;
}
// 最长连续数组
int longestConsecutive(vector<int> &nums) {
    unordered_set<int> u_set;
    for (auto& n: nums) u_set.insert(n);
    int longest = 0;
    for (auto& n: nums) {
        if (u_set.erase(n)) {
            // 左边删除
            int curlong = 1;
            int curnum = n;
            while (u_set.erase(curnum-1)) {
                curnum--;
            }
            curlong += (n - curnum);
            curnum = n;
            while (u_set.erase(curnum+1)) {
                curnum++;
            }
            curlong += (curnum - n);
            longest = max(longest, curlong);
        }
    }
    return longest;
}

// 字符串交织
// s1, s2 能否交织形成s3
bool isInterleave(string s1, string s2, string s3) {
    int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
    if (n3 != n1 + n2) return false;
    vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, 0));
    dp[0][0] = true;
    for (int i = 1; i <= n1; ++i) {
       if (s1[i-1] == s3[i-1]) dp[i][0] = true;
    } 
    for (int i = 1; i <= n2; ++i) {
       if (s2[i-1] == s3[i-1]) dp[0][i] = true;
    } 
    for (int i = 1; i <= n1; ++i) {
        for (int j = 1; j <= n2; ++j) {
            if (s1[i-1] == s3[i+j-1]) dp[i][j] = dp[i-1][j];
            if (s2[j-1] == s3[i+j-1]) dp[i][j] = dp[i][j-1]||dp[i][j];
        }
    }
    return dp[n1][n2];
}
    
    
// 最大正方形
int maximalSquare(vector<vector<char>>& matrix) {
    // dp[i][j]表示以第i行第j列为右下角所能构成正方形的最大正方形边长
    // dp[i][j] = 1 + min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])
    int m = matrix.size();
    int n = matrix[0].size();
    int maxline = 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == '1') {
                if (i == 0 || j == 0) {
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
                }
                maxline = max(maxline, dp[i][j]);
            }
        }
    }
    return maxline;
}


int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << lengthOfLIS(nums);
    cout << '\n';
    cout << lengthOfLIS_binary(nums);
    cout << '\n' << longestConsecutive(nums) << endl;
    return 0;
}
