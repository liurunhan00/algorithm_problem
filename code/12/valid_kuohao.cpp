#include<bits/stdc++.h>
using namespace std;
bool isValid(string t) {
    stack<char> st;
    for(auto &ch: t){
        if(ch == '(') st.push(')');
        else if(ch == '[') st.push(']');
        else if(ch == '{') st.push('}');
        else if(st.empty() || ch != st.top()) return false;
        else if(ch == st.top()) st.pop();
    }
    return st.empty();
}

int main() {
    string t = "{}(){{}}[]";
    cout << isValid(t) << endl;
}
