#include <vector>
#include <algorithm>

using namespace std;

int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), 
                                [&pairs](vector<int>&a, vector<int>& b){
                                    return a[1] < b[1];
                                });
    
    int begin = pairs[0][1];
    int sum = 1;
    for (int i = 1; i < pairs.size(); i++) {
        if (pairs[i][0] <= begin) {
            continue;
        } else {
            sum++;
            begin = pairs[i][1];
        }
    }
    return sum;

}
