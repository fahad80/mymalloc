/*
*****************************************************************************

  File        : main.cpp

  The MIT License (MIT)
  Copyright (c) 2018 STMicroelectronics

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

*****************************************************************************
*/

#include<stdio.h>
#include"mymalloc.h"

int main(void)
{
	int *test = (int *)Mymalloc(sizeof(int));
	int *test2 = (int *)Mymalloc(sizeof(int));
	int *test3 = (int *)Mymalloc(248);

	if(test3 == NULL)
	{
		printf("Test3: Not enough space\n");
	}

	printf("Address of test = %p\n", test);
	printf("Address of test = %p\n", test2);
	printf("Address of test = %p\n", test3);


	int *test4 = (int *)Mymalloc(0);

	if(test4 == NULL)
	{
		printf("Test4: Not enough space\n");
	}


	fflush(stdout);

	return 0;
}
