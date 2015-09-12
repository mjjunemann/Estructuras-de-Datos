#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "list.c"


int main(int argc, char const *argv[]) {
  list l;
  list_new(&l,sizeof(int),NULL);
  int i;
  int numItems = 10;
  for(i = 0; i < numItems; i++)
  {
  printf("%d\n",i );
  list_append(&l, &i);
  }
  listNode *node = l.head;
  printf("%d\n", *(int *)(l.head->data) );
  int *node_value;
  node_value = l.head->data;
  printf("%d\n",(node_value) );
  printf("%d\n",*(node_value) );



  list_destroy(&l);
  return 0;
}
