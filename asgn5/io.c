#include "io.h"
#include <unistd.h>
#include "defines.h"
#include <stdio.h>
#include "fcntl.h"
#include <stdint.h>
static uint8_t read_buffer[BLOCK];
static int read_index =0;
static int read_end=-1;
uint64_t bytes_read=0;
uint64_t bytes_written=0;

int read_bytes(int infile, uint8_t *buf, int nbytes){
	int br=0;
	while(read(infile,buf+bytes_read,nbytes-bytes_read)>0&&nbytes!=br){
		bytes_read+=1;
		br=bytes_read;
		
		
	}
	return bytes_read;
		
}
int write_bytes(int outfile, uint8_t *buf, int nbytes){
	int bw=0;
	while(write(outfile,buf+bytes_written,nbytes-bytes_written)>0&&nbytes!=bw){
        	bytes_written+=1;
		bw= bytes_written;
        	}	
	return bytes_written;
}
bool read_bit(int infile, uint8_t *bit){

	if(read_index==0){
		int bytes = read_bytes(infile,read_buffer,BLOCK);
		if(bytes<BLOCK){
		read_end=bytes*8 +1;
		}
	}

	*bit=(read_buffer[read_index/8] >> read_index% 8)& 0x1;
	
	
	read_index+=1;
	if(read_index==BLOCK*8){
		read_index=0;
	}
	return read_index != read_end;
}
static uint8_t write_buffer[BLOCK];
static int write_index =0;
//static int write_end=-1;
void write_code(int outfile, Code *c){
	for ( uint32_t i=0;i<code_size(c);i+=1){
		int bit = code_get_bit(c,i);
		if(bit==1){
			write_buffer[i/8] |= (0x1 << i % 8);
		}
		else{
			write_buffer[i/8] &= ~(0x1 << i % 8);
		}
		write_index+=1;
		if(write_index==BLOCK*8){
			flush_codes(outfile);
		}
	}
}
void flush_codes(int outfile){
	if(write_index>0){
		write_bytes(outfile,write_buffer,write_index/8);
	}
}

