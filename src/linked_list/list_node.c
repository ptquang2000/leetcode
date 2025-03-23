#include "list_node.h"
#include "utils/logger.h"
#include "utils/type.h"

static struct list_node *new_node(struct list_node i_node);
#define node(...) new_node((struct list_node){__VA_ARGS__});

////////////////////////////////////////////////////////////////////////////////

static struct list_node *new_node(struct list_node i_node)
{
        struct list_node *node = calloc(1, sizeof(*node));
        node->next = i_node.next ? i_node.next : 0;
        node->data = i_node.data;
        return node;
}

////////////////////////////////////////////////////////////////////////////////

static int __cycle_len(struct list_node *L)
{
        struct list_node *dummy = L->next;
        int i = 1;
        while (dummy != L) {
                i++;
                dummy = dummy->next;
        }
        return i;
}

////////////////////////////////////////////////////////////////////////////////

static struct list_node *__has_cycle(struct list_node *L)
{
        struct list_node *slow = L, *fast = L;
        while (slow && fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;
                if (slow == fast) {
                        int len = __cycle_len(fast);
                        struct list_node *advanced_node = L;
                        for (int i = 0; i < len; i++)
                                advanced_node = advanced_node->next;
                        while (L != advanced_node) {
                                L = L->next;
                                advanced_node = advanced_node->next;
                        }
                        return L;
                }
        }
        return 0;
}

////////////////////////////////////////////////////////////////////////////////

int __cmp_ll_node_obj(ll_node_obj a, ll_node_obj b)
{
        struct list_node *lhs = a.data;
        struct list_node *rhs = b.data;
        struct list_node *c1 = __has_cycle(a.data);
        struct list_node *c2 = __has_cycle(b.data);
        int r = !c1 ^ !c2 ? (c1 ? -1 : 0) : (c2 ? 1 : 0);
        while (!r && lhs != c1 && rhs != c2) {
                r = lhs->data < rhs->data ? -1 : lhs->data > rhs->data ? 1 : 0;
                lhs = lhs->next;
                rhs = rhs->next;
        }
        return r ? r : c1 == c2 ? 0 : lhs == c1 ? -1 : rhs == c2 ? 1 : lhs ? 1 : rhs ? -1 : 0;
}

////////////////////////////////////////////////////////////////////////////////

void __print_ll_node_obj(ll_node_obj a)
{
        struct list_node *l = a.data;
        struct list_node *c = __has_cycle(l);
        printf("[");
        while (l != c) {
                printf("%d", l->data);
                l = l->next;
                if (l != c)
                        printf(",");
        }
        if (l) {
                printf(",");
                printf("%d", l->data);
                l = l->next;
                while (l != c) {
                        printf(",");
                        printf("%d", l->data);
                        l = l->next;
                }
        }
        printf("]");
}

////////////////////////////////////////////////////////////////////////////////

struct list_node *list_node_from_list(int size, int list[size])
{
        struct list_node *head = 0;
        for (int i = size - 1; i >= 0; i--) {
                head = node(list[i], head);
        }
        return head;
}

////////////////////////////////////////////////////////////////////////////////

void list_node_to_list(struct list_node *head, int size, int list[size], const char *file, const char *func, int line)
{
        int actualSize = 0;
        for (int i = 0; i < size; i++, actualSize++) {
                if (head == 0) {
                        UTILS_LOG("\n-----------------------------------------------------");
                        UTILS_LOG("FAILED: {}", (string_obj){(char *)func});
                        UTILS_LOG("File {} at line {}:", (string_obj){(char *)file}, (int_obj){line});
                        UTILS_LOG("Expected linked list's size {} got {}", (int_obj){size}, (int_obj){actualSize});
                        UTILS_LOG("-----------------------------------------------------\n");
                        __builtin_trap();
                }
                list[i] = head->data;
                head = head->next;
        }
}

////////////////////////////////////////////////////////////////////////////////

void list_node_free(struct list_node *head)
{
        struct list_node *tmp;
        while (head) {
                tmp = head->next;
                free(head);
                head = tmp;
        }
}

////////////////////////////////////////////////////////////////////////////////
