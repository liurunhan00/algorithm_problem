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
// 寻找峰值
// nums均不相等 峰值一定存在
int findPeakElement(vector<int> &nums) {
    int left = 0, right = nums.size() -1;
    while (left < right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] <= nums[mid+1]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}
// 旋转数组的最小数字
int minArray(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    while (left < right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            right--;
        }
    }
    return nums[left];
}
                
// 搜索旋转排序数组II 有重复
bool search_II(vector<int> &nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right) {
        int mid = left + ((right - left) >> 1);
        if (nums[mid] == target) return true;
        if (nums[mid] == nums[left]) {
            left++;
            continue;
        }
        if (nums[mid] > nums[left]) // 前半部分有序
        {
            if (nums[mid] > target && nums[left] <= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (nums[mid] < target && nums[right] >= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return false;
}
            
