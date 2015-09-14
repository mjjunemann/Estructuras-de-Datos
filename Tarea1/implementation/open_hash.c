#include <stdlib.h>
#include <string.h>
#include <assert.h>


#include "../data-structures/open_hash.h"

static int hashing(open_hash *hash,char *key)
{
  vector *array = hash->array;
  void *target;
  int j = 0;
  int index;
  do
  {
    index = hash->function(key,j,ohash_size(hash));
    printf("index: %d\n",index );
    target = vector_address(array,index);
    printf("target vale:%d\n",*(int *)target );
    j+=1;
  }while(*(int *)target);

  return index;
}
/*
static int hashing(open_hash *hash,char *key)
{
  vector *array = hash->array;
  void *target = NULL;
  int j =0;
  int index;
  printf("hello\n" );
  while(!target || *(int *)target)
  {
    printf("hello\n" );
    index = hash->function(key,j,ohash_size(hash));
    target = vector_address(array,index);
    j+=1;
  }
  return index;
}
*/
static void grow_hash(open_hash *hash)
{
  int i;
  int j;
  vector *array = hash->array;
  int p_size = array->logicalLength;
  array->allocatedLength*=2;
  void *oldElements = array->elements;
  array->elements = calloc(array->allocatedLength,array->elementSize);
  assert(array->elements);
  unsigned long index;
  for(i = 0;i < p_size;i++)
  {
    pedido* tempP = oldElements + i*array->elementSize;
    index = hashing(hash,tempP->key);
    vector_insert_at(array,index,tempP);
  }
}

void ohash_new(open_hash *hash,int elementSize, freeFunction freeElement,hash_function2 hashFun)
{
  hash->array = malloc(sizeof(vector));
  vector_new(hash->array,sizeof(elementSize),freeElement);
  hash->freeElement = freeElement;
  hash->function = hashFun;
}

void ohash_destroy(open_hash *hash)
{
  vector_destroy(hash->array);
  free(hash->array);
}

void ohash_add(open_hash *hash, char *key,void *element)
{
  if (hash->array->allocatedLength == hash->array->logicalLength)
  {
    grow_hash(hash);
  }
  printPedido(element);
  int index = hashing(hash,key);
  vector_insert_at(hash->array,index,element);
}

void * ohash_find(open_hash *hash, char *key) /*this should strcmp(str1,str2)*/
{
  vector *array = hash->array;
  void *target = NULL;
  int count = 0;
  int j = 0;
  int index;
  int result;
  do
  {
    index = hash->function(key,j,ohash_size(hash));
    target = vector_address(array,index);
    if (*(int*)target)
    {
      result = strcmp(((pedido *)target)->key,key);
      if (!result && ((pedido *)target) ->quantity > 0)
      {
        return target;
      }
    }
    else
    {
      return NULL;
    }
    count++;
  }while(count < array->allocatedLength);
}
int ohash_size(open_hash *hash)
{
  return hash->array->allocatedLength;
}
