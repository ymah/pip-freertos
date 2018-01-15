#ifndef _PARTITION_SERVICES_H
#define _PARTITION_SERVICES_H
#include <stdint.h>
/*
 * each service is associated to a unique identifier
 *
 *
 */

 struct xQueueCreateParameters_s {
   uint32_t lenght;
   uint32_t size_type;
 };

 typedef struct xQueueCreateParameters_s xQueueCreateParameters;




#define queueCreate     0x15
#define queueSend       0x16
#define queueReceive    0x17


void initPartitionServices();

#endif
