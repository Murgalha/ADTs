#ifndef _QUEUE_H_
#define _QUEUE_H_

/* struct containing pointer to any
 * type array and queue size */
typedef struct {
    void **data;
    int size;
} queue_t;

/* return allocated queue_t pointer */
queue_t *queue_create();

/* free every element of queue and 
 * the queue itself */
void queue_delete(queue_t *);

/* add an element to the end of the queue */
void queue_push(queue_t *, void *);

/* return the element on the first 
 * position of the queue 
 * return NULL if queue pointer is NULL */
void *queue_front(queue_t *);

/* remove the front element of the queue */
void queue_pop(queue_t *);

/* return 1 -> queue is empty
 * 0 -> queue is not empty 
 * -1 -> passed queue pointer is NULL */
int queue_empty(queue_t *);

#endif
