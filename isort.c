#include <stdio.h>
#include "isort.h"
void shift_element(int *arr, int i)
{
    int j = 0;
    int k = i;
    int key = *(arr + i);
    while (j <= i)
    {
        *(arr + k) = *(arr + k - 1);
        k--;
        j++;
    }
    *arr = key;
}

/* Function to sort an array using insertion sort*/
void insertion_sort(int *arr, int len)
{
    int i, key, j;
    for (i = 1; i < len; i++)
    {
        key = *(arr + i);
        j = i - 1;

        while (j >= 0 && *(arr + j) > key)
        {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j + 1) = key;
    }
}
void print_arr(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i != size - 1)
        {
            printf("%d,", *(arr + i));
        }
        else
            printf("%d\n", *(arr + i));
    }
}
