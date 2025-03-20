#ifndef LIST_NODE_H
#define LIST_NODE_H

struct list_node {
        int data;
        struct list_node *next;
};

void list_node_to_list(struct list_node *head, int size, int list[size], const char *, const char *, int);
#define TO_LIST(head, size, list) list_node_to_list(head, size, list, __FILE__, __FUNCTION__, __LINE__);

struct list_node *list_node_from_list(int size, int list[size]);
#define FROM_LIST(size, list) list_node_from_list(size, list);

void list_node_free(struct list_node *head);
#define FREE_LIST(head) list_node_free(head);

#endif
