#include<stdio.h>

int main(){
	const int MAX = 100;
	FILE *inputFile = fopen("workload.txt","r");
	FILE *outputFile = fopen("result.txt", "w");


	const int SECTOR_SIZE = 512; // 1 sector = 512 bytes
    const int SEEK_TIME = 15; // ms
    const int ROTATE_LATENCY = 8; // ms
    const double TRANSFER_RATE = 50; // Byte/ms
    const int COMMAND_OVERHEAD = 30; // ms
    const int QUEUE_LENGTH = 10000; // request count
    const double ERROR_RATE = 0.0001; // percentage
    const double CYCLE_POWER_CONSUMPTION = 0.01; // W  


	if(inputFile == NULL){
		perror("ERROR: inputFile open failed");
		return 1;
	}
	if(outputFile == NULL){
		perror("ERROR: outputFile open failed");
		fclose(inputFile);
		return 1;
	}
	
	char line[MAX];
	char requestType;
	int logicalAddress;
	int sectorCount;

	int totalBytes = 0;
	int totalSectors = 0;
	int totalTime = 0;
	double totalPower = 0.0;

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
	return 0;
}
