#include "dll.h"

int dl_insert_first(Dlist **head, Dlist **tail, int data) // function to insert at first
{
    Dlist *new = malloc(sizeof(Dlist)); // create a node
    if (new == NULL)                    // error checking (memory allocated or not)
    {
        return FAILURE;
    }

    // update data and link to new node
    new->prev = NULL;
    new->data = data;
    new->next = NULL;

    // checking if list is empty or not
    if (*head == NULL) // if list is empty
    {
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else // if list is non empty
    {
        // If list is not empty
        new->next = *head;       // Update the next pointer of the new node to point to the current head
        (*head)->prev = new;     // Update the prev pointer of the current head to point to the new node
        *head = new;             // Update the head pointer to point to the new node
        return SUCCESS; 
    }
}
