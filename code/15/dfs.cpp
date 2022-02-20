#include<bits/stdc++.h>
#include <cctype>
#include<cstdlib>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// 分割回文子字符串
bool par_is_vali(string s, int x, int i){
    while(x < i) {
        if(s[x++] != s[i--]) {
            return false;
        }
    }
    return true;
}
void par_dfs(string s,int x, vector<vector<string>> &res, vector<string> &path){
    if(x >= s.size()){
        res.push_back(path);
    }
    for(int i = x; i < s.size(); ++i) {
        if(par_is_vali(s, x, i)){
            path.push_back(s.substr(x, i - x + 1));
            par_dfs(s, i+1, res, path);
            path.pop_back();
        }
    }
}


vector<vector<string>> partition(string s) 
{
    vector<vector<string>> res;
    vector<string> path;
    par_dfs(s,0,res,path);
    return res;
}


// 复原IP
namespace fuyuanIp
{
    vector<string> res;
    string path;
    bool Valid(string s) {
        if(s.size() > 1 && s[0] == '0') return false;
        int t = stoi(s);
        return t >= 0 && t <= 255;
    }   
    void dfs(string s, int strat_i, int cnt, string cur_str) {
        if(cnt == 3) {
            if(Valid(s.substr(strat_i, s.size() - strat_i))){
                cur_str += s.substr(strat_i, s.size() - strat_i);
                res.push_back(cur_str);
            }
            return;
        }
        if(cnt > 3) return;
        string str = "";
        for(int i = strat_i; i < strat_i + 3 && i < s.size(); ++i) {
            str += s[i];
            if(Valid(str)){
                dfs(s, strat_i + i + 1, cnt + 1, cur_str + str + '.');
            }
        
        }
    }    
    vector<string> restoreIpAddress(string s) {
        dfs(s, 0, 0, "");
        return res;
    }
   
// 有效的IP地址
    string checkipv4(string IP) {
        istringstream in(IP);
        for (int i = 0; i < 4; ++i) {
            string piece;
            getline(in, piece, '.');
            if (piece.size() > 3 || piece.size() < 1) return "Neither";
            for (auto &e: piece) if (!isdigit(e)) return "Neither";
            if (stoi(piece) > 255 || piece.size() > 1 && piece.front() == '0') return "Neither";
        }
        return in.eof() ? "IPv4": "Neither";
    }
    string checkipv6(string IP) {
        istringstream in(IP);
        for (int i = 0; i < 8; ++i) {
            string piece;
            getline(in, piece, ':');
            if (piece.size() > 4 || piece.size() < 1) return "Neither";
            for (auto &e: piece) {
                if (!isalnum(e) || isalpha(e) && tolower(e) > 'f') return "Neither";
            }
        }
        return in.eof()? "IPv6": "Neither";
    }
    string validIPAddress(string IP) {
        if (IP.size() > 39 || !isalnum(IP.back())) return "Neither";
        for (int i = 1; i < 5; ++i) {
            if (IP[i] == '.') return checkipv4(IP);
            if (IP[i] == ':') return checkipv6(IP);
        }
        return "Neither";
}

// 含有重复元素集合的组合
namespace combinationSum2 {
    vector<int> path;
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int target, int start) {
       if(0 == target) {
           res.push_back(path);
           return;
       }
       if(0 > target) {
           return;
       }
       for(int i = start; i < nums.size(); ++i){
          if(target - nums[i] < 0) break;
          if(i > start && nums[i] == nums[i-1]) continue;
          path.push_back(nums[i]);
          dfs(nums, target - nums[i], start + 1);
          path.pop_back();
       }
    }
    vector<vector<int>>& combinationSum2(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        dfs(nums, target, 0);
        return res;
    }
}
// 没有重复元素集合的全排列
namespace permute {
    vector<int> path;
    vector<vector<int>> res;
    void dfs(vector<int> &nums, vector<int>& vis, int start) {
        if(nums.size() == path.size()) {
            res.push_back(path);
        }
        for(int i = start; i < nums.size(); ++i) {
            if(vis[i] == 0){
                vis[i] = 1;
                path.push_back(nums[i]);
                dfs(nums, vis, start);
                path.pop_back();
                vis[i] = 0;
            }
        }
    }

    vector<vector<int>>& permute(vector<int>& nums){
        vector<int> vis(nums.size(), 0);
        dfs(nums, vis, 0);
        return res;
    }
}

// 有重复元素集合的全排列
namespace premuteUnique {
    vector<int> path;
    vector<vector<int>> res;
    void dfs(vector<int>& nums, int start, vector<int>& vis){
        if(start == nums.size()){
            res.emplace_back(nums);
            return;
        }
        for(int i = start; i < nums.size(); ++i) {
           if(vis[i] == 1 || (i > 0 && vis[i - 1] == 0 && nums[i] == nums[i - 1])) continue;
           vis[i] = 1;
           path.push_back(nums[i]);
           dfs(nums, start, vis);
           path.pop_back();
           vis[i] = 0;
        }


    }
    vector<vector<int>>& premuteUnique(vector<int>& nums){
        vector<int> vis(nums.size(), 0);
        sort(nums.begin(), nums.end());
        dfs(nums, 0, vis);
        return res;
    }
}
