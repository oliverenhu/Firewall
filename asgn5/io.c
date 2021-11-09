#include "io.h"
#include <unistd.h>
#include "defines.h"
#include <stdio.h>
#include "fcntl.h"
#include <stdint.h>
static uint8_t read_buffer[BLOCK];
static int read_index = 0;
static int read_end = -1;
uint64_t bytes_read = 0;
uint64_t bytes_written = 0;

int read_bytes(int infile, uint8_t *buf, int nbytes) {
    int br = 0;
    int r = 0;
    while (r != nbytes) {
        br = read(infile, buf + bytes_read, nbytes - bytes_read);

        bytes_read += br;
        r = bytes_read;
        if (br == 0) {
            break;
        }
    }
    //    printf("%lu", bytes_read);
    return bytes_read;
}
int write_bytes(int outfile, uint8_t *buf, int nbytes) {
    int bw = 0;
    int w = 0;
    while (w != nbytes) {
        bw = write(outfile, buf + bytes_written, nbytes - bytes_written);

        bytes_written += bw;
        w = bytes_written;
        if (bw == 0) {
            break;
        }
    }
    return bytes_written;
}

bool read_bit(int infile, uint8_t *bit) {

    if (read_index == 0) {
        int bytes = read_bytes(infile, read_buffer, BLOCK);
        if (bytes < BLOCK) {
            read_end = bytes * 8 + 1;
        }
    }

    *bit = (read_buffer[read_index / 8] >> read_index % 8) & 0x1;

    read_index += 1;
    if (read_index == BLOCK * 8) {
        read_index = 0;
    }
    return read_index != read_end;
}
static uint8_t write_buffer[BLOCK];
static int write_index = 0;
//static int write_end=-1;
void write_code(int outfile, Code *c) {
    for (uint32_t i = 0; i < code_size(c); i += 1) {
        int bit = code_get_bit(c, i);
        if (bit == 1) {
            write_buffer[write_index / 8] |= (0x1 << write_index % 8);
        } else {
            write_buffer[write_index / 8] &= ~(0x1 << write_index % 8);
        }
        write_index += 1;
        if (write_index == BLOCK * 8) {

            flush_codes(outfile);
        }
    }
    //  printf("\nwrite_index:%d",write_index);
}
void flush_codes(int outfile) {
    if (write_index > 0) {
        //  for(int i=0;i<7 ;i+=1){
        //  	printf("\n%d",write_buffer[i]);
        //  }
        write_bytes(outfile, write_buffer, (write_index + 7) / 8);
    }
}
