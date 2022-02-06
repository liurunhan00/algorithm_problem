/*
 *    读入字符串并丢弃无用的前导空格
 *    检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。 确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
 *    读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
 *    将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
 *    如果整数数超过 32 位有符号整数范围 [−231,  231 − 1] ，需要截断这个整数，使其保持在这个范围内。具体来说，小于 −231 的整数应该被固定为 −231 ，大于 231 − 1 的整数       应该被固定为 231 − 1 。
 *    返回整数作为最终结果。
 *    注意一：空白字符只含有空格
 *    注意二：除前导字符和数字后的其余字符串外，“忽略“所有字符
 */
#include <bits/stdc++.h>
using namespace std;

int Myatoi(string s) {
    int n = s.size();
    long res = 0;
    int flag = 1;
    int i;
    for(i = 0; i < n; i++) {
        if(s[i] != ' ' && s[i] != '+' && s[i] != '-' && !isdigit(s[i])) return 0;
        if(s[i] != ' ') break;
    }
    if(s[i] == '-') {
        flag = -1;
        i++;
    } else if(s[i] == '+') {
        flag = 1;
        i++;
    }
    for(; i < n; i++) {
        if(!isdigit(s[i])) continue;
        int t = s[i] - '0';
        res = res*10 + t;
        if(res >= INT_MAX) {
            if(flag == -1) {
                return INT_MIN;
            } else {
                return INT_MAX;
            }
        }
    }
    return res * flag;
}

int main() {
    cout << Myatoi("  -42 asdewqrw12787878783123");
    return 0;
}
