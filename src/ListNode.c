#include "ListNode.h"

void ListNode_ToList(ListNode* head, int size, int list[size])
{
        for (int i = 0; i < size; i++)
        {
                int j = i;
                ListNode* p = head;
                while (j--)
                        head = head->next;
                list[i] = p->data;
        }
}
