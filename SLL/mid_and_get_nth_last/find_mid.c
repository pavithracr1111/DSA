#include "sll.h"

/* Function to get the middle of the linked list*/
int find_mid(Slist *head, int *mid) 
{ 
    Slist *fast = head; // Fast pointer moves two steps at a time
    Slist *slow = head; // Slow pointer moves one step at a time

    if (head == NULL)
    {
        return LIST_EMPTY; // If the list is empty, return LIST_EMPTY
    }
    else
    {
        // Traverse the list with two pointers, one moving twice as fast as the other
        while (fast != NULL && fast->link != NULL)
        {
            fast = fast->link->link; // Fast pointer moves two steps
            slow = slow->link;       // Slow pointer moves one step
        }

        *mid = slow->data; // Assign the data of the middle node to mid
        return SUCCESS;   // Return SUCCESS indicating middle element found
    }
}
