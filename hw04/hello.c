
// C program to demonstrate working of  
// variable arguments to find average 
// of multiple numbers. 
/*
#include <stdarg.h> 
#include <stdio.h> 
  
int average(int num, ...) 
{ 
    va_list valist; 
  
    int sum = 0, i; 
  
    va_start(valist, num); 
    for (i = 0; i < num; i++)  
        sum += va_arg(valist, int); 
  
    va_end(valist); 
  
    return sum / num; 
} 
  
// Driver code 
int main() 
{ 
    printf("Average of {2, 3, 4} = %d\n", average(2, 3, 4)); 
    printf("Average of {3, 5, 10, 15} = %d\n", average(3, 5, 10, 15)); 
    return 0; 
} 
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>                             // - This is required in any program that uses
                                                //   variadic functions (additional arguments).
void print_many_numbers(int num_of_nums, ...) { // - The ... stands for any number of arguments.
    va_list more_args;                          // - Get a handle to the additional arguments.
    va_start(more_args, num_of_nums);           // - This is required to access them.  Yes, it
                                                //   is weird.
    for(int i = 0; i < num_of_nums; i++) {      //
        int next_num = va_arg(more_args, int);  // - Get the next additional argument.
        printf("%d\n", next_num);               // - Print it.
    }                                           //
                                                //
    va_end(more_args);                          // - This is required after you're done.
}                                               //   Yes, this is weird (too).

int main(int argc, char* argv[]) {
    print_many_numbers(5, 768336, 768337, 768338, 768339);
    return EXIT_SUCCESS;
}

*/

#include <stdio.h>
#include <stdarg.h>

void m_printf(const char* fmt,...){
    va_list args;
    va_start(args,fmt);

    while(*fmt!='\0'){
        if(*fmt=='d'){
            int i=va_arg(args,int);
            printf("%d\n",i);
        }else if(*fmt=='c'){
            //automatic conversion to integral type
            int c=va_arg(args,int);
            printf("%c\n",c);
        }else if(*fmt=='f'){
            double d=va_arg(args,double);
            printf("%f\n",d);
        }
        ++fmt;
    }
    va_end(args);
}

int main(void)
{
    m_printf("dcff",1,'a',3.14,0);
}









