

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

double numbers[3];

// original with checks for array out of bound
int setValueAtOrg(double *x, int i, double value, int l){
    if (i <= l){
        x[i] = value;
        return 0;
    } else{
        return 1;
    }
}

// improved
int setValueAt(double *x, int i, double value, int l){
    if (i <= l){
        *(x+i) = value;
        return 0;
    } else{
        return 1;
    }
}

int main(int argc, const char * argv[]) {

    for (int i = 0; i < 3 ; ++i) {
        numbers[i] = 423.34;
    }

    printf("before\n");
    for (int i = 0; i < 3; ++i) {
        printf("Array is %f\n", numbers[i]);
    }


    double * num_pointer =  numbers;
    int l = sizeof (numbers) / sizeof (double );
    int x = setValueAtOrg(num_pointer,6,100.0002,l);
    int y = setValueAt(num_pointer,2,100.0002,l);
    printf("original: %d\n",x);
    printf("changed: %d\n",y);
    printf("after\n");

    for (int i = 0; i < 10; ++i) {
        printf("Array is %f\n", numbers[i]);
    }

    return 0;
}






