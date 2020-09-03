#include <stdio.h>

void greet_visitor() {
	int gt_top = 0xAAAAAAAA;
	char name[10]; // BAD!!!
	printf("Hello.  What is your name?\n");
	gets(name);    // VERY, VERY, VERY BAD!!!
	printf("Hello, %s.", name);
	int gt_btm = 0xAABBBBAA;
}

void scare_visitor() {
	int sv_top = 0xAACCCCAA;
	char message[10] = "BRAH!!!\n"; // OKAY
	printf(message);
	int sv_btm = 0xAADDDDAA;
}

int main(int argc, char *argv[]) {
	int mn_top = 0xAAEEEEAA;
	greet_visitor();	
	int mn_btm = 0xAAFFFFAA;
	return 0;
}


/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab: */
