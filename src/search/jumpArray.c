#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int jumpSearch(int arr[], int element, int n)
{
     
}

int main ()
{
     int arr[] = {0,1,2,5,8,10,12,15,21,34,55,89,145,232,376,681};
     int n = sizeof(arr) / sizeof(arr[0]);
     int element;

     printf("Elements to be searched: ");
     scanf("%d", &element);

     jumpSearch(arr, element, n);

     return 0;
}