#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Ht_item{
     char *key;
     char *value;
}Ht_item;

int hash(char *key, int m)
{
     int len = strlen(key);
     int hash = 0;

     for (int i = 0; i < len; i++)
     {
          hash = hash + (int) key[i];
     }

     int index = hash % m;
     return index;
}