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

int __cmp_ll_node_obj(ll_node_obj a, ll_node_obj b)
{
        struct list_node *lhs = a.data;
        struct list_node *rhs = b.data;
        while (lhs && rhs) {
                int r = lhs->data < rhs->data ? -1 : lhs->data > rhs->data ? 0 : 1;
                if (r != 0)
                        return r;
                lhs = lhs->next;
                rhs = rhs->next;
        }
        return lhs ? 1 : rhs ? -1 : 0;
}

////////////////////////////////////////////////////////////////////////////////

void __print_ll_node_obj(ll_node_obj a)
{
        struct list_node *l = a.data;
        printf("[");
        while (l) {
                printf("%d", l->data);
                l = l->next;
                if (l)
                        printf(",");
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
