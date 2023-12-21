#ifndef SIM_INFO_H
#define SIM_INFO_H

#define SECTOR_SIZE 			512	// 1 sector = 512 bytes
#define SEEK_TIME				15 // ms
#define ROTATE_LATENCY 			8 // ms
#define TRANSFER_RATE			50 // Byte/ms
#define COMMAND_OVERHEAD		30 // ms
#define ERROR_RATE				(0.0001) // percentage
#define CYCLE_POWER_CONSUMPTION	(0.01) // Watt
#define TASK_QUEUE_DEPTH 32 // queue depth 32


#endif
