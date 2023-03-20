#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item {
     int value;
     int weight;
     float ratio;
}Item;

// sort items in descending order by value to weight ratios
void sort(Item items[], int n)
{
     for(int i=0;i<n;i++)
     {
          for(int j = i+1;j<n;j++)
          {
               if(items[i].ratio < items[j].ratio)
               {
                    Item temp = items[i];
                    items[i] = items[j];
                    items[j] = temp;
               }
          }
     }
}

// calculate value to weight ratios for each item
void calculateRatios(Item items[], int n)
{
     for(int i=0; i < n; i++)
     {
          items[i].ratio = (float) items[i].value / items[i].weight;
     }
}

int knapsack(Item items[], int capacity, int n)
{
     int knapsack_weight = 0;
     int knapsack_value = 0;

     // loop through sorted items and add them to knapsack one by one
     for(int i =0; i< n; i++)
     {
          // check if sum of current knapsack weight and current item weight exceeds knapsack capacity
          if(knapsack_weight + items[i].weight >= capacity){
               break;
          }
          
          knapsack_weight += items[i].weight;
               knapsack_value += items[i].value;
     }

     return knapsack_value;
}


int main()
{
     Item items[] = {{10,2,0},{5,3,0},{15,5,0},{7,7,0},{6,1,0},{18,4,0},{3,1,0}};
     int capacity = 15;
     int noOfItems = sizeof(items)/sizeof(Item);
     
     
     calculateRatios(items, noOfItems);
     sort(items, noOfItems);
     int knapsackValue = knapsack(items, capacity, noOfItems);

     printf("knapsack value: %d\n", knapsackValue);

     return 0;
}