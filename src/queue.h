#ifndef QUEUE_H
#define QUEUE_H

#include <stddef.h>

struct queue_node;

struct queue {
        size_t size;
        struct queue_node *front;
        struct queue_node *back;
};

struct queue queue_ctor();
void queue_dtor(struct queue *q);
void queue_push(struct queue *q, void *next);
void *queue_pop(struct queue *q);

#endif
