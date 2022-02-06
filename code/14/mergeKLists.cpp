#include <bits/stdc++.h>
#include "deleteDuplicates.h"
using namespace std;

ListNode* mergeKLists(vector<ListNode*>& lists) {
    if(lists.size() == 0) return nullptr;
    int n = lists.size();
    ListNode* head = new ListNode(0);
    auto com = [](ListNode* A, ListNode* B){
        return A->val > B->val;// > 升序 < 降序
    };
    priority_queue<ListNode*, vector<ListNode*>, decltype(com)> pq(com);
    for(auto &h: lists) {
        if(h != nullptr) pq.push(h);
    }
    ListNode* tmp = head;
    while(!pq.empty()){
        tmp->next = pq.top();
        tmp = pq.top();
        pq.pop();
        if(tmp->next)pq.push(tmp->next);
    }
    return head->next;
}
ListNode* swapPairs_r(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* tmp = head->next;
    head->next = swapPairs_r(head->next);
    tmp->next = head;
    return tmp;
}
ListNode* swapPairs(ListNode* head) {
    ListNode *flag = new ListNode(0);
    flag->next = head;
    ListNode *p1 = flag;
    ListNode *p2;
    while(p1->next != nullptr && p1->next->next != nullptr) {
        p2 = p1->next;
        p1->next = p2->next;
        p2->next = p2->next->next;
        p1->next->next = p2;
        p1 = p2;
    }
    return flag->next;
}

void MergeTwoArray(vector<int> &array, int left, int right, int mid) {
    vector<int> tmp(right - left + 1, 0);
    int i = left, j = mid + 1, k = 0;
    while(i <= mid && j <= right) {
        if(array[i] <= array[j]) 
           tmp[k++] = array[i++];
        else 
            tmp[k++] = array[j++];
    }
    while(i <= mid) {
       tmp[k++] = array[i++];
    }
    while(j <= right) {
       tmp[k++] = array[j++];
    }
    for(int i = left; i <= right; ++i) {
       array[i] = tmp[i - left];
    }
} 
void Merge(vector<int> &arr, int left, int right){
    if(left < right) {
        int mid = left + ((right - left) >> 1);
        Merge(arr, left, mid);
        Merge(arr, mid+1, right);
        MergeTwoArray(arr, left, right, mid);
    }
}
    

ListNode* mergeTwoList(ListNode* headA, ListNode* headB) {
    if(headA == nullptr) return headB;
    if(headB == nullptr) return headA;
    if(headA->val < headB->val) {
        headA->next = mergeTwoList(headA->next, headB);
        return headA;
    }else {
        headB->next = mergeTwoList(headA, headB->next);
        return headB;
    }
    return nullptr;
}

// 合并区间
// 以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
// 请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

vector<vector<int>> merge(vector<vector<int>> intervals) {
    vector<vector<int>> res;    
    sort(intervals.begin(), intervals.end(), [&](const auto& A, const auto& B){
        return A[0] < B[0];
    });
    res.emplace_back(intervals[0]);
    for(int i = 1; i < intervals.size(); ++i) {
        auto back = res[res.size() - 1];
        if(back[1] >= intervals[i][0]) {
            res.pop_back();
            res.push_back({back[0], intervals[i][1]});
            // 自己构造一个对象
            // res.emplace_back(vector<int>{1,3});
        }
        else
            res.emplace_back(intervals[i]);
    }
    return res;      
}


int main() {
    ListNode *A = new ListNode(1);
    ListNode *B = new ListNode(2);
    ListNode *C = mergeTwoList(A, B);
    while(C){
        cout << C->val << endl;
        C = C->next;
    }
    std::vector<int> v = {1,3,5,2,4,6};
    Merge(v, 0, v.size()-1);
    for(auto &vc: v) {
        cout << vc << endl;
    }
    vector<vector<int>> intervals = {
        {1, 3}, {2, 6}, {8, 10}, {15, 18}
    };
    auto res = merge(intervals);
    for(auto &r: res){
        cout << r[0] << " " << r[1] << endl;
    }

}



    








