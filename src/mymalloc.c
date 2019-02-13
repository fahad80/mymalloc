/*
 * mymalloc.c
 *
 *  Created on: Feb 12, 2019
 *      Author: FahadMirza
 */
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define HEAP_SIZE (256U)

static uint8_t heap_space[HEAP_SIZE + 1];

static uint8_t *topOfHeap = heap_space;
static int availableHeapSize = HEAP_SIZE;

typedef struct sBlockMeta
{
	struct sBlockMeta *next;
	int size;
	bool free;
}sBlockMeta_t;

static sBlockMeta_t *Head = NULL;

#define META_SIZE sizeof(sBlockMeta_t)


/********************* Private Function Declarations *********************/
static sBlockMeta_t * requestSpace(size_t size);
static sBlockMeta_t * findFreeSpace(sBlockMeta_t **last, size_t size);


/********************* Function Definitions *********************/
void * Mymalloc(size_t size)
{
	printf("Available size prev: %d\n", availableHeapSize);
	printf("topOfHeap add prev: %p\n", topOfHeap);
	sBlockMeta_t *last;
	sBlockMeta_t *ptr = findFreeSpace(&last, size);

	if(ptr == NULL)
	{
		ptr = requestSpace(size);
		if(ptr == NULL)
		{
			return NULL;
		}
	}
	else
	{
		ptr->free = false;
	}

	if(Head == NULL)
	{
		Head = ptr;
	}
	else
	{
		last->next = ptr;
	}


	printf("Available size cur: %d\n", availableHeapSize);
	printf("topOfHeap add cur: %p\r\n", topOfHeap);


	// As last is sBlockMeta_t type, incrementing by one will
	// point to the address after META_SIZE
	ptr++;

	return ((void *)ptr);
}

static sBlockMeta_t * findFreeSpace(sBlockMeta_t **last, size_t size)
{
	sBlockMeta_t *current = Head;

	while(current != NULL && !(current->free == true && current->size >= size))
	{
		*last = current;
		current = current->next;
	}

	return current;
}

static sBlockMeta_t * requestSpace(size_t size)
{
	if(size > availableHeapSize || size <= 0)
	{
		return NULL;
	}
	availableHeapSize -= (size + META_SIZE);
	sBlockMeta_t *prevTop = (sBlockMeta_t *)topOfHeap;
	topOfHeap = (topOfHeap + size + META_SIZE);

	prevTop->free = false;
	prevTop->next = NULL;
	prevTop->size = size;

	return prevTop;
}


void free(void *ptr)
{
	if(ptr == NULL)
	{
		return;
	}

	sBlockMeta_t *blockPtr = (sBlockMeta_t *)ptr - 1;
	blockPtr->free = true;

}
