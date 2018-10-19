#include <stdlib.h>
#include "stack.h"

stack_t *stack_create() {
    stack_t *stack = (stack_t *) malloc (sizeof(stack_t));
    stack->size = 0;
    stack->bottom = NULL;
    stack->top = stack->bottom;
}

void stack_push(stack_t *stack, void *element) {
    stack->bottom = (void **) realloc (stack->bottom, sizeof(void *)*(stack->size+1));
    stack->top = stack->bottom+stack->size;
    *(stack->top) = element;
    stack->size++;
}

void stack_pop(stack_t *stack) {
    stack->bottom = (void **) realloc (stack->bottom, sizeof(void *)*(stack->size-1));
    stack->top--;
    stack->size--;
}

void *stack_top(stack_t *stack) {
    void *aux = *(stack->top);
    return aux;
}

void stack_delete(stack_t *stack) {
    if(!stack)
        return;
    while(stack->size > 0) {
        free(*(stack->top));
        stack_pop(stack);
    }
    free(stack);
}

int empty(stack_t *stack) {
    return !(stack->size);
}
