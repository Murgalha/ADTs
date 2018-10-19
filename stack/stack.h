#ifndef _STACK_H_
#define _STACK_H_

/* stack type containig a pointer to 
 * a void* element and size */
typedef struct {
    void **top, **bottom;
    int size;
} stack_t;

/* return a new allocated string_t pointer */
stack_t *stack_create();

/* insert an element into the given stack,
 * increasing its size */
void stack_push(stack_t *, void *);

/* remove the element on top of the stack
 * and decrease its size */
void stack_pop(stack_t *);

/* return the top element */
void *stack_top(stack_t *);

/* free every element on the stack */
void stack_delete(stack_t *);

/* return 1 if stack is empty
 * 0 otherwise */
int empty(stack_t *);

#endif
