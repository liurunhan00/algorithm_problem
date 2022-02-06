#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val, ListNode* next): val(val), next(next){}
};

ListNode* deleteDuplicates(ListNode* head);
