#include<stdio.h>
#include<stdlib.h>
#include "task_queue.h"
#include "sim_info.h"

#define MAX 					100	

int main(){
	
	char line[MAX];
	char requestType;
	int logicalAddress;
	int sectorCount;

	int totalBytes = 0;
	int totalSectors = 0;
	int totalTime = 0;
	double totalPower = 0.0;

	FILE *inputFile = fopen("workload.txt","r");
	FILE *outputFile = fopen("result.txt", "w");

	if(inputFile == NULL){
		perror("ERROR: inputFile open failed");
		return 1;
	}
	if(outputFile == NULL){
		perror("ERROR: outputFile open failed");
		fclose(inputFile);
		return 1;
	}

	TaskQueue* taskQueue = (TaskQueue*)malloc(sizeof(TaskQueue));;;
	if( taskQueue == NULL){
		printf("ERROR : taskQueue malloc failed");
		return 1;
	}

	initQueue(taskQueue);


	while(fgets(line, sizeof(line), inputFile) != NULL ){
		sscanf(line, "%c %d %d",
			   	&requestType, &logicalAddress, &sectorCount );
		totalSectors += sectorCount;
		totalBytes = sectorCount * SECTOR_SIZE;
		totalTime = COMMAND_OVERHEAD + SEEK_TIME +
		   	ROTATE_LATENCY + (totalBytes / TRANSFER_RATE) ;
		totalPower += CYCLE_POWER_CONSUMPTION ;
	}
	
	fprintf(outputFile, 
				"<< HDDSIM-TEST-RESULT >>\n"\
				"Total Sectors = %d\n"\
				"Total Time = %d ms\n"\
				"Total Power = %.2f W",
				totalSectors, totalTime, totalPower);

	fclose(inputFile);
	fclose(outputFile);
	free(taskQueue->tasks);
	free(taskQueue);
	return 0;
}
