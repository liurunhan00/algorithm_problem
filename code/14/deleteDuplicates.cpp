#include <bits/stdc++.h>
#include "deleteDuplicates.h"
using namespace std;
// 删除重复元素
ListNode* deleteDuplicates(ListNode* head) {
    ListNode* p = new ListNode(-1);
    ListNode* left, *right;
    p->next = head;
    head = p;
    while(p->next) {
        left = p->next;
        right = left;
        while(right->next && right->val == right->next->val)
            right = right->next;
        if(left == right) p = p->next;
        else p->next = right->next;
    }
    return head->next;
}


RandomList* copyRandomList(RandomList *head) {
    return nullptr;
}

