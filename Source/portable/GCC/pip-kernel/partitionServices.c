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
  resume(partitionCaller, 0);
}


struct AMessage
 {
    char ucMessageID;
    char ucData[ 20 ];
 } xMessage;

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

  //printf("Data to send %x\r\n",dataToSend);
  //int i;
  //for(i=0;i<20;i++)
    //printf("%d\n",dataToSend->ucData[i] );
  xQueueSend(queueToSend,(void*)dataToSend,tickToWait);

  printf("Message waiting %d\r\n",uxQueueMessagesWaiting(queueToSend));
  if(Pip_MapPageWrapper(dataCall,partitionCaller,data2)){
    printf("Error in mapping service result\r\n");
  }
  printf("Resuming partition after sending\n",queue);

  resume(partitionCaller, 0);
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
  printf("Buffer is %x\r\n",buffer);
  printf("Queue for receiving is %x\r\n",queueToSend);
  xQueueReceive(queueToSend,buffer,tickToWait);

  printf("Message waiting %d\r\n",uxQueueMessagesWaiting(queueToSend));

  printf("Data received\r\n");
  if(Pip_MapPageWrapper(dataCall,partitionCaller,data2)){
    printf("Error in mapping service result\r\n");
  }
  if(Pip_MapPageWrapper(buffer,partitionCaller,bufferReceive)){
    printf("Error in mapping service result\r\n");
  }
  printf("Resuming partition after receiving\n");

  resume(partitionCaller, 0);
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

  resume(partitionCaller, 0);

}

void vTaskGetRunTimeStats(char *pcWriteBuffer)
{
  TaskStatus_t *pxTaskStatusArray;
  volatile UBaseType_t uxArraySize, x;
  unsigned long ulTotalRunTime, ulStatsAsPercentage;

   /* Make sure the write buffer does not contain a string. */
   //*pcWriteBuffer = 0x00;

   /* Take a snapshot of the number of tasks in case it changes while this
   function is executing. */
   uxArraySize = uxTaskGetNumberOfTasks;

   /* Allocate a TaskStatus_t structure for each task.  An array could be
   allocated statically at compile time. */
   pxTaskStatusArray = pvPortMalloc( uxArraySize * sizeof( TaskStatus_t ) );

   if( pxTaskStatusArray != NULL )
   {
      /* Generate raw status information about each task. */
      uxArraySize = uxTaskGetSystemState( pxTaskStatusArray,uxArraySize,&ulTotalRunTime );

      /* For percentage calculations. */
      ulTotalRunTime /= 100UL;

      /* Avoid divide by zero errors. */
      if( ulTotalRunTime > 0 )
      {
         /* For each populated position in the pxTaskStatusArray array,
         format the raw data as human readable ASCII data. */
         for( x = 0; x < uxArraySize; x++ )
         {
            /* What percentage of the total run time has the task used?
            This will always be rounded down to the nearest integer.
            ulTotalRunTimeDiv100 has already been divided by 100. */
            ulStatsAsPercentage = pxTaskStatusArray[ x ].ulRunTimeCounter / ulTotalRunTime;

            if( ulStatsAsPercentage > 0UL )
            {
               printf("%s\t\t%lu\t\t%lu%%\r\n",pxTaskStatusArray[ x ].pcTaskName,pxTaskStatusArray[ x ].ulRunTimeCounter,ulStatsAsPercentage );
            }
            else
            {
               /* If the percentage is zero here then the task has
               consumed less than 1% of the total run time. */
               printf("%s\t\t%lu\t\t<1%%\r\n",pxTaskStatusArray[ x ].pcTaskName,pxTaskStatusArray[ x ].ulRunTimeCounter );
            }


         }
      }

      /* The array is no longer needed, free the memory it consumes. */
      vPortFree( pxTaskStatusArray );
   }
}


void channelService(uint32_t data2){

  printf("Starting channel services by %x\r\n",partitionCaller);
  vTaskGetRunTimeStats((char *)0);
  for(;;);

  uint32_t * dataCall;
  dataCall = (uint32_t*) Pip_RemoveVAddr(partitionCaller,data2);

  uint32_t id = *(dataCall);
  uint32_t * listOfChannel = *(dataCall+1);

  uint32_t * channel = (uint32_t*) Pip_RemoveVAddr(partitionCaller,listOfChannel);



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
