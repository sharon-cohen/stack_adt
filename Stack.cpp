#include <stdlib.h>
#include "stack.h"

/* a structure that represents a generic Stack */
struct Stack_t {
       /* The Stack is implemented as an array of Elements. 
            With nextIndex as an index to the next available position and         
            maximal size stored in maxCapacity.  */
       Element* array;
       int nextIndex;
       int maxCapacity; 
       CopyFunction copyElement;
       FreeFunction freeElement;
};




Stack stackCreate(int maxSize , CopyFunction copyFunction,
		              FreeFunction freeFunction) {
        Stack stack;
  
        if (maxSize <= 0){
               return NULL;
         }
         stack = (Stack) malloc(sizeof(struct Stack_t)) ;
         if (stack == NULL){
               return NULL;
         }
         stack->array = (Element*) malloc(sizeof(Element) * maxSize); 
         if (stack->array == NULL){
               free(stack);
               return NULL;
         }

         stack->nextIndex = 0;
         stack->maxCapacity = maxSize;
         stack->copyElement= copyFunction;
         stack->freeElement = freeFunction;
         return stack;
}
StackResult stackPush(Stack stack, Element element) 
{
	
	if (stack == NULL){
	       return StackBadArgument;
  	}
	 if (stack->nextIndex >= stack->maxCapacity){
	       return StackFull;	
	}


	Element newElement  = stack->copyElement(element);






	if (newElement == NULL) {
	       return StackFail;
	}
 	if(stack->nextIndex >= 0 && stack->nextIndex < stack->maxCapacity)
	{
 		stack->array[stack->nextIndex++] = newElement ;
  		return StackSuccess; 
	}
	return StackFail;
}
StackResult stackPop(Stack stack) {
 	  if (stack == NULL){
    	        return StackBadArgument;
	  }
 	  if (stack->nextIndex < 1){
    	        return StackEmpty;
	  }

 	  if(stack->nextIndex > 0 && stack->nextIndex <= stack->maxCapacity)
	  {
  		  stack->freeElement(stack->array[stack->nextIndex-1]);
		  stack->nextIndex--;
  		  return StackSuccess;
	  }
	  return StackFail;
}
StackResult stackTop(Stack stack, Element* element) 
{
	  if ((stack == NULL) || (element == NULL))
	  {
	        return StackBadArgument;
  	  }
  	  if (stack->nextIndex < 1){
    	        return StackEmpty;
	  }
  	  if(stack->nextIndex > 0 &&  stack->nextIndex <= stack->maxCapacity)
	  {
  		  Element newElement = 
	 		stack->copyElement(stack->array[stack->nextIndex-1]);
		  if (newElement == NULL){
				 return StackFail;
		  }
		 *element = newElement;
  		  return StackSuccess;
	  }
	  return StackFail;
}
StackResult stackSize(Stack stack, int* size) {
        if (stack == NULL || size == NULL){
              return StackBadArgument;
        }
  
        *size = stack->nextIndex;
        return StackSuccess;
}

void stackDestroy(Stack stack) {
	/* empty the stack - free all the elements */
	while (stackPop(stack) == StackSuccess);

	if (stack != NULL){ 
    	      free(stack->array);
              free(stack);
	}
}
