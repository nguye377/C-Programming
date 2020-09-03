#ifndef _CLOG_H_
#define _CLOG_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>

//Define colour
#define ANSI_RED	  "\x1b[31m"
#define ANSI_GREEN    "\x1b[32m"
#define ANSI_YELLOW   "\x1b[33m"
#define ANSI_BLUE     "\x1b[34m"
#define ANSI_MAGENTA  "\x1b[35m"
#define ANSI_CYAN     "\x1b[36m"
#define ANSI_RESET    "\x1b[0m"

//Doing the Macro Stuff
#ifdef DEBUG 
    #define log_msg(msg)    fprintf(stderr, "%s", (msg))   
    #define log_int(n)      fprintf(stderr, "%s == %d\n", (#n), n)
    #define log_str(s)      fprintf(stderr, "%s == %s\n", (#s), s)
    #define log_char(ch)    fprintf(stderr, "%s == %c\n", (#ch), ch)
    #define log_addr(addr) 	fprintf(stderr, "%s == %p\n", (#addr), addr)
    
    #define __mu_log_color(color,...) do {      \
        if(isatty(STDERR_FILENO)){              \
            fputs(color, stderr);               \
        }                                       \
        fprintf(stderr, __VA_ARGS__);           \
        if(isatty(STDERR_FILENO)) {             \
            fputs(ANSI_RESET, stderr);          \
        }                                       \
    }while(false)

    #define log_red(...)        __mu_log_color(ANSI_RED, __VA_ARGS__)                  
    #define log_green(...)      __mu_log_color(ANSI_GREEN, __VA_ARGS__)                   
    #define log_yellow(...)     __mu_log_color(ANSI_YELLOW, __VA_ARGS__)                  
    #define log_blue(...)       __mu_log_color(ANSI_BLUE, __VA_ARGS__)                    
    #define log_magenta(...)    __mu_log_color(ANSI_MAGENTA, __VA_ARGS__)                 
    #define log_cyan(...)       __mu_log_color(ANSI_CYAN, __VA_ARGS__)   

#else 
    #define log_msg(msg)
    #define log_int(n)
    #define log_str(s)
    #define log_char(ch)
    #define log_addr(addr)
    #define log_red(format, ...) 
    #define log_green(format, ...)              
    #define log_yellow(format, ...)           
    #define log_blue(format,...)          
    #define log_magenta(format,...)        
    #define log_cyan(format,...)

#endif
#endif
