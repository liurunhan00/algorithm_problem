#include <functional>
#include <queue>
#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
// 最小的k对数
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto com = [&](vector<int>& A, vector<int>&B){
       return A[0] + A[1] < B[0] + B[1];
    }; 
    priority_queue<vector<int>, vector<vector<int>>, decltype(com)> pq(com);
    int n1 = nums1.size(), n2 = nums2.size(), t1 = 0, t2 = 0;
    for(int j = 0; j < n1; ++j) {
        for(int i = 0; i < n2; ++i) {
            if(pq.size() < k) {
                pq.push({nums1[j], nums2[i]});
            } else {
                if (nums1[j] + nums2[i] < pq.top()[0]+ pq.top()[1]) {
                    pq.pop();
                    pq.push({nums1[j], nums2[i]});
                } else {
                    break;
                }
            }
        }
    }
    vector<vector<int>> res;
    while(!pq.empty()) {
            res.emplace_back(pq.top());
            pq.pop();
    } 
    return res;
}

// 最长公共子序列
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size() + 1, vector<int>(text2.size() + 1, 0));
    int res = 0;
    for (int i = 1; i < text1.size() + 1; ++i) {
        for(int j = 1; j < text2.size() + 1; ++j) {
            if (text1[i-1] == text2[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else { 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
            res = max(res, dp[i][j]);
        }
    }
    return res;
}

// 最长重复数组
int findLength(vector<int>& nums1, vector<int>& nums2) {
    vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1, 0));
    int res = 0;
    for (int i = 1; i < nums1.size() + 1; ++i) {
        for (int j = 1; j < nums2.size() + 1; ++j) {
            if (nums1[i-1] == nums2[j-1]) {
                dp[i][j] = dp[i-1][j-1];
                res = max(res, dp[i][j]);
            }
        }
    }
    return res;
}    

// 接雨水
// 
int trap(vector<int>& height) {
    int n = height.size();
    vector<int> left(n), right(n);
    // left 表示i左边的最大高度
    // right 表示i右边的最大高度
    // 当前i与左右两边最高柱子的较小那个的差值
    left[0] = height[0];
    for (int i = 1; i < n; ++i) {
        left[i] = max(left[i-1], height[i]);
    }
    right[n-1] = height[n-1];
    for(int i = n-2; i >= 0; --i) {
        right[i] = max(right[i+1], height[i]);
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += min(left[i], right[i]) - height[i];
    }
    return res;
}

        
int main() {
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    int k = 3;
    vector<vector<int>> p = kSmallestPairs(nums1, nums2, k);
    for (auto &s: p) {
        cout << s[0] << s[1] << endl;
    }
}
