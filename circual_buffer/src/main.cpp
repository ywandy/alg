#include <iostream>
#include "fifo.h"

struct _fifo *inpbuf;
unsigned char testr[] = "hello world";

#define sizebuf (sizeof(testr)/sizeof(unsigned char))
unsigned char outbuf[24] = {0};
unsigned char outbuf1[24] = {0};
unsigned char outbuf2[24] = {0};
int main(){
	inpbuf = fifo_alloc(8);
	std::cout << sizebuf << '\n';
	fifo_put(inpbuf,testr,8);
	fifo_get(inpbuf,outbuf,2);
	std::cout << outbuf << '\n';

	fifo_put(inpbuf,(unsigned char *)"gg",2);
	fifo_get(inpbuf,outbuf2,2);
	std::cout << outbuf2 << '\n';

	fifo_get(inpbuf,outbuf1,8);
	std::cout << outbuf1 << '\n';
	fifo_free(inpbuf);
	return 0;
}


