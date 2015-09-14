#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>


#include "data-structures/hash.h"
#include "data-structures/vector.h"
#include "implementation/close_hashing.c"


//typedef void ready_pizza(close_hash *hash)


unsigned long hash_f(char *key, int size )
{
  return hash(key)%size;
}
void delQueue(void *element)
{
  queue_destroy(element);
}
void ready_pizza(close_hash *hash, char *key)
{
  hashNode *node = hash_find(hash,key);
  queue *q = node->data;
  pedido *p = q->list->head->data;
  printPedido(p);
}
int main(int argc, char const *argv[]) {

  close_hash hash;
  char *key = "Pepperoni";
  char *name = "Juanito";
  char *key2 = "Jamon";
  char *name2 = "Charles";
  int quantity = 5;
  pedido p;
  init_pedido(&p,key,name,quantity);
  printPedido(&p);
  hash_new(&hash,sizeof(pedido),freeOrder,delQueue,hash_f);
  hash_add(&hash,key,&p);
  init_pedido(&p,key,name2,quantity);
  hash_add(&hash,key,&p);
  // Agregar un assert para no imprimir cosas nulas
  hashNode *node = hash_find(&hash,key);
  queue *q = node->data;
  pedido *p2 = q->list->head->data;
  printPedido(p2);
  //ready_pizza(&hash,key);
  //ready_pizza(&hash,key);
  //ready_pizza(&hash,key);


//  ready_pizza(&hash,key2);
  /*
  */
  //hashNode *node = hash_find(&hash,key);
  //pedido *pe = ((queue *)node->data)->list->head->data;
  //printPedido(&p);
  hash_destroy(&hash);
  //freeOrder(&p);


  return 0;
}
