#include <stdio.h>

void callA(int a) {
    printf("A: %i\n", a);
}

void callB(int a) {
    printf("B: %i\n", a);
}

void callC(int a) {
    printf("C: %i\n", a);
}

int main(int argc, const char * argv[]) {
    void (*functionPointer[3])(int) = { &callA, &callB, &callC };
    functionPointer[0](20);
    functionPointer[1](21);
    functionPointer[2](22);
    return 0;
}
