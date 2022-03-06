#include <stdio.h>


int increment(int *x){
    // increment recieves pointer to i
    // the value of i is incremented by 1 to 5 + 1 = 6
    // j will be 6
    // i will be 6
    return ++(*x);
}

int incrementt(int *x){
    // incrementt recieves pointer to i
    // (*x)++ will be treated as *(x++)
    // this means j will be 5 and i will be 6
    return (*x)++;
}


int main(int argc, const char * argv[]) {
    printf("Question 4\n");

    int i, j;
    i = 5;
    printf("j before %i \n",j);

    // pass pointer to i into increment
    j = increment(&i);
    printf("j is %i \n",j);
    printf("i is %i \n",i);


    printf("***\n");

    i = 5;
    j = incrementt(&i);
    printf("j is %i \n",j);
    printf("i is %i \n",i);

    return 0;
}
