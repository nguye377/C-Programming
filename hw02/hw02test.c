#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "hw02.h"

int main(int argc, char* argv[]){
	print_integer(8876, 12, "");  				 //5178
	fputc('\n', stdout);
	print_integer(-5621, 16, "hi");				 //15f5
	fputc('\n', stdout);	
	print_integer(-1231245, 10, "$$xxabc");		//1231245
	fputc('\n', stdout);
	print_integer(-232455, 36, "0xxxxx");		//4zd3
	fputc('\n', stdout);
	print_integer(INT_MAX, 20, "max_");			//1db1f927
	fputc('\n', stdout);
	print_integer(INT_MIN, 29, "!@#$%^&*()_+min_"); //3hk7988
	fputc('\n', stdout);
	print_integer(-654433, 8, "");				//2376141
	fputc('\n', stdout);
	print_integer(34999, 17, "$oooo$"); print_integer(-28, 2, "testttt");
	fputc('\n', stdout);					//721D --- 11100
	print_integer(1, 2, "-");
	fputc('\n', stdout);
	print_integer(1, 2, "");
	fputc('\n', stdout);
	print_integer(INT_MIN, 2, "min_0x"); //3hk7988
	fputc('\n', stdout);
	print_integer(0, 10, "");    //0
	fputc('\n', stdout);
	print_integer(250, 10, "");    //0
	fputc('\n', stdout);

	return EXIT_SUCCESS;
}
/*
5178
-hi15f5
-$$xxabc1231245
-Oxxxxx4zd3
max_1db1f927
-!@#$%^&*()_+min_3hk7988
-2376141
$oooo$721d-testttt11100
-1
1
-min_0x10000000000000000000000000000000
*/
