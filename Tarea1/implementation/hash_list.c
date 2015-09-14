#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "../data-structures/hash_list.h"

void hlist_new(hash_list *list,int elementSize,freeFunction freeFn)
{
  assert(elementSize > 0);
  list-> logicalLength = 0;
  list-> elementSize = elementSize;
  list-> head = list->tail = NULL;
  list-> freeFn = freeFn;
}

void hlist_destroy(hash_list *list)
{
  hashNode *current;
  while(list->head != NULL)
  {
    current = list->head;
    list->head = current->next;
    if(list->freeFn)
    {
      list->freeFn(current->data);
    }
    free(current->data);
    free(current->key);
    free(current);
  }
}
void hlist_append(hash_list *list, char *key,void *element,freeFunction freeElement)
{
  /*buscar si el nodo existe en caso de retornar, caso contrario agregar*/
  hashNode *node = hlist_find(list,key);
  if (!node)
  {
    /*si no existe el nodo crealo, y luego agregale el elemento en este caso una queue */
    node = malloc(sizeof(hashNode));
    node ->key = strdup(key);
    node ->data = malloc(sizeof(queue));
    queue q;
    queue_new(&q,list->elementSize,freeElement);
    queue_enqueue(&q,element);
    memcpy(node->data,&q,sizeof(queue));

    //printf("%d\n",*(int *)((queue *)node->data)->list->head->data );
  /*en caso de existir el nodo agrego el struct pedido en la lista*/
    if(list->logicalLength == 0)
    {
  		list->head = list->tail = node;
  	}
    else
    {
  		list->tail->next = node;
  		list->tail = node;
  	}
    /*
    if (!strcmp(node->key,key))
    {
      printf("entre\n");
      hashNode *node = hlist_find(list,key);
      printf("%s\n",node->key );
      queue *q2 = node->data;
      printf("%d\n",*(int *)q2->list->head->data );
    }
     */
  }
  else
  {
    queue_enqueue((queue *)node->data,element);
  }

  list->logicalLength++;
}

hashNode *hlist_find(hash_list *list, char *key)// retornar la lista
{
  /*retorna el puntero al nodo que estamos buscando*/
  hashNode *current = list->head;


  while(current != NULL)
  {
    if (!strcmp(current->key,key))
    {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

int hlist_size(hash_list *list)
{
  return list->logicalLength;
}
