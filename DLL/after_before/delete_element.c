#include "dll.h"

int dl_delete_element(Dlist **head, Dlist **tail, int data)
{	
    Dlist *temp = *head;
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    if(*head == *tail)
    {
        *head = *tail = NULL;
        free(temp);
        return SUCCESS;
    }
    else
    {
        while(temp != NULL)
        {
            if(temp -> data == data)
            {
                temp -> prev -> next = temp -> next;
                temp -> next = temp -> prev;
                free(temp);
            }
            temp = temp -> next;
        }
        return SUCCESS;
    }
    return DATA_NOT_FOUND;
}