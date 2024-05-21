#include "main.h"

// Function to convert an infix expression to a postfix expression
int Infix_Postfix_conversion(char *inf_expr, char *postfix_expr, Stack_t *stk)
{
    int i = 0, j = 0;

    // Loop through the infix expression until the null character is encountered
    while (inf_expr[i])
    {
        // If it's a character (number), add it to the postfix expression
        if (inf_expr[i] >= '0' && inf_expr[i] <= '9')
        {
            postfix_expr[j] = inf_expr[i];
            j++;
        }
        else if (inf_expr[i] == '(')
        { // Push '(' onto the stack
            push(stk, inf_expr[i]);
        }
        else if (inf_expr[i] == ')')
        { // Check for ')'
            // Pop elements from the stack until '(' is encountered
            while (stk->stack[stk->top] != '(')
            {
                postfix_expr[j] = peek(stk); // Add to postfix expression
                pop(stk);
                j++;
            }
            pop(stk); // Pop '('
        }
        else if (inf_expr[i] == '*' || inf_expr[i] == '/' || inf_expr[i] == '+' || inf_expr[i] == '-')
        {
            // Check for operator characters
            if (stk->top != -1 && peek(stk) != '(' && priority(inf_expr[i]) <= priority(peek(stk)))
            {
                postfix_expr[j] = peek(stk); // Add to postfix expression
                pop(stk);
                j++;
            }
            push(stk, inf_expr[i]);
        }
        i++;
    }

    // Clear the stack and add remaining characters to the postfix expression
    while (stk->top != -1)
    {
        postfix_expr[j] = peek(stk);
        pop(stk);
        j++;
    }

    postfix_expr[j] = '\0'; // Null-terminate the postfix expression
}