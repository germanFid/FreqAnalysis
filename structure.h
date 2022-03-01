#ifndef STRUCT_INCLUDED
#define STRUCT_INCLUDED

#include <string.h>
#include <stdlib.h>

struct stack
{
    int maxsize;
    int top;
    wchar_t *items;
};

struct stack* newStack(int capacity)
{
    struct stack *pt = (struct stack*)malloc(sizeof(struct stack));
 
    pt->maxsize = capacity * 2;
    pt->top = -1;
    pt->items = (wchar_t*)malloc(sizeof(wchar_t) * capacity * 2);
 
    return pt;
}

int size(struct stack *pt) {
    return ((pt->top + 1) / 2);
}

int isEmpty(struct stack *pt) {
    return pt->top == -1;                   // or return size(pt) == 0;
}

int isFull(struct stack *pt) {
    return pt->top == pt->maxsize - 1;      // or return size(pt) == pt->maxsize;
}

void push(struct stack *pt, wchar_t og, int to)
{
    // check if the stack is already full. Then inserting an element would
    // lead to stack overflow
    if (isFull(pt))
    {
        exit(EXIT_FAILURE);
    }

    // add an element and increment the top's index
    pt->items[++pt->top] = og;
    pt->items[++pt->top] = to;
}

void peek(struct stack *pt, wchar_t* og, wchar_t* to)
{
    // check for an empty stack
    if (!isEmpty(pt)) {
        *to = pt->items[pt->top];
        *og = pt->items[pt->top - 1];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

void pop(struct stack *pt, wchar_t* og, wchar_t* to)
{
    // check for stack underflow
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }
 
    // decrement stack size by 1 and (optionally) return the popped element
    

    *to = pt->items[pt->top];
    *og = pt->items[pt->top - 1];

    pt->top -= 2;
}

#endif
