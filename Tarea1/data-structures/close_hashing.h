#ifndef __CLOSEHASH_H
#define __CLOSEHASH_H


#include "../implementation/vector.c"
#include "common.h"
#include "../implementation/hash_list.c"
#include "hash.h"


typedef struct close_hash
{
  vector *array;
  int elementSize;
  freeFunction SecondList;
  freeFunction freeElement;
  hash_function function;
}close_hash;




void hash_new(close_hash *hash,int elementSize,freeFunction freeElement,freeFunction freeQueue,hash_function hashFun);
void hash_destroy(close_hash *hash);
void hash_add(close_hash *hash,char *key, void *element);
void hash_del(close_hash *hash,char *key);
hashNode *hash_find(close_hash *hash,char *key);
int hash_size(close_hash *hash);


#endif
