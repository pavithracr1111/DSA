#include "sll.h"

/* Function to get the nth node from the last of a linked list */
int find_nth_last(Slist *head, int pos, int *data) 
{ 
    if (head == NULL) // Correct comparison operator
    {
        return LIST_EMPTY;
    }
    else
    {
        Slist *t1 = head;
        Slist *t2 = head;

        // Check if pos is 0, move t1 to the last node and return its data
        if (pos == 0)
        {
            while (t1->link != NULL)
            {
                t1 = t1->link;
            }
            *data = t1->data;
            return SUCCESS;
        }

        // Move t1 pos steps forward
        while (pos > 0)
        {
            if (t1 == NULL) // If pos is greater than the length of the list
            {
                return FAILURE;
            }
            t1 = t1->link;
            pos--;
        }

        // Now move both t1 and t2 until t1 reaches the end of the list
        while (t1 != NULL)
        {
            t1 = t1->link;
            t2 = t2->link;
        }

        // t2 is now at the nth node from the end
        *data = t2->data;
        return SUCCESS;
    }
}
