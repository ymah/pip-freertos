/* Standard includes. */
#include <limits.h>
#include <stdint.h>
/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "StackMacros.h"

#include "pip/vidt.h"
#include "pip/api.h"
#include "pip/compat.h"
#include "partitionServices.h"


extern void * pxCurrentTCB;
int checkAccess(){
  return 1;
}

uint32_t partitionCaller;
void queueCreateService(uint32_t data2){

  printf("Starting QueueCreate services by %x\r\n",*(uint32_t*)pxCurrentTCB);
  uint32_t * dataCall;
  dataCall = (uint32_t*) Pip_RemoveVAddr(*(uint32_t*)pxCurrentTCB,data2);

  uint32_t length = *(dataCall+1);
  uint32_t size_type = *(dataCall+2);

  QueueHandle_t * queue = (QueueHandle_t*) pvPortMalloc(sizeof(QueueHandle_t));

  queue = xQueueCreate(length,size_type);

  printf("Resuming partition with %x\n",queue);
  //__asm__ volatile ("push %%eax; mov %0, %%eax; pop %%eax"::"r"(queue):"%eax");
  //__asm__ volatile("call vPortTimerHandler");

  //__asm__ volatile("push %eax; mov %0,%%eax; pop %%eax"::"r"(queue):);
  resume(partitionCaller, 0);
}


INTERRUPT_HANDLER(serviceRoutineAsm,serviceRoutine)
  printf("Starting service ");
  printf("Data1 %d, data2 %x\r\n",data1,data2);
  partitionCaller = caller;
  if(!checkAccess())
    printf("No rights for this partition\r\n");
  switch (data1) {
    case queueCreate:
          queueCreateService(data2);
      break;
    default:
      __asm__ volatile("call vPortTimerHandler");
  }
      //__asm__ volatile("call vPortTimerHandler");
END_OF_INTERRUPT



void initPartitionServices(){

  registerInterrupt(0x80, &serviceRoutineAsm, (uint32_t*) 0x2020000);

}
