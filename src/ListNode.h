#ifndef LIST_NODE_H
#define LIST_NODE_H

typedef struct ListNode_struct ListNode;

struct ListNode_struct
{
        int data;
        ListNode* next;
};

void ListNode_ToList(ListNode* head, int size, int list[size]);

#endif
