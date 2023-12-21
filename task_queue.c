#include <stdio.h>
#include <stdlib.h>
#include "sim_info.h"
#include "task_queue.h"

void initQueue( TaskQueue* q){
	q -> front = 0;
	q -> rear = 0;
	q -> tasks = (Task*)malloc(TASK_QUEUE_DEPTH * sizeof(Task));
	if( q-> tasks == NULL){
		printf("ERROR: initQueue malloc failed\n");
		exit(1);
	}
}

int isEmpty(TaskQueue* q) {
	return q -> front == q -> rear;
}

int isFull( TaskQueue* q ){
	return (q -> rear + 1 ) % TASK_QUEUE_DEPTH ==  q-> front;
}

Task enqueue ( TaskQueue* q, Task task) {
	if( isFull(q)){
		printf(" queue is full");
		return (Task){0};
	}
	q -> rear = (q -> rear + 1) % TASK_QUEUE_DEPTH;
	q -> tasks[q -> rear] = task;
	return q -> tasks[q -> rear];
}

Task dequeue ( TaskQueue* q){
	if( isEmpty(q) ) {
		return (Task){0}; 
	}
	q-> front = ( q -> front + 1) % TASK_QUEUE_DEPTH;
	return q-> tasks[q-> front];
}


