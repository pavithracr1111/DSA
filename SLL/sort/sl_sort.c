#include "sll.h"

int sl_sort(Slist **head)
{
    if(*head == NULL)
    {
        return LIST_EMPTY;
    }
    if((*head)->link == NULL)
    {
        return SUCCESS;
    }
    Slist *temp = *head;
    int count = 0; 
    while(temp != NULL)
    {
        temp = temp -> link;
        count++;
    }
    Slist * prev =NULL;
    Slist *slow = *head;
    Slist *fast = slow -> link;
    for(int i = 0; i < count; i++)
    {
        prev = NULL;
        slow = *head;
        fast = slow -> link;
        
        for(int j = 0; j < (count -1-i); j++)
        {
            if(slow->data > fast->data)
            {
                if(prev == NULL)
                {
                    slow->link = fast->link;
                    fast -> link = slow;
                    *head = fast;
                }
                else
                {
                    prev->link = fast;
                    slow -> link =fast->link;
                    fast->link = slow;
                }
                prev = fast;
                fast = slow->link;
            }
            else
            {
                prev = slow;
                slow = fast;
                fast = fast -> link;
            }
        }
    }
    return SUCCESS;
    

}