#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linearSearch(int arr[], int element, int n)
{
     for (int i = 0; i < n; i++)
     {
          if (arr[i] == element)
          {
               printf("%d is at index %d", element, i);
               return 1;
          }
     }
     return 0;
}

int main()
{
     int arr[] = {5, 2, 8, 7, 45, 12, 6, 3};
     int n = sizeof(arr) / sizeof(arr[0]);
     int element;

     printf("Elements to be searched: ");
     scanf("%d", &element);

     int res = linearSearch(arr, element, n);
     
     if (res == 0)
     {
          printf("%d is not in the array", element);
     }
     return 0;
}