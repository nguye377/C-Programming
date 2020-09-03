
#include <stdio.h>
//#include "hw02.h"
#include <stdlib.h>
#include <limits.h>
#include "mintf.h"
#include <stdarg.h>
//============================[Copy]-mintf.h===========================
#ifndef __mintf_h__
#define __mintf_h__

void mintf(const char *format, ...);
void print_integer(int n, int radix, char* prefix);

#endif
//=====================================================================
//============================[Copy]-hw02.h============================
#ifndef __hw02_h__
#define __hw02_h__

void print_integer(int n, int radix, char* prefix);

#endif
//=====================================================================

//Recursion function
void print_int_help(unsigned int num, int radix) {
	
	// base cases
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
	
}

void mintf(const char *format,...){
	
	//const char *traverse;
	char *str;	
	char characters_temp;
	va_list argss;
	va_start (argss, format);
	double double_value;
	
	//for(traverse = format; *traverse != '\0'; traverse++)
	while(*format != '\0')
	{
		//Print all the string before encountering the "%"
		if(*format != '%')
		{
			fputc(*format, stdout);
			format++;
			continue;		//jump back to the if(*format != '%');
		}

		format++;
		//Spending three hour becasue of these four lines
		// if(*format == '\0')
		// {
		// 	break;
		// }
		switch(*format)
		{
			//Convert from Decimal to Decimal and print out
			case 'd':
				print_integer(va_arg(argss, int), 10, "");	
				break;
			//COnvert from decimal to binary and print out
			case 'b':
				print_integer(va_arg(argss, int), 2, "0b");
				break;
			//Convert from decimal to hexa and then print out
			case 'x':
				print_integer(va_arg(argss, int), 16, "0x");
				break;

			//Print out a string
			case 's':
				for(str = va_arg(argss, char *); *str; str++)
				{
					fputc(*str, stdout);
				}
				break;
			//
			case 'c':
				characters_temp = va_arg(argss, int);
				fputc(characters_temp, stdout);
				break;
			
			//Pass a double to an argument
			case '$':
				double_value = va_arg(argss, double);
				unsigned long int integer_input = (int) double_value;
				print_integer(integer_input, 10, "$");
				fputc('.', stdout);
			 	if(double_value<0)
				{
					double_value = -double_value;
					integer_input = -integer_input;
				}
				int decimal_part = double_value*100 - integer_input*100; //Get 2 decimal number -- round-up part
				if(decimal_part < 10)
				{
					fputc('0', stdout);
					print_integer(decimal_part, 10, "");
				}
				else
				{
					print_integer(decimal_part, 10, "");
				}
				 
				break;
			case '%':
				fputc('%', stdout);
				break;
			default:
				//Becasue the pointer already went and passed to the very first address [or index in an array]
				//so now we need to go back an address to print its value.
				//This means this value is actually the value of "%"
				format--;
				//traverse--;
				fputc(*format, stdout);
				break;							
		}

		format++;	
		//traverse++;	
	}
	va_end(argss);
}

/*
int main(int argc, char *argv[]){
	char a = 'a';
	mintf("768336");
	fputc('\n', stdout);
	mintf("My favorite number is %d %d %d!", -768336);
	fputc('\n', stdout);
	mintf("%d written in binary is %b.", 768336, 768336);
	fputc('\n', stdout);
	mintf("%d%%", 768336);
	fputc('\n', stdout);
	mintf("%d written in hex is %x.", 768336, 768336);
	fputc('\n', stdout);
	mintf("This is a string: %s", "ABCasdfghjkl");
	fputc('\n', stdout);
	mintf("This is a %c", a);
	fputc('\n', stdout);
	mintf("%$", 23223.1234);
	fputc('\n', stdout);
	mintf("Orlicasta's shoes cost %$.", -768.336);
	fputc('\n', stdout);
	return EXIT_SUCCESS;
}
*/





















