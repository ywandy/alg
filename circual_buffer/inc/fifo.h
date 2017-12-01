#ifndef _FIFO_H_
#define _FIFO_H_
#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "string.h"

#define min(a,b) ((a)<(b)?(a):(b))
/*
 * 圆形缓存区
 * 参照kfifo,c
 * yewei_andy
 * */
struct _fifo{
  unsigned int in;
  unsigned int out;
  unsigned int size;
  unsigned char *buf;
};
struct _fifo *fifo_init(unsigned char *buffer, unsigned int size);
struct _fifo *fifo_alloc(unsigned int size);
void fifo_free(struct _fifo *fifo);
unsigned int fifo_put(struct _fifo *fifo,unsigned char *buffer,unsigned int len);
unsigned int fifo_get(struct _fifo *fifo,unsigned char *buffer, unsigned int len);
#endif
