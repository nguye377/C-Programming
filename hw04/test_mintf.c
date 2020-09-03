#include <stdlib.h>
#include <stdio.h>
#include "mintf.h"
#include <limits.h>

int main(int argc, char *argv[]){
	
    mintf("123124\n");                                                                              //123124
	mintf("It is snowy, today!\n");                                                                 //It is snowy, today!
    mintf("%b can be converted in decimal as %d\n",5678, 5678);                                     //0b1011000101110 can be converted in decimal as 5678
    mintf("%x can be converted in hexa as %d\n", 79789, 79789);                                     //0x137AD can be converted in decimal as 79789
    mintf("This test is about to print out a negative number: %$\n", -1567.34444);                  //This test is about to print out a negative number: -1567.34444
    mintf("This number, %$,is less than 1.\n",0.0413);                                              //This number, %0.314 ,is less than 1.
    mintf("I pet %s", "a cute baby dog!\n");                                                        //I pet a cute baby dog
    mintf("This test to print out INT_MAX: %$\n", INT_MAX + 0.99);                                  //This test to print out INT_MAX: $2147483647
    mintf("How about printing INT_MIN: %$\n", INT_MIN - 0.965);                                     //How about printing INT_MIN: -$2146483648
    mintf("What is it? === %%d\n", 84);                                                             //What is it? === %d
    mintf("The fatality rate whe getting CORONA Viruses is 30%\n");                                 //The fatality rate whe getting CORONA Viruses is 30!
    mintf("Soooo, how about this one!?!?! What is it? === %d%%\n", 100);                            //Soooo, how about this one!?!?! What is it? === 100%
    mintf("Ignore the parameters: %d\n",7777, 121212, 202020);                                      //Ignore the paramters: 7777
    mintf("Print out a dollar-sign char %c\n", '$');                                                //Print out a dollar-sign char $
    mintf("The average aldult human body is around 65% water\n");                                   //The average aldult human body is around 65% water
    mintf("%%%\n");                                                                                 //%%
    mintf("%\n");                                                                                   //%
    mintf("%%\n");                                                                                  //%
    
    return EXIT_SUCCESS;

}