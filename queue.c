#include "queue.h"

Q* createQueue()
{
	unsigned int* queue = (unsigned int*)allocateStorage();
	*queue = 0;

	return (Q*)queue;
}

void destroyQueue(Q* q)
{
	if (q == NULL)
	{
		errIllegalOperation();

		return;
	}

	unsigned int* queue = (unsigned int*)q;
	unsigned int next = *queue & NEXT_POINTER;

	while (next != 0 && next != TERMINATOR)
	{
		unsigned char* mem = data + next;
		unsigned int* cell = (unsigned int*)mem;
		next = *cell & NEXT_POINTER;
		releaseStorage(mem);
	}

	releaseStorage(q);
}

void enqueueByte(Q* q, unsigned char byte)
{
	if (q == NULL)
	{
		errIllegalOperation();

		return 0;
	}

	unsigned int* queue = (unsigned int*)q;

	if (*queue == 0)
	{
		*queue = ((unsigned int)byte << BIT_SHIFT) | TERMINATOR;
	}
	else
	{
		unsigned int next = *queue & NEXT_POINTER;
		unsigned int prev = 0;

		if (next == TERMINATOR)
		{
			prev = 0;
		}
		else
		{
			while (next != 0)
			{
				unsigned char* mem = data + next;
				unsigned int* cell = (unsigned int*)mem;
				prev = next;
				next = *cell & NEXT_POINTER;
			}
		}

		unsigned int* cell = (unsigned int*)allocateStorage();
		*cell = (unsigned int)byte << BIT_SHIFT;


		unsigned int* lastCell;
		if (prev == 0)
		{
			lastCell = queue;
		}
		else
		{
			lastCell = (unsigned int*)(data + prev);
		}

		*lastCell = (*lastCell & ~NEXT_POINTER) |
			((unsigned char*)cell - data);
	}
}

unsigned char dequeueByte(Q* q)
{
	if (q == NULL)
	{
		errIllegalOperation();

		return 0;
	}

	unsigned int* queue = (unsigned int*)q;
	if (*queue == 0)
	{
		errIllegalOperation();

		return 0;
	}

	unsigned char value = (unsigned char)(*queue >> BIT_SHIFT);

	unsigned int next = *queue & NEXT_POINTER;

	if (next != 0 && next != TERMINATOR)
	{
		unsigned int* cell = (unsigned int*)(data + next);
		*queue = *cell;

		releaseStorage(cell);
	}
	else
	{
		*queue = 0;
	}

	return value;
}
