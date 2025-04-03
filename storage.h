#ifndef STORAGE_H
#define STORAGE_H

#include <stdlib.h>
#include <string.h>

#define MAX_STORAGE 2048
#define BIT_SHIFT 24
#define NEXT_POINTER 0xFFFFFF
#define TERMINATOR 0xFFFFFF

unsigned char data[MAX_STORAGE];

void initStorage();
void* allocateStorage();
void releaseStorage(void* mem);

#endif