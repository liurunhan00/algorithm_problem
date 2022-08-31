#include <bits/stdc++.h>
using namespace std;
bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    stack<int> st;
    int j = 0;
    for (int i = 0; i < pushed.size(); i++) {
        st.push(pushed[i]);
        while (!st.empty() && st.top() == popped[j]) {
            j++;
            st.pop();
        }
    }
    return st.empty();
}
