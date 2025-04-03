#include "errors.h"
#include <stdio.h>
#include <stdlib.h>

ErrorCode lastError = ERR_NONE;

void resetError()
{
	lastError = ERR_NONE;
}

ErrorCode getLastError()
{
	return lastError;
}

void errOutOfMemory()
{
	lastError = ERR_OUT_OF_MEMORY;
	printf("ERROR: Not enough momory.\n");
}

void errIllegalOperation()
{
	lastError = ERR_ILLEGAL_OP;
	printf("ERROR: Illegal operation.\n");
}
