#include "sll.h"

int reverse_recursive(Slist ** head)
{
    if (*head == NULL)
    {
        return LIST_EMPTY;
    }
    Slist *temp = *head;
    Slist *next = temp->link;


    // If the next node is NULL (end of the list)
    if (next == NULL) 
    {
        return SUCCESS;
    }

    // Recursive call to reverse the rest of the list
     reverse_recursive(&next);

    // Update the links to reverse the current node and its next node
    temp->link->link = temp;
    temp->link = NULL;

    *head = next; // Update the head pointer to the new first node

    return SUCCESS;
}