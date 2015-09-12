#ifndef __HASHLIST_H
#define __HASHLIST_H

#include "common.h"
#include "../implementation/queue.c"
#include "../implementation/list.c"

typedef struct _hashNode
{
  char *key;
  void *data;
  struct _hashNode *next;
} hashNode;


typedef struct _hashList
{
  int logicalLength;
  int elementSize;
  hashNode *head;
  hashNode *tail;
  freeFunction freeFn;

}hash_list;

void hlist_new(hash_list *list, int elementSize, freeFunction freeFn);
void hlist_destroy(hash_list *list);

void hlist_append(hash_list *list,char *key,void *element,freeFunction freeElement);
hashNode *hlist_find(hash_list *list, char *key);
int hlist_size(hash_list *list);


#endif
