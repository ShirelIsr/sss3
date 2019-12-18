#include <stdio.h>
#include "isort.h"

int main()
{
    int arr[SIZE] = {0};
    printf("Pleas enter the a numbers :\n");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", (arr + i));
    }
    printf("before sort\n");
    print_arr(arr, SIZE);
    insertion_sort(arr, SIZE);
    printf("after sort\n");
    print_arr(arr, SIZE);

    int sort_arr[SIZE] = {0};
    int *t = &sort_arr[5];
     printf("Pleas enter the a numbers :\n");
    for (int i = 0; i < SIZE; i++)
    {
        scanf("%d", (sort_arr + i));
    }
    printf("befor shift the fifth element\n");
    print_arr(sort_arr, SIZE);
    shift_element(t, 2);
    printf("after shift the fifth element\n");
    print_arr(sort_arr, SIZE);
    return 0;
}