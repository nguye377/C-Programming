#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdint.h>
#include <stdbool.h>
#include <inttypes.h>
#include "miniunit.h"
#include "frequencies.h"
#include <stdlib.h>


int testing_true() {
    Frequencies freqs = {0};
    const char* a_error = "true";

    mu_start();
	mu_check(calc_frequencies(freqs, "test.txt", &a_error) == true);
	mu_end();
}
int testing_no_file() {
    Frequencies freqs = {0};
    const char* a_error = "false";
    mu_start();
	mu_check(calc_frequencies(freqs, "no_file", &a_error) == false);
	mu_end();
}


int main(int argc, char** argv) {
    
    mu_run(testing_true);
    mu_run(testing_no_file);

    return EXIT_SUCCESS;
}