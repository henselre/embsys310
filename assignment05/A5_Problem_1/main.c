//  Assignment 5, Problem 1
//  Testing a function that swaps two pointers
//
//  R. Hensel
// 11-21-20
//

void swap_value(int* x, int* y);
void swap_pointer(int** x, int** y);
//
void swap_value(int* a, int* b)   /* function swaps the value of two pointers*/
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_pointer(int** a, int** b)   /* function swaps two pointers */
{
    int* tempPtr = *a;
    *a = *b;
    *b = tempPtr;
}

int main()
{
    int x = 5;
    int y = 7;
    int* xPtr = &x;
    int* yPtr = &y;
    int** xPtrPtr = &xPtr;
    int** yPtrPtr = &yPtr;
    
    int i=0;
    for (i=0;i <5; i++)
    {
    //swap_value(xPtr,yPtr);
    swap_pointer(xPtrPtr,yPtrPtr);
    }
    x=0;
    y=0;
  return 0;
}
