#include "main.h"

int Infix_Prefix_conversion(char *Infix_exp, char *Prefix_exp, Stack_t *stk)
{
    int i = 0, j = 0;
    // Up to the null character
    while (Infix_exp[i]) 
    {
        // If it's a character (number), add it to the prefix expression
        if (Infix_exp[i] >= '0' && Infix_exp[i] <= '9') 
        {
            Prefix_exp[j] = Infix_exp[i];
            j++;
        }
        // Push ')' onto the stack
        else if (Infix_exp[i] == ')') 
        {
            push(stk, Infix_exp[i]);
        }
        // Check for '(''
        else if (Infix_exp[i] == '(') 
        {
            // Pop up to '('
            while (stk->stack[stk->top] != ')') 
            {
                // Add to prefix expression
                Prefix_exp[j] = peek(stk); 
                pop(stk);
                j++;
            }
            pop(stk);
        }
        // Check for operator characters
        else if (Infix_exp[i] == '*' || Infix_exp[i] == '/' || Infix_exp[i] == '+' || Infix_exp[i] == '-') 
        {
            // Check priority and other characters
            while (stk->top != -1 && stk->stack[stk->top] != ')' && priority(Infix_exp[i]) < priority(stk->stack[stk->top])) 
            {
                // Add to prefix expression
                Prefix_exp[j] = peek(stk); 
                pop(stk);
                j++;
            }
            push(stk, Infix_exp[i]);
        }
    
        i++;
    }
    // Clear the stack and add characters to the prefix expression
    while (stk->top != -1) 
    {
        Prefix_exp[j] = peek(stk);
        pop(stk);
        j++;
    }
    Prefix_exp[j] = '\0';
	
}