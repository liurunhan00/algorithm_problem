#include <bits/stdc++.h>
using namespace std;
// 摩尔投票
// 半数一定存在
int majorityElement(vector<int>& nums) {
    int count = 1;
    int res = nums[0];
    for (int i = 1; i < nums.size() - 1; ++i) {
        if (nums[i] == res) {
            count++; 
        } else {
            count--;
            if (0 == count) {
                res = nums[i+1];
            }
        }
    }
    return res;
}

// 求大于1/3元素数的res
vector<int> majorityElement_one_third(vector<int>& nums) {
    int cx = 0, cy = 0, x = INT_MAX, y = INT_MAX, countx = 0, county = 0;
    for (auto &n: nums) {
        if ((cx == 0 || n == x) && n != y) {
            ++cx;
            x = n;
        } else if (cy == 0 || n == y) {
            ++cy;
            y = n;
        } else {
            --cx;
            --cy;
        }
    }
    for (auto &n:nums) {
        if (x == n) {
            countx++;
        } else if (y == n) {
            county++;
        }
    }
    vector<int> res;
    if (countx > nums.size() / 3) res.emplace_back(x);
    if (county > nums.size() / 3 && x != y) res.emplace_back(y);
    return res;
}

