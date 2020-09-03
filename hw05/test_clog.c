#include "clog.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	log_msg("COLOURS\n");
	log_green("green\n");
	log_red("red\n");
	log_yellow("yellow\n");
	log_blue("blue\n");
	log_magenta("magenta\n");
	log_cyan("cyan\n");

	log_msg("\n");

	log_msg("SHOPPING LIST\n");
	log_green("bok choy x %d bunches\n", 3);
	log_red("tomatos x %d \n", 5);
	log_yellow("lemon x %d\n", 3);
	log_blue("borage x %d flower\n", 100);
	log_magenta("rrambutan x %d\n", 15);
	log_cyan("Peeps x %d boxes\n", 5);
	
	return EXIT_SUCCESS;
}
