#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../data-structures/vector.h"

static void vector_grow(vector *vector)
{
	vector->allocatedLength *= 2;
	vector->elements = realloc(vector->elements, vector->elementSize * vector->allocatedLength);
	assert(vector->elements);
}

static void *vector_address(vector *vector, int index)
{
	int addr = vector->elementSize * index;
	return (char *)vector->elements + addr;
}

static void vector_copy_item(vector *vector, int sourceIndex, int destIndex)
{
	void *source = vector_address(vector, sourceIndex);
	void *target = vector_address(vector, destIndex);
	memcpy(target, source, vector->elementSize);
}

void vector_new(vector *vector, int elementSize, freeFunction freeFn)
{
	assert(elementSize > 0);
	vector->elementSize = elementSize;
	vector->logicalLength = 0;
	vector->allocatedLength = 2;
	vector->elements = 	calloc(vector->allocatedLength,vector->elementSize);
	vector->freeFn = freeFn;
}

void vector_destroy(vector *vector)
{
	if(vector->freeFn) {
		int i;
		for(i = 0; i < vector_size(vector); i++) {
			void *target = vector_address(vector,i);
			if(*(int *)target)
			{
			vector->freeFn(target);
			}
		}
	}

	// free main elements
	free(vector->elements);
}

int vector_size(vector *vector)
{
	return vector->allocatedLength;
}

void vector_add(vector *vector, void *element)
{
	if (vector->allocatedLength == vector->logicalLength) {
		vector_grow(vector);
	}

	void *target = vector_address(vector, vector->logicalLength++);
	memcpy(target, element, vector->elementSize);
}

void vector_item_at(vector *vector, int index, void *target)
{
	assert(index >= 0 && index < vector->allocatedLength);

	void *source = vector_address(vector, index);
	memcpy(target, source, vector->elementSize);
}

void vector_insert_at(vector *vector, int index, void *target)
{
	assert(index >= 0 && index <= vector->allocatedLength);
	void *source = vector_address(vector,index);
	if (!*(int *)source)
	{
		memcpy(source,target,vector->elementSize);
	}
}

void vector_remove_at(vector *vector, int index)
{
	assert(index >= 0 && index < vector->logicalLength);

	// remove the item
	void *item = vector_address(vector, index);
	if(vector->freeFn) {
		vector->freeFn(item);
	}

	while(++index < vector->logicalLength) {
		vector_copy_item(vector, index, index - 1);
	}

	vector->logicalLength--;
}
