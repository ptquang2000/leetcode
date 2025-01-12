#include "queue.h"

#include <assert.h>
#include <stdlib.h>

struct queue queue_ctor()
{
        return (struct queue){
                .size = 0,
                .front = 0,
                .back = 0,
        };
}

void queue_dtor(struct queue *q)
{
        struct queue_node *n;
        while (q->size--) {
                n = q->front->next;
                free(q->front);
                q->front = n;
        }
        q->front = 0;
        q->back = 0;
        q->size = 0;
}

void queue_push(struct queue *q, void *next)
{
        assert(q != 0 && "Queue is null");
        // assert(next != 0 && "Push to queue a null node");

        struct queue_node *n = calloc(1, sizeof(*n));
        n->node = next;
        n->next = 0;

        if (!q->size) {
                q->front = n;
                q->back = n;
        } else {
                q->back->next = n;
                q->back = n;
        }
        q->size++;
}

void *queue_pop(struct queue *q)
{
        assert(q != 0 && "Queue is null");
        assert(q->size != 0 && "Pop a empty queue");

        struct queue_node *front = q->front;
        void *n = front->node;

        q->size--;
        if (!q->size) {
                q->front = 0;
                q->back = 0;
        } else {
                q->front = front->next;
        }
        free(front);

        return n;
}
