#include "main.h"

/* Function to search the element using binary search */
data_t binarySearch_recursive(data_t *arr, data_t size, data_t key, data_t first, data_t last)
{
    //checking for each recursive call whether low is less than or equal to high or not
    if(first<=last)
    {
        //finding mid position
        data_t mid = (first + last)/2;
        //if middle element is the key then return the mid position
        if(arr[mid] == key)
        {
            return mid;
        }
        //if key is lesser than arr[mid] then update last
        else if(arr[mid] > key)
        {
            last = mid - 1;
        }
        //if key is greater than arr[mid] then update first
        else if(key > arr[mid])
        {
             first = mid + 1;
        }
        //recursive function call
        binarySearch_recursive( arr, size, key, first, last);
    }
    else
    {
        return DATA_NOT_FOUND;
    }
}
