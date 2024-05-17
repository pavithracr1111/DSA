#include "sll.h"

int sorted_merge(Slist **head1, Slist **head2)
{
    if (*head1 == NULL && *head2 == NULL)
    {
        return LIST_EMPTY;
    }
    else if (*head2 == NULL && *head1 != NULL)
    {
        if (sort(head1) == SUCCESS)
        {
            return SUCCESS;
        }
        return FAILURE;
    }
    else if (*head1 == NULL && *head2 != NULL)
    {
        *head1 = *head2;
        if (sort(head1) == SUCCESS)
        {
            return SUCCESS;
        }
        return FAILURE;
    }
    else
    {
        Slist *temp = *head1;
        while (temp->link != NULL)
        {
            temp = temp->link;
        }
        temp->link = *head2;
        if (sort(head1) == SUCCESS)
        {
            return SUCCESS;
        }
        return FAILURE;
    }
}