#include <functional>
#include <queue>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    auto com = [&](vector<int>& A, vector<int>&B){
       return A[0] + A[1] < B[0] + B[1];
    }; 
    priority_queue<vector<int>, vector<vector<int>>, decltype(com)> pq(com);
    int n1 = nums1.size(), n2 = nums2.size(), t1 = 0, t2 = 0;
    for(int j = 0; j < n1; ++j) {
        for(int i = 0; i < n2; ++i) {
            if(pq.size() < k) {
                pq.push({nums1[j], nums2[i]});
            } else {
                if (nums1[j] + nums2[i] < pq.top()[0]+ pq.top()[1]) {
                    pq.pop();
                    pq.push({nums1[j], nums2[i]});
                } else {
                    break;
                }
            }
        }
    }
    vector<vector<int>> res;
    while(!pq.empty()) {
            res.emplace_back(pq.top());
            pq.pop();
    } 
    return res;
}
int main() {
    vector<int> nums1 = {1, 1, 2};
    vector<int> nums2 = {1, 2, 3};
    int k = 3;
    vector<vector<int>> p = kSmallestPairs(nums1, nums2, k);
    for (auto &s: p) {
        cout << s[0] << s[1] << endl;
    }
}
