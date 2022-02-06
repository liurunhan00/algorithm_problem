#include<bits/stdc++.h>
using namespace std;
vector<string> res;
void dfs(int l, int r, int n, string str) {
    if (l < r || l > n || r > n) {
        return;
    }
    if (l == n && r == n) {
        res.emplace_back(str);
        return;
    }
    str += '(';
    dfs(l+1, r, n, str);
    str.pop_back();
    str += ')';
    dfs(l, r+1, n, str);
}
vector<string> generateParenthesis(int n) {
    
    dfs(0, 0, n, "");
    return res;
}

int main(){
    dfs(0, 0, 3, "");
    for(auto &r: res){
        cout << r << endl;
    }
}

