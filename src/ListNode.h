#ifndef LIST_NODE_H
#define LIST_NODE_H

typedef struct ListNode_struct ListNode;

struct ListNode_struct
{
        int data;
        ListNode* next;
};

void ListNode_ToList(ListNode* head, int size, int list[size], const char*, const char*, int);
#define TO_LIST(head, size, list) ListNode_ToList(head, size, list, __FILE__, __FUNCTION__, __LINE__);

void ListNode_Free(ListNode* head);
#define FREE_LIST(head) ListNode_Free(head);

#endif
