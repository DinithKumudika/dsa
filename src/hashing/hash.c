#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "includes/hash.h"

#define TABLE_SIZE 9

char *hashTable[TABLE_SIZE];

void insert(char *key)
{
     int index = hash(key, TABLE_SIZE);
     hashTable[index] = key;
     printf("%s is at index %d\n", key, index);
}

void search(char *key)
{
     int index = hash(key, TABLE_SIZE);
     int i = 0;
     int found = 0;

     while(i < TABLE_SIZE)
     {
          if(hashTable[index] == key){
               printf("%s found at %d\n", key, index);
               found = 1;
               break;
          }
          i++;
     }

     if(found == 0)
     {
          printf("%s is not in the table\n", key);
     }
}

int main()
{
     insert("paul");
     insert("arthur");
     insert("jane");
     insert("john");

     printf("\n<-- hash table -->\n");

     for (int i = 0; i < TABLE_SIZE; i++)
     {
          if (hashTable[i] == NULL)
          {
               printf("%s\n", "null");
          }
          else
          {
               printf("%s\n", hashTable[i]);
          }
     }

     printf("\n");

     search("mary");
     search("arthur");

     return 0;
}
