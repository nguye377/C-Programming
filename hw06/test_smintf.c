#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include "smintf.h"
#include "miniunit.h"


int _test_smintf();

int main(int argc, char* argv[]) {
	mu_run(_test_smintf);
	char* s;
	
	s = smintf("Starting to test my HW!\n");														//Starting to test my HW!\n
	printf("%s", s);
	free(s);
	s = smintf("Convert from decimal %d to binary: %b\n", -1, -1);							//Convert from decimal -5050 to binary: -0b1001110111010\n
	printf("%s", s);
	free(s);
	s = smintf("%x\n", -7);													//7777 in Hexa is: 0x1e61\n
	printf("%s", s);
	free(s);
	s = smintf("How about printing out a negative number: %$\n", -123456);							//How about printing out a negative number: -$123456\n
	printf("%s", s);
	free(s);
	
	s = smintf("Max Integer Value %$\n", INT_MAX);													//Max Integer Value $2147483647\n
	printf("%s", s);
	free(s);
	s = smintf("Min Integer Value %$\n", INT_MIN);													//Min Integer Value -$2147483648\n
	printf("%s", s);
	free(s);
	
	
	s = smintf("Test double max integer value again %d\n", (double)(INT_MAX-0.97));							//Test double max integer value again $2147483647.0.97\n
	printf("%s", s);
	free(s);
	s = smintf("Test double min integer value again %d\n", (double)(INT_MIN-0.9888));							//Test double max integer value again -$2147483648.0.98\n
	printf("%s", s);
	free(s);
	
	s = smintf("A real number: %$\n", 907323.3432234);												//A real number: $907323.34\n
	printf("%s", s);
	free(s);
	s = smintf("One more real number: %$\n", -29073.37324);											//One more real number: -$29073.37\n
	printf("%s", s);
	free(s);
	
	s = smintf("Number less than 0, but greater than -1: %$\n", -0.777);							//Number less than 0, but greater than -1: -$o.77\n
	printf("%s", s);
	free(s);
	s = smintf("Number grater than 0, but less than 1: %$\n", 0.777);								//Number grater than 0, but less than 1: $0.77
	printf("%s", s);
	free(s);
	s = smintf("%s%d %s 2020!!!\n", "ECE", 264, "Spring");											//ECE264 Spring 2020!!!\n
	printf("%s", s);
	free(s);	
	s = smintf("Testing to print out % for %% and %%%\n", 232);										//Testing to print out % for % and %%\n
	printf("%s", s);
	free(s);
	s = smintf("Test for a char: %c\n", 'A');															//Test for a char: A\n
	printf("%s", s);
	free(s);
	s = smintf("Done for testing!!!");
	printf("%s", s);
	free(s);
	s = smintf("");
	printf("%s", s);
	free(s);
	
	
	// mintf("123124\n");                                                                              //123124
	// mintf("It is snowy, today!\n");                                                                 //It is snowy, today!
    // mintf("%b can be converted in decimal as %d\n",5678, 5678);                                     //0b1011000101110 can be converted in decimal as 5678
    // mintf("%x can be converted in hexa as %d\n", 79789, 79789);                                     //0x137AD can be converted in decimal as 79789
    // mintf("This test is about to print out a negative number: %$\n", -1567.34444);                  //This test is about to print out a negative number: -1567.34444
    // mintf("This number, %$,is less than 1.\n",0.0413);                                              //This number, %0.314 ,is less than 1.
    // mintf("I pet %s", "a cute baby dog!\n");                                                        //I pet a cute baby dog
    // mintf("This test to print out INT_MAX: %$\n", INT_MAX + 0.99);                                  //This test to print out INT_MAX: $2147483647
    // mintf("How about printing INT_MIN: %$\n", INT_MIN - 0.965);                                     //How about printing INT_MIN: -$2146483648
    // mintf("What is it? === %%d\n", 84);                                                             //What is it? === %d
    // mintf("The fatality rate whe getting CORONA Viruses is 30%\n");                                 //The fatality rate whe getting CORONA Viruses is 30!
    // mintf("Soooo, how about this one!?!?! What is it? === %d%%\n", 100);                            //Soooo, how about this one!?!?! What is it? === 100%
    // mintf("Ignore the parameters: %d\n",7777, 121212, 202020);                                      //Ignore the paramters: 7777
    // mintf("Print out a dollar-sign char %c\n", '$');                                                //Print out a dollar-sign char $
    // mintf("The average aldult human body is around 65% water\n");                                   //The average aldult human body is around 65% water
    // mintf("%%%\n");                                                                                 //%%
    // mintf("%\n");                                                                                   //%
    // mintf("%%\n");           

	return EXIT_SUCCESS;
}

int _test_smintf(){
	mu_start();
	mu_check_smintf("10\n", smintf("%d\n", 10));
	mu_check_smintf("-0b1010\n", smintf("%b\n", -10));
	//mu_check_smintf("Max double variable $2147483647.99?\n", smintf("Max double variable %$?\n", INT_MAX + 0.99));
	mu_end();
	return 0;
}

