#ifndef ERRORS_H
#define ERRORS_H

typedef enum {
	ERR_NONE = 0,
	ERR_OUT_OF_MEMORY,
	ERR_ILLEGAL_OP
} ErrorCode;
extern ErrorCode lastError;

void resetError();
ErrorCode getLastError();
void errOutOfMemory();
void errIllegalOperation();

#endif