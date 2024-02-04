#include <stdio.h>
#include <stdlib.h>
#include "sim_info.h"
#include "task_queue.h"

void initQueue( task_queue_t* q){

	q -> front = malloc(sizeof(q_ptr_t));
	if( q-> front == NULL){
		printf("ERROR: initQueue malloc failed\n");
		exit(1);
	}
	q -> rear = malloc(sizeof(q_ptr_t));
	if( q-> rear == NULL){
		printf("ERROR: initQueue malloc failed\n");
		exit(1);
	}
	q -> front -> ptr = 0;
	q -> front -> phase = 0;
	q -> rear -> ptr = 0;
	q -> rear -> phase = 0;
	q -> num_of_entries = 0;

	q -> tasks = (task_t*)malloc(TASK_QUEUE_DEPTH * sizeof(task_t));
	if( q-> tasks == NULL){
		printf("ERROR: initQueue malloc failed\n");
		exit(1);
	}
}

int isEmpty(task_queue_t* q) {
	return (q -> rear -> ptr == q-> front -> ptr) && (q -> rear -> phase == q ->front -> phase);
}

int isFull( task_queue_t* q ){
	return (q -> rear -> ptr == q-> front -> ptr) && (q -> rear -> phase != q ->front -> phase);
}

int enqueue ( task_queue_t* q, task_t task) {
	if( isFull(q)){
		printf(" queue is full");
		return -1;
	}
	q -> tasks[q -> rear -> ptr] = task;
	q -> rear -> ptr = (q -> rear -> ptr + 1) % TASK_QUEUE_DEPTH;
	if (q -> rear -> ptr == 0) {
		q -> rear -> phase = (q -> rear -> phase + 1) % 2;
	}
	q -> num_of_entries++;
	return 0;
}

int dequeue ( task_queue_t* q, task_t* task){
	if( isEmpty(q) ) {
		printf(" queue is empty");
		return -1;
	}
	if (task != NULL) {
		*task = q->tasks[q->front->ptr];
//		memcpy(task, &q->tasks[q->front->ptr], sizeof(task_t));
	}
	else {
		printf("task should not be NULL!");
		return -2;
	}
	q-> front -> ptr = ( q -> front -> ptr + 1) % TASK_QUEUE_DEPTH;
	if (q -> front -> ptr == 0) {
		q -> front -> phase = (q -> front -> phase + 1) % 2;
	}
	q -> num_of_entries--;
	return 0;
}


