#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data) // function to insert at last
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
        (*tail)->next = new; // no need to traverse, bz tail has last node address

        new->prev = *tail; // establishing a link b/w last node and new node
        *tail = new;

        return SUCCESS;
    }
}
