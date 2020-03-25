#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "stack.h"

#define MAX_INPUT_SIZE 100
#define UNDO_LAST_COMMAND  -1

/* functions that will be used by the ADT */
Element copyInt(Element element) 
{
	int* newInt;
	if (element == NULL) 
	       return NULL;

	newInt = (int*) malloc(sizeof(int));
	*newInt = *(int*)element;
	return newInt;
}

void freeInt(Element element) 
{
	free (element);
}

int main()
{
      Stack stack;

	  Element* element = (Element*)malloc(sizeof(Element));
      StackResult stackResult;

      int lastNumber, size = 0;
      
  
      stack = stackCreate(MAX_INPUT_SIZE, copyInt, freeInt);
      if (stack == NULL)
	  {
             fprintf(stderr,"failed to create stack\n");
           return -1;
      }
		int i = 1;
		int j = 7;
		int k = 8;

		stackPush(stack, &i);
		stackPush(stack, &j);
		stackPush(stack, &k);

	  while ( stackTop(stack,element)== StackSuccess)
	  {
		Element elem = (*element);

		printf("CurrElement is : %d\n", *((int*)elem) ); //(*(*element)));
		stackPop(stack)
		/* empty while body */ ;
	  }
	  return 1;
}
 