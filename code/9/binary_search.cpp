// 统计数字在数组中出现次数
#include<bits/stdc++.h>
using namespace std;

int findUpperbound(vector<int> &vec, int target) {
    int l = 0, r = vec.size() - 1;
    while(l < r) {
        int mid = l + ((r - l + 1) >> 1);
        if(vec[mid] > target) r = mid - 1; 
        else l = mid;
    }
    return l;
}
int findLowerbound(vector<int> &vec, int target) {
    int l = 0, r = vec.size() - 1;
    while(l < r) {
        int mid = l + ((r - l) >> 1);
        if(vec[mid] < target) l = mid + 1; 
        else r = mid;
    }
    return l;
}

// 搜索旋转排序数组
int search_rotate(vector<int> &nums, int target) {
     // 每次二分一半有序 一半无序
     // 如果nums[mid] < 右边 ==》 右边有序
     // 如果nums[mid] > 左边 ==》 左边有序
     // 然后判断target是不是在有序区间里
     int n = nums.size();
     if(n == 0) return -1;
     int l = 0, r = n - 1;
     while(l <= r) {
         int mid = l + ((r - l) >> 1);
         if(nums[mid] == target) {
             return mid;
         }
         if(nums[mid] < nums[r]) {
            if(nums[mid] < target && nums[r] > target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
         } else {
             if(nums[mid] > target && nums[l] < target) {
                 r = mid - 1;
             } else {
                 l = mid + 1;
             }
         }
     }
     return -1;
}
    
         

int main() {
    std::vector<int> v = {1,1,2,2,2,3,4,5};
    cout << findLowerbound(v, 2) << endl;
    cout << findUpperbound(v, 2) << endl;
}

