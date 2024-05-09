#include "stack.h"

/* Function to peek at the top element of the stack */
int Peek(Stack_t *s)
{
    // Check if the stack is empty
    if (s->top == -1) // If top is -1, stack is empty
    {
        // Stack is empty, cannot peek any element
        return FAILURE; // Indicate that the stack is empty and cannot peek any element
    }

    // Get the top element of the stack
    int element = s->stack[s->top];

    // Return the top element of the stack
    return element;
}
