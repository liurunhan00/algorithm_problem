#include <vector>
#include <algorithm>
using namespace std;

int specialArray(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    if (len <= nums[0])
    {
        return len;
    }
    for (int i = 1; i < len; i++)
    {
        if (len - i < nums[i-1])
        {
            break;
        }
        if (len - i <= nums[i] && len - i > nums[i - 1])
        {
            return len - i;
        }
    }
    return -1;
}
