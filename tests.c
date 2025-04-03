#include "queue.h"
#include "tests.h"
#include "errors.h"
#include <stdio.h>
#include <assert.h>

void run_test()
{
	initStorage();

	Q* q0 = createQueue();

	enqueueByte(q0, 0);
	enqueueByte(q0, 1);

	Q* q1 = createQueue();

	enqueueByte(q1, 3);
	enqueueByte(q0, 2);
	enqueueByte(q1, 4);

	printf("%d", dequeueByte(q0));
	printf("%d\n", dequeueByte(q0));

	enqueueByte(q0, 5);
	enqueueByte(q1, 6);

	printf("%d", dequeueByte(q0));
	printf("%d\n", dequeueByte(q0));

	destroyQueue(q0);

	printf("%d", dequeueByte(q1));
	printf("%d", dequeueByte(q1));
	printf("%d\n", dequeueByte(q1));

	destroyQueue(q1);

}

void testEmptyQueue()
{
	Q* q3 = createQueue();

	dequeueByte(q3);

	assert(getLastError() == ERR_ILLEGAL_OP);
	resetError();

	destroyQueue(q3);
}

void testSingleItemQueue()
{
	Q* q4 = createQueue();

	enqueueByte(q4, 7);

	assert(dequeueByte(q4) == 7);

	destroyQueue(q4);
}

void testTerminatingBehavior()
{
	Q* q5 = createQueue();

	enqueueByte(q5, 8);
	enqueueByte(q5, 9);

	assert(dequeueByte(q5) == 8);
	assert(dequeueByte(q5) == 9);

	dequeueByte(q5);

	assert(getLastError() == ERR_ILLEGAL_OP);
	resetError();

	destroyQueue(q5);
}

void runAdditionalTests()
{
	testEmptyQueue();
	testSingleItemQueue();
	testTerminatingBehavior();
	printf("All tests passed!\n");
}