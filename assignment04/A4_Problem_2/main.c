// Project for Assignment 4, problem 2
//  investigate assembly code for function calling
//
//
//
int func1(int f1var1, int f1var2, int f1var3, int f1var4, int f1var5)
//int func1(int f1var1, int f1var2, int f1var3)
{
    int var1;
    int var2;
    int var3;
    int var4;
    int var5;
    //int var6;
    //int var7;
    int sum;
    
    var1 = f1var1;
    var2 = f1var2;
    var3 = f1var3;
    var4 = f1var4;
    var5 = f1var5;
    //var6 = f1var6;
    //var7 = f1var7;
    
    sum = var1 + var2 + var3 + var4 + var5;
    //sum = var1 + var2 + var3;
    return sum;
}

int func2(void)
{
    int var1 = 1;
    int var2 = 3;
    int var3 = 5;
    int var4 = 7;
    int var5 = 9;
    //int var6 = 11;
    //int var7 = 13;
    //int f2result;
    int sum;
    
    sum = func1(var1, var2, var3, var4, var5);
    //sum = func1(var1, var2, var3);
    return sum;
}

int main(void)
{
    //int v1 = 1;
    int result;
    //while(1)
    //{ 
    //}
    result = func2();
    return result;
}

