// Assignment 4 Problem 3
// build and test a stack
// R. Hensel 11-15-20

#include<assert.h>
#include"stack.h"

int main()
{
    int result1;
    int result2;
    int testInt;
    
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    testInt = 100;
    stack_init();
    
    // Act:
    result1 = stack_pop(&testInt);
      
    // Assert:
    assert(1 == result1);
    assert(100 == testInt);
    
    
    // *******************************************************************
    // Test2: Successfully pop an item from the stack
    // *******************************************************************
    // Arrange:
    result1 = 42;
    result2 = 42;
    testInt = 100;
    stack_init();
    
    // Act:
    result1 = stack_push(77);
    result2 = stack_pop(&testInt);
    
    // Assert:
    assert(0 == result1);
    assert(0 == result2);
    assert(77 == testInt);
    
    
    // *******************************************************************
    // Test3: Fill stack, then pop all items.
    // *******************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(77);
    stack_push(88);
    stack_push(99); 
    stack_push(111);
    stack_push(222);   
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(222 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(111 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(99 == testInt);
    
    assert(0 == stack_pop(&testInt));
    assert(88 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(77 == testInt);

    
    // *******************************************************************
    // Test4: Fill stack, then push one more item, should fail
    // *******************************************************************
    // Arrange:
    testInt = 77;
    stack_init();
    
    // Act:
    stack_push(77);
    stack_push(88);
    stack_push(99);
    stack_push(111);
    stack_push(222);
    
    // Assert:
    assert(1 == stack_push(333));

    assert(0 == stack_pop(&testInt));
    assert(222 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(111 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(99 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(88 == testInt);
    
    assert(0 == stack_pop(&testInt));
    assert(77 == testInt);


    // ***********************************************************************
    // Test5: Fill stack, pop one item, then push item, then pop all
    // ***********************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(77);
    stack_push(88);
    stack_push(99);
    stack_push(111);
    stack_push(222);
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(222 == testInt);

    assert(0 == stack_push(333));

    assert(0 == stack_pop(&testInt));
    assert(333 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(111 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(99 == testInt);
    
    assert(0 == stack_pop(&testInt));
    assert(88 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(77 == testInt);
    
    // ***********************************************************************
    // Test6: Fill stack and pop all items. Do it twice in a row.
    // ***********************************************************************
    // Arrange:
    testInt = 100;
    stack_init();
    
    // Act:
    stack_push(77);
    stack_push(88);
    stack_push(99);
    stack_push(111);
    stack_push(222);
    
    // Assert:
    assert(0 == stack_pop(&testInt));
    assert(222 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(111 == testInt);
    
    assert(0 == stack_pop(&testInt));
    assert(99 == testInt);
    
    assert(0 == stack_pop(&testInt));
    assert(88 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(77 == testInt);
    
    assert(0 == stack_push(44));
    assert(0 == stack_push(55));
    assert(0 == stack_push(66));
    assert(0 == stack_push(77));
    assert(0 == stack_push(88));
    
    assert(1 == stack_push(100));

    assert(0 == stack_pop(&testInt));
    assert(88 == testInt);
   
    assert(0 == stack_pop(&testInt));
    assert(77 == testInt);

    assert(0 == stack_pop(&testInt));
    assert(66 == testInt);
    
    assert(0 == stack_pop(&testInt));
    assert(55 == testInt);
    
    assert(0 == stack_pop(&testInt));
    assert(44 == testInt);

    return 0;
}
