#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include "bit_writer.h"
#include "miniunit.h"
#include "clog.h"
#include <stdbool.h>

int _test_0() {
    mu_start();
    BitWriter writer = open_bit_writer("expected");
    write_bits(&writer, 0x1b, 8);
    close_bit_writer(&writer);
    FILE* file = fopen("expected", "r");
    mu_check(fgetc(file) == 0x1b);
    fclose(file);
    mu_end();
}

int _test_1() {
    mu_start();
    BitWriter writer = open_bit_writer("expected");
    write_bits(&writer, 0xf3, 3);
    close_bit_writer(&writer);
    FILE* file = fopen("expected", "r");
    mu_check(fgetc(file) == 0x60);
    fclose(file);
    mu_end();
}

int _test_2() {
    mu_start();
    BitWriter writer = open_bit_writer("expected");
    write_bits(&writer, 0x77, 5);
    close_bit_writer(&writer);
    FILE* file = fopen("expected", "r");
    mu_check(fgetc(file) ==0xB8);
    fclose(file);
    mu_end();
}

int _test_3() {
    mu_start();
    BitWriter writer = open_bit_writer("expected");
    write_bits(&writer, 0x0e, 4);
    write_bits(&writer, 0x0e, 4);
    close_bit_writer(&writer);
    FILE* file = fopen("expected", "r");
    mu_check(fgetc(file) == 0xee);
    fclose(file);
    mu_end();
}

int _test_4() {
    mu_start();
    BitWriter writer = open_bit_writer("expected");
    write_bits(&writer, 0x0b, 4);
    write_bits(&writer, 0x0a, 4);
    close_bit_writer(&writer);
    FILE* file = fopen("expected", "r");
    mu_check(fgetc(file) == 0xba);
    fclose(file);
    mu_end();
}


int _test_5() {
    mu_start();
    BitWriter writer = open_bit_writer("expected");
    write_bits(&writer, 0x05, 3);
    write_bits(&writer, 0xf3, 3);
    write_bits(&writer, 0x01, 2);
    write_bits(&writer, 0x20, 6);
    write_bits(&writer, 0x13, 5);
    close_bit_writer(&writer);
    FILE* file = fopen("expected", "r");
    mu_check(fgetc(file) == 0xAD);
    mu_check(fgetc(file) == 0x82);
    mu_check(fgetc(file) == 0x60);
    fclose(file);
    mu_end();
}




int main(int argc, char* argv[]) { 
    mu_run(_test_0);
    mu_run(_test_1);
    mu_run(_test_2);
    mu_run(_test_3);
    mu_run(_test_4);
    mu_run(_test_5);
    return EXIT_SUCCESS;
}