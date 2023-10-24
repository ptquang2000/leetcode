#include "merge_two_sorted_lists.h"
#include "unity.h"
#include "stdlib.h"
#include <limits.h>


struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2)
{
    struct ListNode *l1, *l2;
    if (list1 == NULL) {
	return list2;
    } else if (list2 == NULL) {
	return list1;
    } else {
	l1 = list1->val < list2->val ? list1 : list2;
    }

    struct ListNode* next;
    while (l1 != NULL && l1->next != NULL) {
	next = l1->next;
	if (l2 != NULL && next->val > l2->val) {
	    l1->next = l2;
	    l2 = l2->next;
	    l1->next->next = next;
	} else if (l2 == NULL) {
	    break;
	}
    }
    return l1;
}

void test0_merge_two_sorted_lists(void)
{
    struct ListNode* node = malloc(sizeof(* node));
    struct ListNode* node1 = malloc(sizeof(* node));
    struct ListNode* node2 = malloc(sizeof(* node));

    node->val = 1;
    node->next = node1;
    node1->val = 2;
    node1->next = node2;
    node2->val = 4;
    node2->next = NULL;

    struct ListNode* _node = malloc(sizeof(* node));
    struct ListNode* _node1 = malloc(sizeof(* node));
    struct ListNode* _node2 = malloc(sizeof(* node));

    node->val = 1;
    node->next = node1;
    node1->val = 2;
    node1->next = node2;
    node2->val = 4;
    node2->next = NULL;

    _node->val = 1;
    _node->next = _node1;
    _node1->val = 3;
    _node1->next = _node2;
    _node2->val = 4;
    _node2->next = NULL;

    struct ListNode* p = mergeTwoLists(node, _node);
    TEST_ASSERT_EQUAL(p->val, 1);
    p = p->next;
    TEST_ASSERT_EQUAL(p->val, 1);
    p = p->next;
    TEST_ASSERT_EQUAL(p->val, 2);
    p = p->next;
    TEST_ASSERT_EQUAL(p->val, 3);
    p = p->next;
    TEST_ASSERT_EQUAL(p->val, 4);
    p = p->next;
    TEST_ASSERT_EQUAL(p->val, 4);
    p = p->next;
    TEST_ASSERT_EQUAL(p, NULL);

    free(node);
    free(node1);
    free(node2);
    free(_node);
    free(_node1);
    free(_node2);
}

void test1_merge_two_sorted_lists(void)
{
    struct ListNode* p = mergeTwoLists(NULL, NULL);

    TEST_ASSERT_EQUAL(p, NULL);
}

void test2_merge_two_sorted_lists(void)
{
    struct ListNode* node = malloc(sizeof(* node));

    node->val = 0;
    node->next = NULL;

    struct ListNode* p = mergeTwoLists(NULL, node);
    TEST_ASSERT_EQUAL(p->val, 0);
    p = p->next;
    TEST_ASSERT_EQUAL(p, NULL);

    free(node);
}
