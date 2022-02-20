#include "strings.h"
#include <string>

string multiply(string num1, string num2) {
    int n1 = num1.size();
    int n2 = num2.size();
    vector<int> mul(n1+n2, 0); 
    for (int i = n1 - 1; i >= 0; --i) {
        for (int j = n2 - 1; j >= 0; --j) {
            int bitmuti = (num1[i] - '0') * (num2[j] - '0');
            bitmuti += mul[i + j + 1];
            mul[i + j] += bitmuti/10;
            mul[i + j + 1] = bitmuti%10;
        }
    }
    string res;
    int len = 0;
    while (len < mul.size() - 1 && mul[len] == 0) ++len;
    for (; len < mul.size(); ++len) 
        res += to_string(mul[len]);
    return res;
}

// 罗马数字转int
int romanToInt(string s) {
    unordered_map<string, int> u_map = {
        {"I", 1}, {"IV", 4}, {"V", 5},
        {"IX", 9}, {"X", 10}, {"XL", 40},
        {"L", 50}, {"XC", 90}, {"C", 100},
        {"CD", 400}, {"D", 400}, {"CM", 900},
        {"M", 1000} };
    int n = s.size();
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        if (i + 1 < n && u_map.find(s.substr(i, 2)) != u_map.end()) {
            ans += u_map[s.substr(i, 2)];
            i += 1;
        } else {
            ans += u_map[s.substr(i, 1)];
        }
    }
    return ans;
}

string intToRoma(int num) {
    int values[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    string repos[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};

    string res;
    for (int i = 13 - 1; i > -1; --i) {
        while(num >= values[i]) {
            res += repos[i];
            num -= values[i];
        }
    }
    return res;
}

int CompareVersion(string version1, string version2) {
    // 1 > 2 ret 1 2 > 1 ret -1 | ret 0
    int i = 0, j = 0;
    while (i < version1.size() || j < version2.size()) {
        int a = 0, b = 0;
        while (i < version1.size() && version1[i] != '.') {
            a += a*10 + version1[i] - '0';
            i++;
        }
        while (j < version1.size() && version1[j] != '.') {
            b += b*10 + version2[j] - '0';
            j++;
        }
        if (a > b) return 1;
        if (a < b) return -1;
        // 去掉'.'
        i++;
        j++;
    }
    return 0;
}
    
        

// word1 -> word2 使用的最小步数
int minDistance(string word1, string word2) {
    
            

}

// 数字转字符串翻译个数
// 青蛙跳台阶
int translateNum(int num) {
    string t = to_string(num);
    vector<int> dp(t.size() + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < t.size(); ++i) {
        dp[i] = dp[i-1];
        int subnum = t[i-2]*10 + t[i-1];
        if (subnum >= 10 && subnum <= 25) {
            dp[i] += dp[i-2];
        }
    }
    return dp[t.size()];
}
