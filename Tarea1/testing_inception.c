#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#include "implementation/list.c"
#include "implementation/vector.c" // arreglos

void freeList(void *list)
{
    list_destroy(list);
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

    for(j=0;j < numberOflist; j++)
    {
      list_new(&l,sizeof(int),NULL);
      for(i=0;i < 10; i++)
      {
        k = i*j;
        list_append(&l,&k); //
      }
      vector_add(&v,&l); //
    }
    list target;
    vector_item_at(&v,7,&target); // en la direccion de target carga la posicion 7 del array que es una lista
    listNode* node = target.head;
    printf("%d\n",*(int *)node->data );
    *(int)node ->data = 4;
    vector_item_at(&v,7,&target); // en la direccion de target carga la posicion 7 del array que es una lista
    printf("%d\n",*(int *)target.head->data );


    vector_destroy(&v);
    return 0;
}
