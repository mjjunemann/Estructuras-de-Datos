#ifndef __OPENHASH_H
#define __OPENHASH_H

#include "../implementation/vector.c"
#include "common.h"
#include "../implementation/hash_list.c"
#include "hash.h"


typedef struct open_hash
{
  vector *array;
  freeFunction freeElement;
  hash_function2 function;
}open_hash;

void ohash_new(open_hash *hash,int elementSize, freeFunction freeElement,hash_function2 hashFun);
void ohash_destroy(open_hash *hash);
void ohash_add(open_hash *hash,char *key,void *element);
void ohash_del(open_hash *hash,char *key);
void *ohash_find(open_hash *hash,char *key);
int ohash_size(open_hash *hash);

#endif
