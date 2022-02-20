#include <bits/stdc++.h>

using namespace std;

// strlen_ 不使用循环实现
int my_strlen(const char* str) {
    return *(str++) ? 1 + my_strlen(str): 0;
}
char* my_memcpy(char *dest, const char* src, int len) {
    char *ret = dest;
    // 内存重叠从高地址开始复制
    if (dest >= src && dest < len + src) {
        cout << len << endl;
        dest = dest + len - 1;
        src = src + len - 1;
        while (len--) {
            *dest-- = *src--;
        }
    } else {
        while (len--) {
            *dest++ = *src++;
        }
    }
    return ret;
}
char* strcpy_(const char* src, char *dest) {
    char* ret = dest;
    my_memcpy(dest, src, my_strlen(src) + 1);
    return ret;
}
int main() {
    char *dest = static_cast<char*>(malloc(10*sizeof(char)));
    char s[10] = "hello";
    strcpy_("12", dest);
    cout << dest << endl;
    char* ret = strcpy_(s, s+1);
    cout << ret << endl;
   // cout << strcpy_(s+1, s) << endl;
    cout << s << endl;
}
