#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "implementation/list.c"
#include "implementation/vector.c" // arreglos
#include "implementation/queue.c" // colas

void freeList(void *list)
{
    list_destroy(list);
}
void freeQueue(void *queue)
{
  queue_destroy(queue);
}
typedef struct Pedido
{
  char* key;
  int quantity;
}pedido;
void init_pedido(pedido *p, char *key, int quantity)
{
  p->key = strdup(key);
  p->quantity = quantity;
}
void freeOrder(void *p)
{
  pedido * current;
  current = p;
  free(current->key);
}
int main(int argc, char* argv[])
{
    vector v;
    vector_new(&v,sizeof(list),freeList); // crea un array que los tamaños de objetos son de tamaño lista
    int i;
    int numberOflist = 10;
    int j;
    int k;
    list l;
    queue q;
    pedido p;
    char *key = "pepito";
    for(j=0;j < numberOflist; j++)
    {
      list_new(&l,sizeof(queue),freeQueue);
      queue_new(&q,sizeof(pedido),freeOrder);
      init_pedido(&p,key,10);
      queue_enqueue(&q,&p);
      list_append(&l,&q); // agregar una queue a una lista
      vector_add(&v,&l); //
    }
    list target;
    vector_item_at(&v,1,&target); // en la direccion de target carga la posicion 7 del array que es una lista
    listNode* node = target.head; // esto me retorna el nodo cabeza de la lista
    queue* keke = target.head->data;
    listNode* nodoQ = keke->list->head;
    pedido* pedido1 = nodoQ->data;
    printf("%d\n",(int)pedido1->quantity );
    printf("%s\n",(char *)pedido1->key );




    vector_destroy(&v);
    return 0;
}
