#include <bits/stdc++.h>
#include <string>
using namespace std;

// 数组中重复的数字
// 找出任意的一个重复数字
// num==>[0---100000]

// 在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内
// 交换 鸽巢原理
int findRepeatNumber(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] != i) {// 往复
            if (nums[nums[i]] != nums[i])
                swap(nums[i], nums[nums[i]]);
            else {
                return nums[i];
            }
        }
    }
    return -1;
}

/* 把数组排成最小的数 返回string */
string minNumber(vector<int>& nums) {
    vector<string> to_string_nums(nums.size());
    for (auto &n: nums) {
        to_string_nums.push_back(to_string(n));
    }
    sort(to_string_nums.begin(), to_string_nums.end(),
         [&](const auto& s1, const auto &s2) {
             return s1+s2 < s2+s1;
    });
    string res = "";
    for (auto &s: to_string_nums) {
        res += s;
    }
    return res;
}

int main() {
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    vector<int> nums2 = {3,30,34,5,9};
    cout << findRepeatNumber(nums);
    cout << endl;
    cout << minNumber(nums2);
}
