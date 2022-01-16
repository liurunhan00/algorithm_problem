#include <iostream>
using namespace std;
// 蓄水池算法
// 从包含未知大小的数据流中随机抽取K个数据
// 保证每个数据概率相等 
// 从链表头开始，遍历整个链表，对遍历到的第 i 个节点，
// 随机选择区间 [0,i)[0,i) 内的一个整数，如果其等于 0，则将答案置为该节点值，否则答案不变
struct ListNode {
    ListNode *next;
    int val;
    ListNode(int x):val(x), next(nullptr) {}
    ListNode():val(0), next(nullptr){}
};
class Solution {
    ListNode *head;

public:
    Solution(ListNode *head) {
        this->head = head;
    }

    int getRandom() {
        int i = 1, ans = 0;
        for (auto node = head; node; node = node->next) {
            if (rand() % i == 0) { // 1/i 的概率选中（替换为答案）
                ans = node->val;
            }
            ++i;
        }
        return ans;
    }
};

