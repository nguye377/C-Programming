#include <stdio.h>
#include "hw02.h"
#include <stdlib.h>
#include <limits.h>

void print_int_help(unsigned int num, int radix) {
	
	// base case
	unsigned int remainder;
	
	// recursion case
	remainder = num  % radix;	//get next place value
	if (num >= radix){
		num = num/radix;
		print_int_help(num, radix);
	}
	
	// only print after child has printed
	//print_num(remainder);
	if(remainder <= 9)
	{
		remainder = remainder + '0';
		fputc(remainder, stdout);
	}
	else if(remainder >= 10)
	{
		remainder = (remainder - 10) + 'a'	;
		fputc(remainder, stdout);
	}
	return;
}


void print_integer(int n, int radix, char* prefix){
	 unsigned int num = n;
	//int remainder;

	if(n < 0){
		num = -n;
		fputc('-', stdout);
	}
	for(int ind_in_s = 0; prefix[ind_in_s] != '\0'; ind_in_s++){
		fputc(prefix[ind_in_s], stdout);
	}

	// start recursion
	print_int_help(num, radix);
	
	//printf( '%u' ,mm);
	
}



