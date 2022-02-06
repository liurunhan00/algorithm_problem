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
    


