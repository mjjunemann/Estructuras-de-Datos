#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "implementation/hash_list.c"



void freeList(void *list)
{
    hlist_destroy(list);
}
void freeQueue(void *queue)
{
  queue_destroy(queue);
}
typedef struct Pedido
{
  char* key;
  char* name;
  int quantity;
}pedido;

void init_pedido(pedido *p, char *key,char *name, int quantity)
{
  p->key = strdup(key);
  p->name = strdup(name);
  p->quantity = quantity;
}


void freeOrder(void *p)
{
  pedido *current;
  current = p;
  free(current->key);
  free(current->name);
}
printOrder(pedido *p)
{
  printf("%s\n",p->key );
  printf("%s\n",p->name );
  printf("%d\n",p->quantity);
}

int main(int argc, char const *argv[]) {

  pedido p;
  hash_list list;
  int i;
//  ### INIT EXITOSO ###
  char *key = "Pepperoni";
  char *name = "Juanito";
//  ##### CREAR HLIST ####
  hlist_new(&list,sizeof(pedido),freeQueue);
  for (i =0 ;i < 10; i++)
  {
  init_pedido(&p,key,name,i);
  hlist_append(&list,key,&p,freeOrder);
  }
  hashNode *node = hlist_find(&list,key);
  pedido *pe = ((queue *)node->data)->list->head->data;
  pedido *pe2 = ((queue *)node->data)->list->head->next->data;
  printOrder(pe);
  printOrder(pe2);

//  printOrder(&p);
  hlist_destroy(&list);
  freeOrder(&p);

  return 0;
}
