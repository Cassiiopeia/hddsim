#ifndef TASK_QUEUE_H
#define TASK_QUEUE_H

#define READ 	0
#define WRITE 	1

typedef struct {
	int requestType; // R or W
	int logicalAddress;
	int sectorCount;
} task_t;

typedef struct {
	int ptr;
	int phase;
} q_ptr_t;

typedef struct {
	task_t* tasks;
	q_ptr_t* front;
	q_ptr_t* rear;
	int num_of_entries;
} task_queue_t;

void initQueue(task_queue_t* q);
int isEmpty(task_queue_t* q);
int isFull(task_queue_t* q);
int enqueue(task_queue_t* q, task_t task);
// void enqueue(task_queue_t* q, task_t task);
int dequeue(task_queue_t* q, task_t* task);
// task_t dequeue(task_queue_t* q);

#endif
