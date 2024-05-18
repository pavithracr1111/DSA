#include "main.h"

/* Function for binary search using iterations */
data_t binarySearch_iterative(data_t *arr, data_t size, data_t key)
{
    int high,low=0,mid;
    high = size - 1;
    //run a loop untill it reaches false condition
    while(low <= high)
    {
        //calculate mid first
        mid = (low + high) / 2;
        //check if key element is found at middle position
        if(arr[mid] == key)
        {
            return mid;
        }
        //if arr[mid] is greater than the key then update high
        else if( arr[mid] > key )
        {
            high = mid -1;
        }
        //if arr[mid] is lesser than the key then update low
        else if(arr[mid] < key) 
        {
            low = mid + 1;
        }
    }
    return DATA_NOT_FOUND;
    
}
