#include "main.h"

int Prefix_Eval(char *Prefix_exp, Stack_t *stk) {
    int i = 0, num, result;
    int operand1, operand2;

    while (Prefix_exp[i]) 
    {
        // Check for characters (numbers)
        if (Prefix_exp[i] >= '0' && Prefix_exp[i] <= '9')
        {
            // Convert into integers and push it to the stack
            push(stk, Prefix_exp[i] - 48);
        }
        // If any operators are found in the prefix expression, pop 2 numbers
        else
        {
            operand1 = peek(stk);
            pop(stk);
            operand2 = peek(stk);
            pop(stk);
            // Performing operations
            switch (Prefix_exp[i]) 
            {
                case '*':
                    num = operand1 * operand2;
                    break;
                case '/':
                    num = operand1 / operand2;
                    break;
                case '+':
                    num = operand1 + operand2;
                    break;
                case '-':
                    num = operand1 - operand2;
                    break;
            }
            // Store the solution in the stack
            push(stk, num);
        }
        i++;
    }
    // Store the final result and return it
    result = peek(stk);
    pop(stk);

    return result;
}
