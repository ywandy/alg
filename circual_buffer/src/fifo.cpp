#include "fifo.h"
/*
 * 圆形缓存区
 * 参照kfifo,c
 * yewei_andy
 * */
struct _fifo *fifo_init(unsigned char *buffer, unsigned int size)
{
	struct _fifo *fifo;
	fifo = (struct _fifo *)malloc(sizeof(struct _fifo));
	if (!fifo)
		printf("malloc failed\n");
	fifo->buf = buffer;
	fifo->size = size;
	fifo->in = fifo->out = 0;
	return fifo;
}

struct _fifo *fifo_alloc(unsigned int size){
	unsigned char *buffer;
	struct _fifo *ret;
	buffer = (unsigned char *)malloc(size*sizeof(unsigned char));
	if(!buffer)
		printf("malloc failed\n");
	ret = fifo_init(buffer,size);
	return ret;
}

void fifo_free(struct _fifo *fifo){
	free(fifo->buf);
	free(fifo);
}

unsigned int fifo_put(struct _fifo *fifo,unsigned char *buffer,unsigned int len){
	unsigned int l;
	len = min(len, fifo->size - fifo->in + fifo->out);
	l = min(len, fifo->size - (fifo->in & (fifo->size -1)));
	memcpy(fifo->buf + (fifo->in & (fifo->size -1)), buffer ,l);
	memcpy(fifo->buf, buffer + l, len - l);
	fifo->in += len;
	return len;
}


unsigned int fifo_get(struct _fifo *fifo,unsigned char *buffer, unsigned int len)
{
	unsigned int l;
	len = min(len, fifo->in - fifo->out);
	l = min(len, fifo->size - (fifo->out & (fifo->size - 1)));
	memcpy(buffer, fifo->buf + (fifo->out & (fifo->size - 1)), l);
	memcpy(buffer + l, fifo->buf, len - l);
	fifo->out += len;
	return len;
}
