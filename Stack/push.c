#include "stack.h"

/* Function for inserting an element into the stack */
int Push(Stack_t *stack, int element)
{
    // Check if the stack is full
    if (stack->top == stack->capacity - 1) // If top is at the last index (capacity - 1), stack is full
        return FAILURE; // Indicate that the insertion failed because the stack is full

    // Increment the top index to make space for the new element
    stack->top = stack->top + 1;

    // Insert the new element at the top of the stack
    stack->stack[stack->top] = element;

    // Return true to indicate successful insertion
    return SUCCESS;
}
