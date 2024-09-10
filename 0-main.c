#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    int myarray[] = {2, 4, 6, 8, 10, 12, 14, 16, 20, 17};
    size_t n2 = sizeof(myarray) / sizeof(myarray[0]);

    print_array(array, n);
    printf("\n");
    bubble_sort(array, n);
    printf("\n");
    print_array(array, n);

    print_array(myarray, n2);
    printf("\n");
    bubble_sort(myarray, n2);
    printf("\n");
    print_array(myarray, n2);
    return (0);
}
