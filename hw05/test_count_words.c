#include <stdio.h>
#include <stdlib.h>
#include "count_words.h"
#include "miniunit.h"
//#include "clog.h"

int _test_empty() {
	mu_start();
	//-------------------------------
	mu_check(count_words("") == 0);
	//-------------------------------
	mu_end();
}

int _test_simple() {
	mu_start();
	//--------------------------------
	mu_check(count_words("apple") == 1);
	mu_check(count_words("boring boxes") == 2);
	mu_check(count_words("apple banana") == 2);
	mu_check(count_words("apple banana cherry") == 3);
	//--------------------------------
	mu_end();
}

int _test_hard() {
    mu_start();
    //--------------------------------
    mu_check(count_words("famigerate fiddle-faddle") == 2);
    mu_check(count_words("Mary's mongoose") == 2);
    mu_check(count_words("plumbers' platitudes") == 2);
    //--------------------------------
    mu_end();
}
int main(int argc, char* argv[]) {
	mu_run(_test_empty);
	mu_run(_test_simple);
	mu_run(_test_hard);

	log_int(count_words("My apples are sweet."));               // should print 4
	log_int(count_words("My friend's apples are sweeter."));    // should print 5
	log_int(count_words("A pear is sweeter than an apple.."));  // should print 7

	return EXIT_SUCCESS;
}
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
