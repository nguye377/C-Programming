#ifndef _MINIUNIT_H_
#define _MINIUNIT_H_

#define DEBUG
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
#include "clog.h"
//mu_start
#define mu_start() int __mu_line_current = 0;
//mu_check
#define mu_check(condition) do{                                                                 \
	if ((condition) == false && __mu_line_current == 0) { 								        \
	__mu_line_current = __LINE__; 														        \
	}																				            \
}while(false)	
//mu_run													
#define mu_run(function) do { 														            \
	int __mu_return_line_number = function();											        \
	if (__mu_return_line_number == 0) { 													    \
		log_green("Test passed (%s)\n", (#function));								            \
	}																				            \
	else { 																			            \
		log_red("Test failed (%s) at line %d\n", (#function), __mu_return_line_number);	        \
	}																				            \
} while (false)
//mu_end
#define mu_end() return __mu_line_current
#endif
