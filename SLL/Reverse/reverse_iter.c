#include "sll.h"

/* Function to reverse the given single linked list */
int reverse_iter(Slist **head) 
{ 
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    // If the list has only one node, it's already reversed
    else if ((*head)->link == NULL) {
        return SUCCESS;
    }
    else
    {
        Slist *temp = *head;
        Slist *prev = NULL;
        Slist *next;

        while (temp != NULL)
        {
            next = temp->link;
            if (prev == NULL)
            {
                temp->link = NULL;
            }
            else
            {
                temp->link = prev;
            }
            prev = temp;
            temp = next;
        }
        *head = prev;  // Update the head pointer to the new first node
    }
    
    return SUCCESS;
} 