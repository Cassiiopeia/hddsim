#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

typedef struct {
	char requestType; // R or W
	int logicalAddress;
	int sectorCount;
} Task;

typedef struct {
	Task* tasks;
	int front;
	int rear;
} TaskQueue;

void initQueue(TaskQueue* q);
int isEmpty(TaskQueue* q);
int isFull(TaskQueue* q);
Task enqueue(TaskQueue* q, Task task);
Task dequeue(TaskQueue* q);

#endif
