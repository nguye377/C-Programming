/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
#include <stdio.h>
#include <stdlib.h>
#include "prime_factor.h"

int main(int argc, char* argv[]) {
	print_prime_factors(6);
	print_prime_factors(1);  // should report "(none)"
	print_prime_factors(0);  // should report "(none)"
	print_prime_factors(48); // 2 2 2 2 3
	print_prime_factors(49); // 7 7 (square number)
	print_prime_factors(74); // 2 37

	return EXIT_SUCCESS;
}
