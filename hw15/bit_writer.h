#ifndef __BIT_WRITER_H__
#define __BIT_WRITER_H__


#include <stdint.h>
#include <stdio.h>

typedef struct {
	FILE* file;
	uint8_t current_byte;
	uint8_t num_bits_left;
} BitWriter;

BitWriter open_bit_writer(const char* path);
void write_bits(BitWriter* a_writer, uint8_t bits, uint8_t num_bits_to_write);
void flush_bit_writer(BitWriter* a_writer);
void close_bit_writer(BitWriter* a_writer);


#endif /* end of include guard: __BIT_WRITER_H__ */
#define __BIT_WRITER_H_V1__
