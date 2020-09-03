#include <stdio.h>
#include <stdlib.h>

// print_prime_factors(…) prints the prime factorization of an integer
// using a naïve algorithm, to keep this code simple and understandable.
// Actually, there are *much* more efficient methods!
//   https://en.wikipedia.org/wiki/Integer_factorization

/*****************************************************\
|*                                                   *|
|* WARNING:  Some comments may be misleading/false.  *|
|*           This is about finding bugs.             *|
|*                                                   *|
\*****************************************************/

void print_prime_factors(int n) {
    if(n <= 0) {
        printf("Only positive numbers are supported.\n");
    }
    else {
        printf("Prime factors of %d:", n);

        if(n == 1) {
            printf(" (none)");
        }
        else {
            // Print all occurrences of 2 in the prime factorization
            while(n % 2 == 0) {
                printf(" %d", 2);
                n /= 2;  // Divide n by 2 (integer division)
            }

            // Try all odd integers, from 3 to sqrt(n)
            for(int i = 3; i * i < n; i += 2) {

                // Print all occurrences of i in the prime factorization
                while(n % i == 0) {
                    printf(" %d", i);
                    n /= i; // Divide n by i (integer division)
                }
            }

            if(n >= 3) {
                printf(" %d", n);
            }
        }
        printf("\n");
    }
}

/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 expandtab: */
