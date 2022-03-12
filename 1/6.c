#include <stdio.h>

int main(int argc, const char * argv[]) {
    struct {
        char a[10];
        char b;
        char c;
        short int d;
    }myStruct;

    union {
        char a[12];
        int b;
        short int d[4];
    } myUnion;

    //struct: each element gets its own disk space -> 14
    // char a[10]: 10 bytes + char b 1 byte + char c 1 byte + short int 2 bytes
    // union: disk space is defined by biggest element -> 12
    // char a[12]: 12 bytes
    printf("%i\n", sizeof (myStruct));
    printf("%i\n", sizeof (myUnion));
}