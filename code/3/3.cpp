#include <string>
#include <iostream>
using namespace std;

string add(string &s1, string &s2){
    int n1 = s1.size() - 1;//s1的最低位下标
    int n2 = s2.size() - 1;//s2的最低位下标
    int carry = 0;
    string ans;

    while(n1 >= 0 || n2 >= 0 || carry > 0){
        int t1 = n1 >= 0 ? s1[n1--] - '0' : 0;
        int t2 = n2 >= 0 ? s2[n2--] - '0' : 0;
        ans += (t1 + t2 + carry) % 10 + '0';//最低位放在最前面
        carry = (t1 + t2 + carry) / 10;//进位：逢10进1
    }

    return ans;
}

bool dfs(string &num, int i, int j, int k) {
// 以0开头且不为0的字符串
    if (num[i] == '0' && j != i + 1) return false;
    if (num[j] == '0' && k != j + 1) return false;
    string num1 = num.substr(i, j - i);
    string num2 = num.substr(j, k - j);
    string sum = add(num1, num2);
    if (sum.size() + k > num.size()) return false;
    for (int i = k; i <= k - 1 + sum.size(); ++i) {
       if (num[i] != sum[i - k]) return false;
    }
    if (sum.size() == num.size() - k) return true;
    return dfs(num, j, k, k + sum.size());
}

bool isAdditiveNumber(string num) {
    int n = num.size();
    for (int i = 0; i < n; ++i){
        for (int j = i + 1; j < n; ++j) {
            if (dfs(num, 0, i, j)) {
                return true;
            }
        }
    }
    return false;
}


int main() {
    string v = "";
    v += "112358";
    bool flag = isAdditiveNumber(v);
    std::cout << flag << std::endl;
}



















    


