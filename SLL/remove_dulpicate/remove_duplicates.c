#include "sll.h"

// Function to remove duplicates from a singly linked list
int remove_duplicates(Slist **head)
{
    if (*head == NULL)
    {
        return FAILURE; // List is empty
    }
    else if ((*head)->link == NULL)
    {
        return SUCCESS; // Only one element in the list, no duplicates possible
    }
    else
    {
        Slist *t1 = *head; // Pointer to traverse the list
        Slist *p;          // Pointer to hold the position for potential deletion
        Slist *t2;         // Pointer to compare with t1

        while (t1 != NULL)
        {
            p = t1;
            t2 = t1->link;
            while (t2 != NULL)
            {
                if (t1->data != t2->data)
                {
                    p = t2;        // Move p to t2 if data is not equal
                    t2 = t2->link; // Move t2 to the next node
                }
                else
                {
                    p->link = t2->link; // Adjust links to remove duplicate
                    free(t2);           // Free the duplicate node
                    t2 = p->link;       // Move t2 to the next node
                }
            }
            t1 = t1->link; // Move t1 to the next node
        }
        return SUCCESS;
    }
    return FAILURE;
}
