#include <stdio.h>


int main(int argc, const char * argv[]) {
    printf("Question 3\n");
    long a = 1234567890; /* Hex: 499602d2 */
    long b = 1000000000; /* Hex: 3b9aca00 */

    // void pointer to b
    void*p=&b;

    // print address of b since p points to this address
    printf("%x\n", p);

    // void pointer is cast to a pointer of type long and incremented after print
    // prints b
    printf("%x\n",*(long*)p++);

    // void pointer p and cast to a pointer of type char and is incremented after print
    // prints
    printf("%x\n",*(char*)p++);

    //
    printf("%x\n",*(unsigned char*)p++);

    //
    printf("%x\n", p);


    return 0;
}