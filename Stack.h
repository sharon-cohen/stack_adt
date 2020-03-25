#ifndef _STACK_H
#define _STACK_H

/* generic ADT of Stack of integers */
typedef struct Stack_t* Stack ;

typedef void*  Element;

typedef Element (*CopyFunction)(Element);
typedef void  (*FreeFunction)(Element);




/* possible return values */
typedef enum 
{ 
	StackBadArgument, 
	StackSuccess, 
	StackFail, 
	StackEmpty, 
	StackFull 
} StackResult ;








 /*  Creates a Stack with maximal capacity of 'maxSize'.  
       If fails, returns NULL */
Stack stackCreate(int maxSize, CopyFunction toto,
			    FreeFunction fofo);







/*  releases the memory allocated for the stack */
void stackDestroy(Stack stack);







/*  insert an element to the top of the stack.
     Error Codes: StackBadArgument if stack is NULL
                            StackFull if the stack is full. */
StackResult stackPush(Stack stack, Element mm);










/*  removes the element at the top of the stack. 
      Error codes: StackBadArgument if stack is NULL
                             StackEmpty if the stack is empty  */
StackResult stackPop(Stack stack);







/*  returns in the ‘element’ the last element that was pushed.
     Error codes: StackBadArgument if stack or element are NULL
                           StackEmpty if the stack is empty */
StackResult stackTop(Stack stack, Element* element); 







/*  returns the number of elements in the stack.
      Error codes: StackBadArgument if stack or size are NULL */
StackResult stackSize(Stack stack, int* size);





#endif
