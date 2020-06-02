#include <stdio.h>

int gcd(int, int);

// Driver program to test above function
int main()
{
    srand(time(0));
    int a = rand() % 100, b = rand() % 100;

    if (b>a)
        b = (a + b) - (a = b);

    printf("GCD of %d and %d is %d ", a, b, gcd(a, b));
    return 0;
}

int gcd(int a, int b)
{
    if (b == 0) 
        return a; 
    return gcd(b, a % b);
}

/*
================ OUTPUT ================
******* All the inputs are taking by Random Function *******

GCD of 28 and 16 is 4

GCD of 32 and 65 is 1 

GCD of 50 and 98 is 2 
*/