#include "storage.h"
#include "errors.h"

void initStorage()
{
	memset(data, 0, MAX_STORAGE);
	unsigned int* nextFreeSpace = (unsigned int*)data;
	*nextFreeSpace = sizeof(unsigned int);
}

void* allocateStorage()
{
	unsigned int* nextFreeSpace = (unsigned int*)data;

	if (*nextFreeSpace == 0 || *nextFreeSpace >= MAX_STORAGE)
	{
		errOutOfMemory();

		return NULL;
	}

	unsigned int* cell = (unsigned int*)(data + *nextFreeSpace);

	if (*cell == 0)
	{
		*nextFreeSpace += sizeof(unsigned int);
		if (*nextFreeSpace >= MAX_STORAGE)
		{
			errOutOfMemory();

			return NULL;
		}
	}
	else
	{
		*nextFreeSpace = *cell;
	}

	*cell = 0;

	return cell;
}

void releaseStorage(void* mem)
{
	if (mem == NULL || (unsigned char*)mem < data ||
		(unsigned char*)mem >= data + MAX_STORAGE)
	{
		errIllegalOperation();

		return 0;
	}

	unsigned int* nextFreeSpace = (unsigned int*)data;
	unsigned int* cell = (unsigned int*)mem;

	*cell = *nextFreeSpace;
	*nextFreeSpace = (unsigned char*)mem - data;
}