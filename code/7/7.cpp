#include <cstdint>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
vector<int> countBits(int n) {
    // dp[n] = dp[n>>1]
    std::vector<int> vec(n, 0);
    vec[0] = 0;
    for (int i = 1; i < n; ++i) {
        vec[i] = vec[i >> 1] + (i & 1);
        // & | ^ 等符号需要注意优先级
        cout << vec[i] << " " ;
    } 
    return vec;
}

// 二进制加法
string addBinary(string a, string b) {
    int n1 = a.size(), n2 = b.size(), carry = 0, i = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string res = "";
    while ( i < max(n1, n2)) {
        int s1 = i >= n1 ? 0 : a[i] - '0';
        int s2 = i >= n2 ? 0 : b[i] - '0';
        int k = (s1 + s2 + carry) % 2;
        carry = (s1 + s2 + carry) /2 ;
        res += to_string(k);
        i++;
    }
    if (carry) res += to_string(carry);
    reverse(res.begin(), res.end());
    return res;
}
    
// 整数除法
int divide(int a, int b) {
    return -1;
}

// 只出现一次的数字
int singleNumber(vector<int> &nums) {
    int res = 0;
    for (int i = 0; i < 32; ++i) {
        int count = 0;
        for (int j = 0; j < nums.size(); ++j) {
            count += (nums[j] >> i) & 1;
        }
        if (count % 3 == 1) 
            res += 1;
    }
    return res;
}

// 单词长度的最大乘积
int maxProduct(vector<string> &words) {
    int n = words.size();
    vector<int> st(n, 0);
    for (int i = 0; i < n; ++i) {
        for (auto &w: words[i]) {
            st[i] |= 1 << (w - '0');
        }
    }
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((st[i] & st[j]) == 0 ) {
                res = max( res, static_cast<int>(words[i].size() * words[j].size()));
            }
        }
    }
    return res;
}

// 颜色分类
// 0, 1, 2排序
void sortColors(vector<int>& nums) {
    int lo = 0, hi = nums.size(), zero = 0;
    // hi ==> 2 zero ==> 0 lo ==> 顺序推进
    while (lo < hi) {
        if (nums[lo] == 0) {
            std::swap(nums[zero], nums[lo]);
            zero++;
            lo++;
        } else if (nums[lo] == 2) {
            std::swap(nums[lo], nums[hi-1]);
            hi--;
        } else {
           lo++;
        }
    }
}  

int main() {
    vector<int> vec = countBits(5);
    for (auto &v: vec) {
        cout << v << " ";
    }
    string a = "1010", b = "1011";
    cout << addBinary(a, b) << endl;
}
