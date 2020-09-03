#include <stdlib.h>
#include <stdio.h>
#include "mintf.h"

int main(int argc, char *argv[]){
	//Test 00: empty test
    //Expect: ""

    //Test 01: empty string
	mintf("");
    //Expect: ""

    //Test 02: Print out a string  
	mintf("This is a test!\n");
    //Expect: "This is a test"

    //Test 03: Print out the number
	mintf("41554\n");
    //Expect: "41554"

    //Test 04: Print a positve number - base 10
	mintf("This is a positive number: %d\n", 123456);
    //Expect: "This is a positive number: 123456"

    //Test 05: a negative number - base 10
	mintf("A negetive number: %d\n", -78945);
    //Expect: "A negetive number: 78945"

    //Test 06: BINARY Test with prefix "0b"
	mintf("%d in binary is: %b\n", 123, 123);
    //Expect: "123 in binary is: 0b1111011"

    //Test 07: HEX test with prefix "0x"
	mintf("%x in decimal is: %d\n", 589, 589);
    //Expect: "0x24D in decimal is 589"

    //Test 08: Print out STRING
	mintf("I pet a %s\n", "baby dog!");
    //Expect: "I pet a baby dog!"

    //Test 09: Print out a CHAR
	mintf("Print out a dollar-sign char %c\n", '$');
    //Expect: "Print out a dollar-sign char $"

    //Test 10: Testing for %$ with round up to 2 decimals
	mintf("A decimal number %$\n", 53.3588);
    //Expect: "A decimal number 53.35"

    //Test 11: Testing for %$ with round up to 2 decimals
	mintf("A negative decimal number %$\n", -321321.741852963);
    //Expect: "A negative decimal number -321321.74"

    //Test 12: Print out the "%" sign
	mintf("%%");
    //Expect: "%"

    return EXIT_SUCCESS;
}