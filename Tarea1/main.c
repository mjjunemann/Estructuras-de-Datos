#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "implementation/list.c"
#include "implementation/vector.c"
#include "implementation/queue.c"
void freeList(void *list)
{
		list_destroy(list);
}
int main(int argc, const char *argv[])
{
	vector v;
	vector_new(&v,sizeof(list),freeList);
	printf("hello\n");
	list l;
	int i;
	list_new(&l,sizeof(int),NULL);
	for(i=0;i < 10;i++)
	{

		list_append(&l,&i);
	}
		vector_add(&v,&l);
		list target;
		vector_item_at(&v,0,&target);
		listNode *node = target.head;
		printf("world\n" );
		printf("%d",*(int *)node->data);


		vector_destroy(&v);
		//list_destroy(&l);
	return 0;
}
