#include <stdio.h>


int main(int argc, const char * argv[]) {
    printf("Question 3\n");
    long a = 1234567890; /* Hex: 499602d2 */
    long b = 1000000000; /* Hex: 3b9aca00 */
    printf("a %x\n",a);
    printf("b %x\n",b);
    // void pointer to b
    void*p=&b;

    // print address of b since p points to this address
    printf("%x\n", p);
    //printf("Address of b: %p\n", &b);

    // void pointer p is incremented and cast to a pointer of type long
    // prints b
    printf("%x\n",*(long*)p++);

    // void pointer p is incremented and cast to a pointer of type char
    // prints
    printf("%x\n",*(char*)p++);

    //
    printf("%x\n",*(unsigned char*)p++);

    //
    printf("%x\n", p);


    return 0;
}