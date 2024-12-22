#include "ListNode.h"
#include "utils.h"

#include <stdlib.h>

////////////////////////////////////////////////////////////////////////////////

void ListNode_ToList(ListNode* head, int size, int list[size], const char* file, const char* func, int line)
{
        int actualSize = 0;
        for (int i = 0; i < size; i++, actualSize++)
        {
                if (head == 0)
                {
                        UTILS_LOG("\n-----------------------------------------------------");
                        UTILS_LOG("FAILED: {}", UTYPE(func));
                        UTILS_LOG("File {} at line {}:", UTYPE(file), UTYPE(line));
                        UTILS_LOG("Expected linked list's size {} got {}", UTYPE(size), UTYPE(actualSize));
                        UTILS_LOG("-----------------------------------------------------\n");
                        __builtin_trap();
                }
                list[i] = head->data;
                head = head->next;
        }
}

////////////////////////////////////////////////////////////////////////////////

void ListNode_Free(ListNode* head)
{
        ListNode* tmp;
        while (head)
        {
                tmp = head->next;
                free(head);
                head = tmp;
        }
}

////////////////////////////////////////////////////////////////////////////////
