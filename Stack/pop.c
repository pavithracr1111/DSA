#include "stack.h"

/* Function to remove the top element from the stack (Pop) */
int Pop(Stack_t *s)
{
    // Check if the stack is empty
    if (s->top == -1) // If top is -1, stack is empty
    {
        // Stack is empty, cannot pop any element
        return FAILURE; // Indicate that the stack is empty and cannot pop any element
    }

    // Get the top element of the stack before removing it
    int element = s->stack[s->top];

    // Decrement the top index to remove the top element (simulate popping)
     s->top = s->top-1;

    // Return true to indicate successful pop operation
    return SUCCESS;
}
