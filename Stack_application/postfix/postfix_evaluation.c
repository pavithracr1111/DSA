#include "main.h"

int Postfix_Eval(char *postfix_expr, Stack_t *stk)
{
    int i = 0, num , result;
    int operand1, operand2;

    while ( postfix_expr[i])
    {
        // check for characters (numbers)
        if ( postfix_expr[i] >= '0' && postfix_expr[i] <= '9' )	
	    {
	        // convert into integers and push it to the stack
	        push (stk, postfix_expr[i] - 48 );	
    	}
    	// if any operators found in postfix expression pop 2 numbers
	    else	
	    {
    	    operand2 = peek (stk);
    	    pop (stk);
    	    operand1 = peek  (stk);
    	    pop (stk);
            // performing operations
    	    switch (postfix_expr[i])	
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
    	   	// store the solution into stack
    	    push (stk, num);
    	}
    	i++;
    }
    // store final result and return it
    result = peek (stk);
    pop (stk);	

    return result;
}