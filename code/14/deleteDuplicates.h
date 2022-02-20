#pragma once
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val): val(val), next(nullptr){}
    ListNode(int val, ListNode* next): val(val), next(next){}
};

struct RandomList {
    int val;
    RandomList *next;
    RandomList *random;
    RandomList(int val): val(val), next(nullptr), random(nullptr) {}
};

RandomList* copyRandomList(RandomList* head);
ListNode* deleteDuplicates(ListNode* head);
