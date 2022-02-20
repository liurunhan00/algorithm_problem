#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 排序数组中两个数字之和
vector<int> twoSum(vector<int> &numbers, int target) {
    int l = 0, r  = numbers.size() - 1;
    while (l < r) {
        if (target == numbers[l] + numbers[r]) {
            return {l, r};
        } else if (target < numbers[l] + numbers[r]) {
            l++;
        } else {
            r--;
        }
    }
    return {};
}

// 数组中和为0的三个数
vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size();

    for(int i = n - 3; i >= 0; --i) {
        for (int j = i+1; j <= n - 2; ++j) {
    
        }
    }
    return {};
}

// 狒狒吃香蕉
// 速度[1, max] 之间 依次二分判断能不能吃完
int countTime(vector<int>& nums, int h) {
    int t = 0;
    for (auto &n: nums) {
        t += n / h;
        t += ((n % h) > 0);
    }
    return t;
}
int minEatingSpeed(vector<int>& nums, int h) {
    int left = 0, right = *max_element(nums.begin(), nums.end());
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (countTime(nums, mid) <= h) {
            if (mid == 1 || countTime(nums, mid - 1) > h) {
                return mid;
            }
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    return -1;
}

// 求平方根
int mySqrt(int x) {
    int left = 0, right = x;
    int res = -1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if ((long) mid * mid <= x) {
            left = mid + 1;
            res = mid;
        } else {
            right = mid - 1;
        }
    }
    return res;
}
