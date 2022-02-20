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
         
// 寻找旋转排序数组中的最小值
// 数字均不相同
int findMinInrotate(vector<int> &nums) {
    int r = nums.size() - 1, l = 0;
    while (l < r) {
        int mid = l + ((r - l) >> 1);
        /* l < r 的最终点一定是(r, r + 1);
         * mid最终取值l，若此时与l自身比较会出现等于情况 不好判断
         * 所以判断mid与r比较，这样两数不同比较
         */
        if (nums[mid] < nums[r]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return nums[l];
}

// 寻找峰值
// 返回任意一个峰值即可
// 峰值指值严格大于左右相邻值的元素
// 假定nums[-1] = nums[n] = -∞
int findPeakElement(vector<int>& nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = l + ((r - l) >> 1);
        // 左边界值 ==》 mid + 1 一定存在
        // nums[mid] > nums[mid+1] ==》峰值在mid及以前
        // nums[mid] < nums[mid+1] ==》峰值在mid+1及以后
        if (nums[mid] < nums[mid+1]) {
            l = mid + 1;
        } else {
            r = mid;
        }
    } 
    return l;
}



int main() {
    std::vector<int> v = {1,1,2,2,2,3,4,5};
    cout << findLowerbound(v, 2) << endl;
    cout << findUpperbound(v, 2) << endl;
}
 
