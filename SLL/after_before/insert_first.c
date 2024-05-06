#include "sll.h"

// function to insert at last
int insert_at_first(Slist **head, data_t data)
{
    Slist *new = malloc(sizeof(Slist)); // create a node
    if (new == NULL)                    // error checking (memory allocated or not)
    {
        return FAILURE;
    }

    // update data and link to new node
    new->data = data;
    new->link = NULL;

    // checking if list is empty or not
    if (*head == NULL) // if list is empty
    {
        *head = new;
        return SUCCESS;
    }
    else
    {
        new->link = *head; // head has first node address, so update newlink with head
        *head = new;       // then point new to head
        return SUCCESS;
    }
}