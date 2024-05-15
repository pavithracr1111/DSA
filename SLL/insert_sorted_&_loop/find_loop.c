#include "sll.h"

/* Function for finding the loop in the link */
int find_loop(Slist *head)
{
    Slist *fast = head;
    Slist *slow = head;
    if(head == NULL)
    {
        return LIST_EMPTY;
    }
    while((fast != NULL) && (fast->link != NULL))
    {
        fast = fast -> link -> link;
        slow = slow -> link;
        if(fast == slow)
        {
            return SUCCESS;
        }
    }
    return LOOP_NOT_FOUND;
}