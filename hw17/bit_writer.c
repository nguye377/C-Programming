#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include "bit_writer.h"

BitWriter open_bit_writer(const char* path) {
    return (BitWriter) { .file = fopen(path, "w"), .current_byte = 0, .num_bits_left = 8};
}

void write_bits(BitWriter* a_writer, uint8_t bits, uint8_t num_bits_to_write) {
    assert(num_bits_to_write >= 0 && num_bits_to_write <= 8);
    assert(a_writer -> num_bits_left >= 1 && a_writer -> num_bits_left <= 8 );
    uint8_t temp_current_bits;
    if(num_bits_to_write >= 1) {
        if(num_bits_to_write > (a_writer -> num_bits_left)) {
            num_bits_to_write = (num_bits_to_write) - (a_writer -> num_bits_left);
            write_bits(a_writer, (bits >> (num_bits_to_write)), a_writer -> num_bits_left);
        }
        temp_current_bits = (bits <<(8-num_bits_to_write));
        temp_current_bits = temp_current_bits >> (8-num_bits_to_write);
        temp_current_bits = (temp_current_bits << ((a_writer -> num_bits_left) - num_bits_to_write));
        (a_writer->current_byte) = ((a_writer->current_byte) | temp_current_bits);

        if(((a_writer-> num_bits_left) - num_bits_to_write) == 0) {
            fwrite(&(a_writer->current_byte), sizeof(a_writer->current_byte), 1, a_writer->file);
            a_writer -> current_byte = 0;
            a_writer -> num_bits_left = 8;
        }
        else 
        {
        a_writer -> num_bits_left = ((((a_writer->num_bits_left) - num_bits_to_write) + 8 ) % 8);
        }
    }
    assert(((a_writer -> num_bits_left) >= 1) && ((a_writer -> num_bits_left) <= 8));
    return;
}

void flush_bit_writer(BitWriter* a_writer) {
    write_bits(a_writer, 0, a_writer->num_bits_left);
}

void close_bit_writer(BitWriter* a_writer) {
    while((a_writer -> num_bits_left) != 8 ) {
        flush_bit_writer(a_writer);
        break;
    }
    //flush_bit_writer(a_writer);
    fclose(a_writer-> file);
    a_writer->file = NULL;
}

#define __BIT_WRITER_C_V1__
/* vim: set tabstop=4 shiftwidth=4 fileencoding=utf-8 noexpandtab colorcolumn=96: */

