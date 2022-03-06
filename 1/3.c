#include <stdio.h>


int main(int argc, const char * argv[]) {
    printf("Question 3\n");
    long a = 1234567890; /* Hex: 499602d2 */
    long b = 1000000000; /* Hex: 3b9aca00 */

    //pointer to b
    void*p=&b;

    //print address of p
    printf("%x\n", p);

    //print content of pointer off casted long pointer of the next address to p
    //pr
    printf("%x\n",*(long*)p++);
    printf("%x\n",*(char*)p++);
    printf("%x\n",*(unsigned char*)p++);
    printf("%x\n", p);


    return 0;
}