#include <iostream>
#include "fifo.h"

struct _fifo *inpbuf;
unsigned char testr[] = "hello world";
#define sizebuf (sizeof(testr)/sizeof(unsigned char))
unsigned char outbuf[24] = {0};

int main(){
	inpbuf = fifo_alloc(24);
	std::cout << sizebuf << '\n';
	fifo_put(inpbuf,testr,sizebuf);
	fifo_get(inpbuf,outbuf,sizebuf);
	std::cout << outbuf << '\n';
	fifo_free(inpbuf);
	return 0;
}


