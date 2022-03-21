#include <stdio.h>


int main(int argc, const char * argv[]) {



    L1: #do something
        add $s2, $s2, $s1 beq $s2, $s3, L2 j L1
    L2:


    return 0;
}