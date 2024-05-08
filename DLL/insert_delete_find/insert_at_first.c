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
        new->next = new; 

        (*head)->prev = *tail; // establishing a link b/w last node and new node
        *head = new;

        return SUCCESS;
    }
}
