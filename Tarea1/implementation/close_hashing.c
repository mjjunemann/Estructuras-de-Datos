#include <stdlib.h>
#include <string.h>
#include <assert.h>


#include "../data-structures/close_hashing.h"
#include "../data-structures/vector.h"



static void freeList(void *list)
{
  hlist_destroy(list);
}
void hash_new(close_hash *hash,int elementSize,freeFunction freeElement,freeFunction freeQueue, hash_function hashFun)
{
  hash -> array = malloc(sizeof(vector));
  vector_new(hash->array,sizeof(hash_list),freeList); /*aqui deberia entregar la funcion que destruye a las hash list */
  hash -> elementSize;
  hash -> SecondList = freeQueue;
  hash -> freeElement = freeElement;
  hash -> function = hashFun;
}


void hash_destroy(close_hash *hash)
{
  vector_destroy(hash->array);
}

void hash_add(close_hash *hash,char *key, void *element)
{
  /*aqui veo si existe una lista en la direccion de memoria que hashea la key
    , luego de crear/buscar la lista debo aplicar append a la lista que se encuentra
     en esa direccion*/
  unsigned long index = hash->function(key,hash_size(hash));
  void *target = vector_address(hash->array,index);
  if (!target)
  {
    hash_list hlist;
    hlist_new(&hlist,sizeof(queue),hash->SecondList);
    hlist_append(&hlist,key,element,hash->freeElement);
    vector_insert_at(hash->array,index,&hlist);
    return;
  }
  else
  {/*saca el la lista que se encuentra en la posicion index y luego le agrega el elemento*/
  hash_list nodeList;
  vector_item_at(hash->array,index,&nodeList);
  hlist_append(&nodeList,key,element,hash->freeElement);
  return;
}
}

hashNode hash_find (close_hash *hash, void *element, char *key)
{

}


int hash_size(close_hash *hash)
{
  return hash->array->allocatedLength;
}
