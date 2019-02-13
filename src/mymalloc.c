/*
 * mymalloc.c
 *
 *  Created on: Feb 12, 2019
 *      Author: FahadMirza
 */
#include <stdio.h>
#include <stdint.h>

#define HEAP_SIZE (256U)

static uint8_t heap_space[HEAP_SIZE + 1];

static uint8_t *topOfHeap = heap_space;
static int availableHeapSize = HEAP_SIZE;

void * mymalloc(size_t size)
{
	printf("Available size prev: %d\n", availableHeapSize);
	printf("topOfHeap add prev: %p\n", topOfHeap);

	if(size > availableHeapSize)
	{
		return NULL;
	}

	availableHeapSize -= size;
	uint8_t* last = topOfHeap;
	topOfHeap = (topOfHeap + size);

	printf("Available size cur: %d\n", availableHeapSize);
	printf("topOfHeap add cur: %p\r\n", topOfHeap);

	return ((void *)last);
}
