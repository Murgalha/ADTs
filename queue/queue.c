#include <stdlib.h>
#include "queue.h"

queue_t *queue_create() {
    queue_t *queue = (queue_t *) malloc (sizeof(queue_t));
    queue->data = NULL;
    queue->size = 0;
    return queue;
}

void queue_delete(queue_t *queue) {
    if(!queue)
        return;

    int i;
    for(i = 0; i < queue->size; i++)
        free((queue->data)[i]);
    free(queue->data);
    free(queue);
}

void queue_push(queue_t *queue, void *data) {
    if(!queue || !data)
        return;

    queue->data = (void **) realloc (queue->data, sizeof(void *)*((queue->size)+1));
    queue->data[queue->size++] = data;
}

void *queue_front(queue_t *queue) {
    if(!queue)
        return NULL;

    return *(queue->data);
}

void queue_pop(queue_t *queue) {
    if(!queue)
        return;

    int i;
    for(i = 0; i < (queue->size)-1; i++)
        (queue->data)[i] = (queue->data)[i+1];
    queue->data = (void **) realloc (queue->data, sizeof(void *)*(--queue->size));
}

int queue_empty(queue_t *queue) {
    if(!queue)
        return -1;

    return !(queue->size);
}
