#include <stdio.h>

#define callA callB(5)
/*The #define creates a macro,
 * which is the association of an identifier or parameterized identifier
 * with a token string. After the macro is defined, the compiler can
 * substitute the token string for each occurrence of the identifier
 * in the source file.
 */

void callB(int a){
    // prints 10
    printf("%i\n", a*2);
}


int main(int argc, const char * argv[]) {
    // this calls is substituted for callB(5)
    callA;
    return 0;
}