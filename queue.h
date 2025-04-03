#ifndef QUEUE_H
#define QUEUE_H

#include "storage.h" 
#include "errors.h"

typedef void Q;

Q* createQueue();
void destroyQueue(Q* q);
void enqueueByte(Q* q, unsigned char byte);
unsigned char dequeueByte(Q* q);

#endif

