

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

double numbers[3];

// original
// does not check if out of bounds
// does not use *x which is a parameter
// always returns 0
int setValueAtOrg(double *x, int i, double value){
    x[i] = value;
    return 0;
}

// improved

void setValueAt(double *x, int i, double value){
    if (i < 3){
        *x = *x + i;
        *x = value;
    }

}

int main(int argc, const char * argv[]) {

    for (int i = 0; i < 3 ; ++i) {
        numbers[i] = 423.34;
    }

    printf("before\n");
    for (int i = 0; i < 3; ++i) {
        printf("Array is %f\n", numbers[i]);    }



    double * num_pointer = & numbers;
    setValueAt(num_pointer,0,100.0002);
    printf("after\n");

    for (int i = 0; i < 3; ++i) {
        printf("Array is %f\n", numbers[i]);    }

    return 0;
}






