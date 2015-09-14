#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "implementation/hash_list.c"
#include "data-structures/hash.h"
void delQueue(void *element)
{
  queue_destroy(element);
}
unsigned long hash_f(char *key)
{
  return hash(key)%10;
}
int main(int argc, char const *argv[]) {

  char *key = "juanitoperez";
  int element = 1;
  long a = hash_f(key);
  printf("%lu\n",a );
  /*
  */
  hash_list list;
  hlist_new(&list,sizeof(int),delQueue);
  hlist_append(&list,key,&element,NULL);
  hashNode *nodo = hlist_find(&list,key); // aqui retorna la queue, queue->head->data
  queue *q1 = nodo->data;
  printf("sabpbe\n" );
  printf("%d\n",*(int *)q1->list->head->data);
  hlist_destroy(&list);
  return 0;
}
