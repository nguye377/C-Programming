
#include <stdarg.h>
#include <stdlib.h> 
#include "smintf.h"
#include <limits.h>
#include <stdio.h>

int _len_str(const char*, va_list);
int _num_len(int, int);
void _print_integer(int, int, char*, char*, int*);
void _help_print_integer(unsigned int, int, char*, int*);
void _store_string(char*, const char*, int, va_list);
void _output(char*, int, char);

char* smintf(const char *format, ...) {
    va_list agrs_orig, args_copy;
    va_start(agrs_orig, format);
    va_copy(args_copy, agrs_orig);

    int len_str;
    len_str = _len_str(format, agrs_orig);
    char* result;
    result = malloc((len_str + 1)*sizeof(result));
    _store_string(result, format, len_str, args_copy);
    
    va_end(agrs_orig);
    va_end(args_copy);
    return result;
}

void mintf(const char* format, ...) {
	va_list agrs_orig, args_copy;
	va_start(agrs_orig, format);
	va_copy(args_copy, agrs_orig);
	int str_length = _len_str(format, agrs_orig);
	_store_string(NULL, format, str_length, args_copy); // Use NULL as a flag: if it is NULL, _str_store will print. If not NULL, the character will be stored into the string 
	va_end(agrs_orig);
	va_end(args_copy);
	return;
}


int _len_str(const char* format, va_list argss) {
    int len_str = 0;
    char *str;
    double temp;
	int tempp;
    for(int i = 0; format[i] != '\0'; i++){
		if(format[i] != '%'){
        len_str++; //length of string
	    }
        else{
            i++;
            switch(format[i])
		    {
				//Convert from Decimal to Decimal and print out
			    case 'd':
					tempp = va_arg(argss, int);
				    len_str += _num_len(tempp, 10);
				    break;
			    //Convert from decimal to binary and print out
			    case 'b':
					tempp = va_arg(argss, int);
				    len_str += _num_len(tempp, 2) + 2;
				    break;
			    //Convert from decimal to hexa and then print out
			    case 'x':
					tempp = va_arg(argss, int);
				    len_str += _num_len(temp, 16) + 2;
				    break;
			    //Print out a string
			    case 's':
				    for(str = va_arg(argss, char *); *str; str++)
				    {
					    len_str++;
				    }
				    break;
                //Character
			    case 'c':
				    va_arg(argss, int);
                    len_str++;
				    break;			
			    //Pass a double to an argument
			    case '$':
				    temp = va_arg(argss, double);
				    if((temp < 0) && (temp > -1)){
                        len_str++;
                    }
                    int integer_temp = temp;
                    //Count '.', 2 decimal places, and "$" prefix
                    len_str += _num_len(integer_temp, 10) + 4;
				 
				    break;
			    case '%':
				    len_str++;
				    break;
			    default:
				    //Becasue the pointer already went and passed to the very first address [or index in an array]
				    //so now we need to go back an address to print its value.
				    //This means this value is actually the value of "%"
				    i--;
				    len_str++;
				    break;						
		    }
        }   
    }
    return len_str;
}

/*
int _len_str(const char* format, va_list args) {
	int length = 0;
	for (int i = 0; format[i] != '\0'; i++) {
		if (format[i] != '%') {
			length++;
		}
		else {
			i++;
			if (format[i] == 'd' || format[i] == 'x' || format[i] == 'b') {
				int new_input = va_arg(args, int);
				if (format[i] == 'd') {
					length += _num_len(new_input, 10);
				}
				else if(format[i] == 'x') {
					length += _num_len(new_input, 16) + 2; // Count the prefix
				}
				else {
					length += _num_len(new_input, 2) + 2; // Count the prefix
				}
			}
			else if (format[i] == '$') {
				double new_input = va_arg(args, double);
				if (new_input < 0 && new_input > -1) { // Count the '-' character because if a decimal number is > -1 and < 0 (-0.123 for example), the integer_input (line 59) will only returns 0, completely eliminate the '-' sign
					length++;
				}
				int integer_input = new_input;
				length += _num_len(integer_input, 10) + 4; // Count the '.', 2 decimal places, and '$' prefix
			}
			else if (format[i] == 's') {
				char* new_input = va_arg(args, char*);
				for (int j = 0; new_input[j] != '\0'; j++) {
					length++;
				}
			}
			else if (format[i] == 'c') {
				va_arg(args, int);
				length++;
			}
			else if (format[i] == '%') {
				length++;
			}
			else {
				i--;
				length++;
			}
		}
	}
	return length;
}
*/

int _num_len(int temp, int radix){
    unsigned int abs_value = temp;
    int len = 0;
    if(temp < 0){
        abs_value *= -1;
        len++; //Count the '-'
    }
    if(temp != 0 ){
        for(;abs_value > 0; len++){
            abs_value /=radix;
        }
    }
    else // Count the '0' character if n = 0
    {
        len++; 
    }
    return len;
}


void _store_string(char* output, const char* format, int len_str, va_list argss) {
	char *str;
    char char_temp;
    double double_value;
    int index = 0;
    
	for(int i = 0; index < len_str; i++) {
		if (format[i] != '%') {
			_output(output, index, format[i]);	
			index++;
		}
		else {
			i++;
            switch (format[i])
            {
                case 'd':
                    _print_integer(va_arg(argss, int), 10, "", output, &index);
                    break;
            
                case 'b':
                    _print_integer(va_arg(argss, int), 2, "0b", output, &index);
                    break;
                case 'x':
                    _print_integer(va_arg(argss, int), 16, "0x", output, &index);
                    break;
                case 's':
                    for(str = va_arg(argss, char*); *str; str++){
                        _output(output, index, *str);
                        index++;
                    }
			        break;
                case 'c':
                    char_temp = va_arg(argss, int);
                    //fputc(char_temp, stdout);
                    _output(output, index, char_temp);
                    index++;
                    break;
                case '%':
                    //fputc('%', stdout);
                    _output(output, index, '%');
                    index++;
                    break;
                case '$':
                    double_value = va_arg(argss, double);
					//double_value = va_arg(argss, int);
					//printf("%f\n", double_value);
				    if ((double_value < 0) && (double_value > -1)) { 
					    //fputc('-', stdout);
					    _output(output, index, '-');
						//printf("%s\n", output);
                        index++;
				    }
					
				    unsigned long int integer_input = (int) double_value;
					//printf("%ld\n", integer_input);
					//printf("before %s\n", output);
					
				    _print_integer(integer_input, 10, "$", output, &index);
					
					//printf("after %s\n", output);
			 	    //fputc('.', stdout);
                    _output(output, index, '.');
				    index++;
				    if (double_value < 0) {
					    double_value = -double_value;
					    integer_input = -integer_input;
				    }
					//printf("%f\n", double_value);
				    int decimal_part = double_value * 100 - integer_input * 100; 
					//printf("%d\n", decimal_part);
				    if (decimal_part < 10) { 
					    //fputc('0', stdout);
                        _output(output, index, '0');
					    index++;
					    _print_integer(decimal_part, 10, "", output, &index); 
				    }
				    else {
					    _print_integer(decimal_part, 10, "", output, &index);
				    }
				
                    break;
                    //----------------------------------------------------
                default:
                    i--;
                    _output(output, index, format[i]);
                    index++;
                    break;
            }

		}
	}
	if (output != NULL) {
		_output(output, index, '\0');
	}
	return;
}



// void _store_string(char* output, const char* format, int str_length, va_list args) {
// 	int output_index = 0;
// 	for(int i = 0; output_index < str_length; i++) {
// 		if (format[i] != '%') {
// 			_output(output, output_index, format[i]);	
// 			output_index++;
// 		}
// 		else {
// 			i++;
// 			if (format[i] == 'd' || format[i] == 'x' || format[i] == 'b') {
// 				int new_input = va_arg(args, int);
// 				if (format[i] == 'd') {
// 					_print_integer(new_input, 10, "", output, &output_index);
// 				}
// 				else if(format[i] == 'x') {
// 					_print_integer(new_input, 16, "0x", output, &output_index);
// 				}
// 				else {
// 					_print_integer(new_input, 2, "0b", output, &output_index);
// 				}
// 			}
// 			else if (format[i] == '$') {
// 				double new_input = va_arg(args, double);
// 				if (new_input < 0 && new_input > -1) { // Put negative sign for numbers that are negative but larger than 1
// 					_output(output, output_index, '-');
// 					output_index++;
// 				}
// 				unsigned long int integer_input = new_input;
// 				_print_integer(integer_input, 10, "$", output, &output_index);
// 			 	_output(output, output_index, '.');
// 				output_index++;
// 				if (new_input < 0) {
// 					new_input = -new_input;
// 					integer_input = -integer_input;
// 				}
// 				int decimal = new_input * 100 - integer_input * 100; // Get the 2 decimal numbers by subtracting the double value to the integral value times 100 
// 				if (decimal < 10) { // If decimal number is less than 10, make sure to store a '0' before the decimal number
// 					_output(output, output_index,'0');
// 					output_index++;
// 					_print_integer(decimal, 10, "", output, &output_index); 
// 				}
// 				else {
// 					_print_integer(decimal, 10, "", output, &output_index);
// 				}
// 			}
// 			else if (format[i] == 's') {
// 				char* new_input = va_arg(args, char*);
// 				for (int j = 0; new_input[j] != '\0'; j++) {
// 					_output(output, output_index, new_input[j]);
// 					output_index++;
// 				}
// 			}
// 			else if (format[i] == 'c') {
// 				char new_input = va_arg(args, int);
// 				_output(output, output_index, new_input);	
// 				output_index++;
// 			}
// 			else if (format[i] == '%') {
// 				_output(output, output_index, '%');
// 				output_index++;
// 			}
// 			else {
// 				i--;
// 				_output(output, output_index, format[i]);
// 				output_index++;
// 			}
// 		}
// 	}
// 	if (output != NULL) {
// 		_output(output, output_index, '\0');
// 	}
// 	return;
// }

//Recusive function
void _help_print_integer(unsigned int num, int radix, char* output, int* index){
    // base cases
    unsigned int remainder;
    //recusrsion case 
    remainder = num % radix;
	
    if(num >= radix){
        num = num/radix;
        _help_print_integer(num, radix, output, index);
    }
    if(remainder <= 9){
        remainder = '0' + remainder;
        _output(output, *index, remainder);
        *index = *index + 1;
    }
    else if( remainder >= 10){
        remainder = (remainder -10) +'a';
        _output(output, *index, remainder);
        *index = *index + 1;
    }
    return;
}

void _print_integer(int n, int radix, char* prefix, char* output, int* index){
    
    unsigned int num = n;
	
    int num_len = _num_len(n, radix);
    if(n< 0){
        num = -n;
        _output(output, *index, '-');
        *index = *index + 1;
        num_len--;
    }
    for(int i = 0; prefix[i] != '\0'; i++){
        _output(output, *index, prefix[i]);
        *index = *index + 1;
    }
	if (n == INT_MAX) {
		printf("here");
		return;
	}
    //Starting recursion
    _help_print_integer(num, radix, output, index);
}

/*
void _print_integer(int n, int radix, char* prefix, char* output, int* output_index) { 
	unsigned int absnumber = n;
	int num_length = _num_len(n, radix);
	if (n < 0) {
		absnumber = -n;
		_output(output, *output_index, '-');
		*output_index = *output_index + 1;
		num_length--; // Minus due to the redudancy of '-' in num_length and output_index, which will mess up the output indexing
	}	
	for (int i = 0; prefix[i] != '\0'; i++) {
		_output(output, *output_index, prefix[i]);
		*output_index = *output_index + 1;
	}
	int mod_number = absnumber % radix;
	if (absnumber >= radix) {
		absnumber /= radix;
		_print_integer(absnumber, radix, "", output, output_index); // Use recursion to print out/ put the char into string from left to right
	}
	if (mod_number < 10) {
		_output(output, *output_index, '0' + mod_number);
		*output_index = *output_index + 1;
	}
	else {
		_output(output, *output_index, 'a' + mod_number - 10);
		*output_index = *output_index + 1;
	}
	return;
}
*/
void _output(char* output, int index, char c) {
	//This condition for mintf(), setting NULL as a flag
    if (output != NULL) {
         output[index] = c;
	} 
    //This condition for smintf()
	else
    {
        fputc(c, stdout);
    }
}

