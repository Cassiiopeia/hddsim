#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "sim_info.h"
#include "task_queue.h"

void generate_task(task_t* task) {
	static int pattern_idx = 0;
	
	task->requestType = pattern_idx % 2;
	task->logicalAddress = (pattern_idx + 2) * 10 + 3;
	task->sectorCount = (pattern_idx + 1) * 8;
	pattern_idx++;
}

int examine_task(task_t* task) {
	static int examine_pattern_idx = 0;

	examine_patter_idx++;
	return 0;
}

void testTaskQueue_enqueue(task_queue_t* task_queue) {
	task_t task;
	int qd = TASK_QUEUE_DEPTH;
	int idx;
	int ret;


	for (idx = 0; idx < TASK_QUEUE_DEPTH + 10; idx++) {
		// DONE: generate 'task's for experiments
		generate_task(&task);
		
		ret = enqueue(task_queue, task);
		if (ret < 0) {
			break;
		}
	}

	if (ret == -1) {
		printf("Full test success!\n");
	}
	else {
		printf("Full test fail!\n");
	}
}

void testTaskQueue_dequeue(task_queue_t* task_queue) {
	int idx;
	int ret;
	int correct;
	task_t task;
	testTaskQueue_enqueue(task_queue);

	for (idx = 0; idx < TASK_QUEUE_DEPTH + 10; idx++)
	{
		ret = dequeue(task_queue, &task);
		if (ret < 0) {
			break;
		}
		correct = examine_task(&task);
	}

	if (ret == -1) {
		printf("Empty test success!\n");
	}
	else {
		printf("Empty test fail!\n");
	}
}

void testTaskQueue() {
	task_queue_t* task_queue;
	task_queue = (task_queue_t*) malloc(sizeof(task_queue_t));
	initQueue(task_queue);

	testTaskQueue_enqueue(task_queue);


	task_queue_new = (task_queue_t*) malloc(sizeof(task_queue_t));
	initQueue(task_queue_new);

	testTaskQueue_dequeue(task_queue_new);


}
