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

  printf("Starting QueueCreate services by %x\r\n",partitionCaller);
  uint32_t * dataCall;
  dataCall = (uint32_t*) Pip_RemoveVAddr(partitionCaller,data2);

  uint32_t length = *(dataCall);
  uint32_t size_type = *(dataCall+1);

  if(*(dataCall+2) == 0xDEADBEEF){
    printf("Evrything ok...\r\n");
  }
  printf("Service requested with %d %d %x\r\n",length,size_type);
  //uint32_t *returnFct = (uint32_t*) Pip_RemoveVAddr(*(uint32_t*)pxCurrentTCB,returnCall);

  QueueHandle_t * queue = (QueueHandle_t*) pvPortMalloc(sizeof(QueueHandle_t));

  queue = xQueueCreate(length,size_type);
  *(dataCall+2) = (uint32_t*) queue;
  printf("Resuming partition with %x at %x\r\n",*(dataCall+2));

  if(Pip_MapPageWrapper(dataCall,partitionCaller,data2)){
    printf("Error in mapping service result\r\n");
  }
  printf("resuming\r\n");
  resume(partitionCaller, 0);
}
void queueSendService(uint32_t data2){

  printf("Starting QueueSend services by %x\r\n",partitionCaller);
  uint32_t * dataCall;
  dataCall = (uint32_t*) Pip_RemoveVAddr(partitionCaller,data2);

  uint32_t queue = *(dataCall);
  uint32_t * itemToQueue = *(dataCall+1);
  uint32_t tickToWait = *(dataCall+2);

  printf("Data for sending : %x %x %x\r\n",queue,itemToQueue,tickToWait);

  QueueHandle_t * queueToSend = (QueueHandle_t*) Pip_RemoveVAddr(partitionCaller,queue);
  void * dataToSend = (void*) Pip_RemoveVAddr(partitionCaller,itemToQueue);

  xQueueSend(queueToSend,dataToSend,tickToWait);


  printf("Resuming partition with %x\n",queue);

  resume(partitionCaller, 0);
}
void queueReceiveService(uint32_t data2){

  printf("Starting QueueReceive services by %x\r\n",partitionCaller);
  uint32_t * dataCall;
  dataCall = (uint32_t*) Pip_RemoveVAddr(partitionCaller,data2);

  uint32_t length = *(dataCall+1);
  uint32_t size_type = *(dataCall+2);

  QueueHandle_t * queue = (QueueHandle_t*) pvPortMalloc(sizeof(QueueHandle_t));

  //queue = send(length,size_type);

  printf("Resuming partition with %x\n",queue);

  resume(partitionCaller, 0);
}


void sbrkService(uint32_t data2){



  printf("Starting sbrk services by %x\r\n",*(uint32_t*)pxCurrentTCB);
  //dataCall = (uint32_t*) Pip_RemoveVAddr(*(uint32_t*)pxCurrentTCB,data2);
  //uint32_t * dataCall;
  printf("Allocating memory %d pages \r\n",data2);

  int index;

    uint32_t * page = allocPage();
    uint32_t * firstPage = page;
    printf("First page %x\r\n",firstPage);
  for(index=0;index<12;index++){

    if(Pip_MapPageWrapper(page,partitionCaller,page)){
      printf("Error in mapping sbrk call\r\n");
    }
    page = allocPage();
    printf("Allocating %x\r\n",page);
  }

  printf("Mapping first page %x at %x\r\n",firstPage);
  Pip_Notify(partitionCaller,0x81,firstPage,0);
  printf("return from sbrk service\r\n" );
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
    case queueSend:
      queueSendService(data2);
      break;
    case queueReceive:
      queueReceiveService(data2);
      break;
    case sbrk:
      sbrkService(data2);
      break;
    default:
      __asm__ volatile("call vPortTimerHandler");
  }
      //__asm__ volatile("call vPortTimerHandler");
END_OF_INTERRUPT



void initPartitionServices(){

  registerInterrupt(0x80, &serviceRoutineAsm, (uint32_t*) 0x2020000);

}
