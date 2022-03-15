#include <cstdint>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
// 上升三元组
bool increasingTriplet(vector<int>& nums) {
    int a = INT32_MAX, b = INT32_MAX;
    for (auto &n: nums){
      if (n <= a) {
        a = n;
      }  else if (n <= b) {
          b = n;
      } else {
        return true;
      }
    }
    return false;
}
int main() {
    vector<int> nums = {2,1,5,0,7,6};
    vector<int> nums2 = {4, 3, 2, 1};
    cout << boolalpha << increasingTriplet(nums2) << endl;
    cout << boolalpha << increasingTriplet(nums) << endl;
}










