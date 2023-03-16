#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Item
{
     int value;
     int weight;
     float ratio;
} Item;

// sort items in descending order by value to weight ratios
void sort(Item items[], int n)
{
     for (int i = 0; i < n; i++)
     {
          for (int j = i + 1; j < n; j++)
          {
               if (items[i].ratio < items[j].ratio)
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
     for (int i = 0; i < n; i++)
     {
          items[i].ratio = (float)items[i].value / items[i].weight;
     }
}

float fractionalKnapsack(Item items[], int capacity, int n)
{
     float knapsack_value = 0.0;
     int remaining_capacity = capacity;

     // loop through sorted items and add them to knapsack one by one
     for (int i = 0; i < n; i++)
     {
          // check if knapsack is full
          if (remaining_capacity == 0)
          {
               break;
          }
          // add fractional value of item if weight of item exceeds the remaining capacity
          else if (items[i].weight > remaining_capacity)
          {
               float fractional_value = (float)(remaining_capacity / items[i].weight) * items[i].value;
               knapsack_value += fractional_value;
               remaining_capacity = 0;
          }
          // add full value if otherwise
          else
          {
               remaining_capacity -= items[i].weight;
               knapsack_value += items[i].value;
          }
     }

     return knapsack_value;
}

int main()
{
     Item items[] = {{10, 2, 0}, {5, 3, 0}, {15, 5, 0}, {7, 7, 0}, {6, 1, 0}, {18, 4, 0}, {3, 1, 0}};
     int capacity = 15;
     int noOfItems = sizeof(items) / sizeof(Item);

     calculateRatios(items, noOfItems);
     sort(items, noOfItems);
     float knapsackValue = fractionalKnapsack(items, capacity, noOfItems);

     printf("knapsack value: %f\n", knapsackValue);
     return 0;
}