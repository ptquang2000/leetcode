#include "linked_list_cycle.h"
#include "stdbool.h"
#include "unity.h"
#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>


struct ListNode {
	int val;
	struct ListNode *next;
};

bool hasCycle(struct ListNode *head) 
{
	for (
	struct ListNode *p = head; 
	head != NULL && head->next != NULL; 
	head = head->next->next, p = p->next) {
		if (head->next->next == p->next) {
			return true;
		}
	}
	return false;
}

void test0_linked_list_cycle(void)
{
	struct ListNode* node = malloc(sizeof(* node));
	struct ListNode* node1 = malloc(sizeof(* node));
	struct ListNode* node2 = malloc(sizeof(* node));
	struct ListNode* node3 = malloc(sizeof(* node));

	node->val = 3;
	node->next = node1;
	node1->val = 2;
	node1->next = node2;
	node2->val = 0;
	node2->next = node3;
	node3->val = 4;
	node3->next = node1;

	TEST_ASSERT_TRUE(hasCycle(node));

	free(node);
	free(node1);
	free(node2);
	free(node3);
}

void test1_linked_list_cycle(void)
{
	struct ListNode* node = malloc(sizeof(* node));
	struct ListNode* node1 = malloc(sizeof(* node));

	node->val = 1;
	node->next = node1;
	node1->val = 2;
	node1->next = node;

	TEST_ASSERT_TRUE(hasCycle(node));

	free(node);
	free(node1);
}

void test2_linked_list_cycle(void)
{
	struct ListNode* node = malloc(sizeof(* node));

	node->val = 1;
	node->next = NULL;

	TEST_ASSERT_FALSE(hasCycle(node));

	free(node);
}
