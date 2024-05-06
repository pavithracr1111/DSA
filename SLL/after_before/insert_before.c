#include "sll.h"

int sl_insert_before(Slist **head, data_t g_data, data_t ndata) // function to insert before a given node
{
    if(head == NULL)
    {
        return LIST_EMPTY;
    }
    else
    {
       Slist *temp = *head;
       Slist *prev = NULL;
       
       while(temp != NULL)
       {
        if(temp->data != g_data)
        {
            prev=temp;
            temp=temp->link;
        }
        else
        {
            Slist *new=malloc(sizeof(Slist));
            if(new==NULL)
            {
                return FAILURE;
            }

            new->data=ndata;
            new->link=prev->link;
            prev->link=new;
            return SUCCESS;
        }
       }
return DATA_NOT_FOUND;
    
    }
}