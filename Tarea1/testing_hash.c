#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "data-structures/hash.h"
#include "data-structures/vector.h"
#include "implementation/close_hashing.c"


typedef struct Pedido
{
  char* key;
  char *name;
  int quantity;
}pedido;
void init_pedido(pedido *p, char *key, char *name,int quantity)
{
  p->key = strdup(key);
  p->name = strdup(name);
  p->quantity = quantity;
}
void freeOrder(void *p)
{
  pedido * current;
  current = p;
  free(current->name);
  free(current->key);
}
void printPedido(pedido *p)
{
  printf("%s\n", p->key);
  printf("%s\n", p->name);
  printf("%d\n", p->quantity);

}
unsigned long hash_f(char *key, int size )
{
  return hash(key)%size;
}
void delQueue(void *element)
{
  queue_destroy(element);
}
int main(int argc, char const *argv[]) {

  close_hash hash;
  char *key = "Pepperoni";
  char *name = "Juanito";
  int quantity = 5;
  pedido p;
  init_pedido(&p,key,name,quantity);
  printPedido(&p);
  hash_new(&hash,sizeof(pedido),freeOrder,delQueue,hash_f);
  hash_destroy(&hash);
  freeOrder(&p);
  printf("hello\n" );


  return 0;
}
