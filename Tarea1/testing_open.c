#include <stdio.h>
#include <string.h>
#include <assert.h>


#include "implementation/open_hash.c"

unsigned long hashFun(char *key,int index,int size)
{
  return (hash(key) + index)%size;
}


int main(int argc, char const *argv[]) {
  pedido p;
  open_hash hash;

  char *name = "William";
  char *key = "Pepperoni";
  int quantity = 10;
  init_pedido(&p,key,name,quantity);
  printPedido(&p);
  ohash_new(&hash,sizeof(pedido),freeOrder,hashFun);
  printf("el numero de hash es; %d\n",(int)hashFun(key,1,10) );
  ohash_add(&hash,key,&p);
  pedido *target = ohash_find(&hash,key);
  ohash_destroy(&hash);
  freeOrder(&p);

  return 0;
}
