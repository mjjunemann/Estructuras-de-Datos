#ifndef __CDS_COMMON_H
#define __CDS_COMMON_H
// a common function used to free malloc'd objects
typedef void (*freeFunction)(void *);
// boolean doesn't exist...seriously...
typedef enum { FALSE, TRUE } bool;

typedef unsigned long  (*hash_function)(char *,int );
typedef unsigned long  (*hash_function2)(char *,int,int );

typedef struct Pedido
{
  char* key;
  char *name;
  int quantity;
}pedido;

void printPedido(pedido *p)
{
  printf("%s\n", p->key);
  printf("%s\n", p->name);
  printf("%d\n", p->quantity);
}
void freeOrder(void *p)
{
  pedido * current;
  current = p;
  free(current->name);
  free(current->key);
}
void init_pedido(pedido *p, char *key, char *name,int quantity)
{
  p->name = strdup(name);
  p->key = strdup(key);
  p->quantity = quantity;
}
#endif
