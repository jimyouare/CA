#include <stdio.h>

int main(int argc, const char * argv[]) {
    struct {
        char a[10];
        char b;
        char c;
        short intd;
    }myStruct;

    union {
        char a[12];
        int b;
        short int d[4];
    } myUnion;

    printf("%i\n", sizeof (myStruct));
    printf("%i\n", sizeof (myUnion));
}