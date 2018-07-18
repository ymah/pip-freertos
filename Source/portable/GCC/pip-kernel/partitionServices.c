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

extern enableSerialInChild();
extern disableSerialInChild();
uint32_t partitionCaller;
uint32_t * returnFunctionService;
uint32_t * returnBufferService;


void getFunctionCallInfo(){
  returnFunctionService = (uint32_t *)Pip_RemoveVAddr(partitionCaller,0x600000);

  returnBufferService = (uint32_t *)Pip_RemoveVAddr(partitionCaller,0x601000);

}

void setFunctionCallInfo(){
  if(Pip_MapPageWrapper(returnFunctionService,partitionCaller,0x600000)){
    printf("Error in mapping service result\r\n");
  }
  if(Pip_MapPageWrapper(returnBufferService,partitionCaller,0x601000)){
    printf("Error in mapping service buffer\r\n");
  }
}

void queueCreateService(uint32_t data2){

  printf("Starting QueueCreate services by %x\r\n",partitionCaller);
  uint32_t * dataCall;
  dataCall = (uint32_t*) Pip_RemoveVAddr(partitionCaller,data2);

  uint32_t length = *(dataCall);
  uint32_t size_type = *(dataCall+1);

  if(*(dataCall+2) == 0xDEADBEEF){
    printf("Everything ok...\r\n");
  }
  printf("Service requested with %d %d %x\r\n",length,size_type);
  //uint32_t *returnFct = (uint32_t*) Pip_RemoveVAddr(*(uint32_t*)pxCurrentTCB,returnCall);

  QueueHandle_t * queue = (QueueHandle_t*) pvPortMalloc(sizeof(QueueHandle_t));

  queue = xQueueCreate(length,size_type);
  *(dataCall+2) = (uint32_t*) queue;

  printf("Resuming partition with %x\r\n",queue);

  if(Pip_MapPageWrapper(dataCall,partitionCaller,data2)){
    printf("Error in mapping service result\r\n");
  }
  printf("resuming\r\n");
    enableSerialInChild();
    setFunctionCallInfo();
  resume(partitionCaller, 1);
}




 void* my_memcpy(void* destination, void* source, size_t num)
 {
 	int i;
 	char* d = destination;
 	char* s = source;
 	for (i = 0; i < num; i++) {
 		d[i] = s[i];
 	}
 	return destination;
 }


void queueSendService(uint32_t data2){

  printf("Starting QueueSend services by %x\r\n",partitionCaller);
  uint32_t * dataCall;
  dataCall = (uint32_t*) Pip_RemoveVAddr(partitionCaller,data2);

  uint32_t queue = *(dataCall);
  printf("Queue is %x\r\n",queue);
  uint32_t * itemToQueue = *(dataCall+1);
  printf("Item to Queue is %x\r\n",itemToQueue);
  uint32_t tickToWait = *(dataCall+2);
  printf("Tick to wait %x\r\n",tickToWait);


  QueueHandle_t queueToSend = (QueueHandle_t)queue; //(QueueHandle_t*) Pip_RemoveVAddr(partitionCaller,queue);
  uint32_t * dataToSend = (uint32_t *) Pip_RemoveVAddr(partitionCaller,itemToQueue);

  uint32_t * interBuffer = (uint32_t*)allocPage();
  my_memcpy(interBuffer, dataToSend, 0x1000);


  Pip_MapPageWrapper(dataToSend,partitionCaller,itemToQueue);

  uint32_t returnQueue = xQueueSend(queueToSend,(void*)interBuffer,tickToWait);

  *(uint32_t*)returnFunctionService = returnQueue;

  printf("Message waiting %d\r\n",uxQueueMessagesWaiting(queueToSend));

  if(Pip_MapPageWrapper(dataCall,partitionCaller,data2)){
    printf("Error in mapping service result\r\n");
  }
  printf("Resuming partition after sending\n",queue);
  enableSerialInChild();
  setFunctionCallInfo();
  resume(partitionCaller, 1);
}
void queueReceiveService(uint32_t data2){

  printf("Starting queueReceive services by %x\r\n",partitionCaller);
  uint32_t * dataCall;
  dataCall = (uint32_t*) Pip_RemoveVAddr(partitionCaller,data2);

  uint32_t queue = *(dataCall);
  printf("Queue is %x\r\n",queue);
  uint32_t * bufferReceive = *(dataCall+1);
  printf("Buffer to Receive is %x\r\n",bufferReceive);
  uint32_t tickToWait = *(dataCall+2);
  printf("Tick to wait %x\r\n",tickToWait);



  QueueHandle_t queueToSend = (QueueHandle_t)queue; //(QueueHandle_t*) Pip_RemoveVAddr(partitionCaller,queue);
  void * buffer = (void*) Pip_RemoveVAddr(partitionCaller,bufferReceive);
  //void * buffer = (void*) bufferReceive;

  printf("Buffer is %x\r\n",buffer);
  printf("Queue for receiving is %x\r\n",queueToSend);

  vSetTaskBuffer((uint32_t*)buffer,(uint32_t)bufferReceive);

  uint32_t returnQueue = xQueueReceive(queueToSend,buffer,tickToWait);

  *(uint32_t*)returnFunctionService = returnQueue;

  printf("Data received\r\n");

  if(Pip_MapPageWrapper(dataCall,partitionCaller,data2)){
    printf("Error in mapping service result\r\n");
  }
  // if(Pip_MapPageWrapper(buffer,partitionCaller,bufferReceive)){
  //   printf("Error in mapping service result\r\n");
  // }
  printf("Resuming partition after receiving\n");
  enableSerialInChild();
  setFunctionCallInfo();
  resume(partitionCaller, 1);
}


void sbrkService(uint32_t data2){



  printf("Starting sbrk services by %x\r\n",partitionCaller);
  uint32_t * dataCall;
  dataCall = (uint32_t*) Pip_RemoveVAddr(partitionCaller,data2);

  uint32_t size = *(dataCall);
  uint32_t begin = *(dataCall+1);
  printf("Allocating memory %d pages at %x\r\n",size,begin);

  int index;
  uint32_t page;
  for(index=0;index<size;index++){
    page = allocPage();
    if(Pip_MapPageWrapper(page,partitionCaller,begin+(index*0x1000))){
      printf("Error in mapping sbrk call\r\n");
      for(;;);
    }

    //printf("Allocating %x at %x\r\n",page,begin+(index*0x1000));
  }
  if(Pip_MapPageWrapper(dataCall,partitionCaller,data2)){
    printf("Error in mapping service result\r\n");
  }
  printf("return from sbrk service\r\n" );
  enableSerialInChild();
  setFunctionCallInfo();
  resume(partitionCaller, 1);

}


void channelService(uint32_t data2){

  printf("Starting channel services by %x\r\n",partitionCaller);

  uint32_t * partitionList = getPartitionList();
  uint32_t numberOfPartition = getNumberOfPartition();


  uint32_t * dataCall;
  dataCall = (uint32_t*) Pip_RemoveVAddr(partitionCaller,data2);

  uint32_t number = *(dataCall);
  uint32_t * listOfChannel = *(dataCall+1);

  uint32_t * channel = (uint32_t*) Pip_RemoveVAddr(partitionCaller,listOfChannel);

  int i,j;
  uint32_t * pageChannel;
  for(i = 0;i<numberOfPartition;i++){
    pageChannel = (uint32_t*) allocPage();
    for(j = 0;j<number;j++){
      pageChannel[j] = channel[j];
    }
    if(Pip_MapPageWrapper(pageChannel,partitionList[i],0xBAAD0000)){
      printf("Error in mapping service result\r\n");
    }

  }

  printf("return from channelCom service service\r\n" );
  enableSerialInChild();
setFunctionCallInfo();
  resume(partitionCaller, 1);

}



INTERRUPT_HANDLER(serviceRoutineAsm,serviceRoutine)
  Pip_VCLI();
  disableSerialInChild();
  printf("Starting service data1 %d, data2 %x \r\n",data1,data2);


  partitionCaller = *(uint32_t*)pxCurrentTCB;
  getFunctionCallInfo();

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
    case channelCom:
        channelService(data2);
        break;
    default:
      __asm__ volatile("call vPortTimerHandler");
  }
      //__asm__ volatile("call vPortTimerHandler");
END_OF_INTERRUPT



void initPartitionServices(){

  registerInterrupt(0x80, &serviceRoutineAsm, (uint32_t*) 0x2020000);

}
