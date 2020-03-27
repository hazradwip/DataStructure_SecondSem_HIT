#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct poly
{
    int coeff;
    int exp;
};

typedef struct poly poly;

poly *create(int);

poly *sort(poly *, int);

void display(poly *, int);
