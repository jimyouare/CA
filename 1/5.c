#include <stdio.h>

void test(){

    short x = 3;
    short *px = &x;
    *(px--) = 20;
    *px = 21;
    // prints 20 21
    printf("%i %i\n", x, *px);
}

int main(int argc, const char * argv[]) {
    printf("Question 5\n");
    short x[4] = {1, 2, 3, 4};
    int *px = x;

    //prints 1 1
    printf("%i %i\n", *x, *(short *)px);
    px++;
    //prints 1 3
    //address px-1 could already be used and will be overwritten
    printf("%i %i\n", *x, *(short *)px);


    test();

    return 0;
}