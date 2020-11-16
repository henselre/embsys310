// Assignment 4 Problem 3
// build and test a stack
// R. Hensel 11-15-20

#include "stack.h"
#define STACK_SIZE 5

// Backing store
int StackStore[STACK_SIZE];

// Pointers to stack elements
int* pushPtr;
int* popPtr;

// LIFO Stack is Empty if pushPtr == popPtr;
// LIFO Stack is Full if popkPtr == Address of highest element in the stack;

// Initialize internals of the stack
void stack_init(void)
{
    pushPtr = 0;
    popPtr = 0;
    for(int i=0; i<STACK_SIZE; i++)
    {
        StackStore[i] = 0;
    }
}

// Add data to stack
// If stack is full return error
// Otherwise return success
int stack_push(int data)
{
    if (popPtr == &StackStore[STACK_SIZE-1])
    {
        // stack is full
        return 1;
    }
    
    //if (popPtr > pushPtr) || popPtr > &StackStore[STACK_SIZE-1])
    //{
        //push pointer should never be lower than pop pointer
        //pop pointer should never be higher than top of stack
     //   return -1;
    //}
    
    if (popPtr == 0)
    {
        popPtr = &StackStore[0];
    }    
    
    if (pushPtr == 0)     
    {
        pushPtr = &StackStore[0];       
    }

    *pushPtr = data;

    if (pushPtr != &StackStore[0] && popPtr != &StackStore[STACK_SIZE-1])     /* only increment pop pointer if stack has more than one element and stack is not full*/
    {
         popPtr++;
    }
    if (pushPtr != &StackStore[STACK_SIZE-1])     /* only increment push pointer if stack is not full*/
    {
         pushPtr++;
    }
  
    return 0;
}

// Pop data from stack
// If stack is empty return error
// Otherwise return success
int stack_pop(int* data)
{   
    if (popPtr == 0)
    {
        // stack is empty
        return 1;
    }

    *data = *popPtr;   // load the data regsiter with the popped value
    *popPtr = 0;       // clear the popped stack register
    
    if (popPtr != &StackStore[STACK_SIZE-1] && pushPtr != &StackStore[0])
    {
    // decrement push pointer only if stack is not full prior to pop or stack had only one element prior to pop
        pushPtr--;
    }
    if (popPtr != &StackStore[0])
    {
        //only decrement pop pointer if stack has more than one element
        popPtr--;
    }
    else
    {
        // stack had one element prior to pop so set to empty
        popPtr = 0;
        pushPtr = 0;
    }
    
    
    return 0;
}
