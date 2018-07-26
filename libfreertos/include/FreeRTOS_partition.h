#ifndef _FREERTOS_ACCESS_h
#define _FREERTOS_ACCESS_h
#ifndef anyIntAsm
	#define anyIntAsm 0x00700144
#endif

#ifndef anyIntHandler
	#define anyIntHandler 0x00704743
#endif

#ifndef __Arch_APICall_0
	#define __Arch_APICall_0 0x0070071e
#endif

#ifndef __Arch_APICall_1
	#define __Arch_APICall_1 0x00700740
#endif

#ifndef __Arch_APICall_2
	#define __Arch_APICall_2 0x007007a7
#endif

#ifndef __Arch_APICall_3
	#define __Arch_APICall_3 0x0070081b
#endif

#ifndef __Arch_APICall_4
	#define __Arch_APICall_4 0x00700821
#endif

#ifndef __Arch_APICall_5
	#define __Arch_APICall_5 0x00700852
#endif

#ifndef __Arch_APICall_6
	#define __Arch_APICall_6 0x0070089b
#endif

#ifndef channelService
	#define channelService 0x00705027
#endif

#ifndef checkAccess
	#define checkAccess 0x007049a6
#endif

#ifndef code
	#define code 0x00700000
#endif

#ifndef collect
	#define collect 0x00700aaa
#endif

#ifndef createPartition
	#define createPartition 0x007009ea
#endif

#ifndef debug1
	#define debug1 0x00708560
#endif

#ifndef deletePartition
	#define deletePartition 0x00700a9e
#endif

#ifndef disableSerialInChild
	#define disableSerialInChild 0x00702631
#endif

#ifndef dispatch
	#define dispatch 0x00700a4e
#endif

#ifndef dRegTest1_st1
	#define dRegTest1_st1 0x00709240
#endif

#ifndef dRegTest1_st2
	#define dRegTest1_st2 0x00709238
#endif

#ifndef dRegTest1_st3
	#define dRegTest1_st3 0x00709230
#endif

#ifndef dRegTest1_st4
	#define dRegTest1_st4 0x00709228
#endif

#ifndef dRegTest1_st5
	#define dRegTest1_st5 0x00709220
#endif

#ifndef dRegTest1_st6
	#define dRegTest1_st6 0x00709218
#endif

#ifndef dRegTest1_st7
	#define dRegTest1_st7 0x00709210
#endif

#ifndef dRegTest2_st1
	#define dRegTest2_st1 0x00709278
#endif

#ifndef dRegTest2_st2
	#define dRegTest2_st2 0x00709270
#endif

#ifndef dRegTest2_st3
	#define dRegTest2_st3 0x00709268
#endif

#ifndef dRegTest2_st4
	#define dRegTest2_st4 0x00709260
#endif

#ifndef dRegTest2_st5
	#define dRegTest2_st5 0x00709258
#endif

#ifndef dRegTest2_st6
	#define dRegTest2_st6 0x00709250
#endif

#ifndef dRegTest2_st7
	#define dRegTest2_st7 0x00709248
#endif

#ifndef enableSerialInChild
	#define enableSerialInChild 0x0070257b
#endif

#ifndef Galileo_Gen2_Init_IO7_and_IO8
	#define Galileo_Gen2_Init_IO7_and_IO8 0x0070624d
#endif

#ifndef Galileo_Gen2_Set_IO_Direction
	#define Galileo_Gen2_Set_IO_Direction 0x007062b3
#endif

#ifndef Galileo_Gen2_Set_IO_Level
	#define Galileo_Gen2_Set_IO_Level 0x00706503
#endif

#ifndef galileoSerialGetc
	#define galileoSerialGetc 0x00700cbe
#endif

#ifndef galileoSerialPrintc
	#define galileoSerialPrintc 0x00700c5b
#endif

#ifndef galileoSerialPrints
	#define galileoSerialPrints 0x00700d31
#endif

#ifndef getFunctionCallInfo
	#define getFunctionCallInfo 0x007049ac
#endif

#ifndef getNumberOfPartition
	#define getNumberOfPartition 0x00702a58
#endif

#ifndef getPartitionList
	#define getPartitionList 0x00702a5e
#endif

#ifndef halt
	#define halt 0x0070000e
#endif

#ifndef handleGPF
	#define handleGPF 0x007046a6
#endif

#ifndef I2CWriteMultipleBytes
	#define I2CWriteMultipleBytes 0x00707f85
#endif

#ifndef inb
	#define inb 0x00700924
#endif

#ifndef initGalileoSerial
	#define initGalileoSerial 0x00700aba
#endif

#ifndef initGalileoUART
	#define initGalileoUART 0x00700ae4
#endif

#ifndef initPartitionServices
	#define initPartitionServices 0x0070524e
#endif

#ifndef inl
	#define inl 0x007009a8
#endif

#ifndef inw
	#define inw 0x00700966
#endif

#ifndef irqTimer
	#define irqTimer 0x0070012c
#endif

#ifndef keyAsm
	#define keyAsm 0x0070013c
#endif

#ifndef keyHandler
	#define keyHandler 0x00704713
#endif

#ifndef main
	#define main 0x007057ed
#endif

#ifndef mapPage
	#define mapPage 0x00700a2e
#endif

#ifndef mappedInChild
	#define mappedInChild 0x00700a92
#endif

#ifndef memcpy
	#define memcpy 0x00705270
#endif

#ifndef memset
	#define memset 0x007052c5
#endif

#ifndef my_memcpy
	#define my_memcpy 0x00704b38
#endif

#ifndef outaddrl
	#define outaddrl 0x007009c7
#endif

#ifndef outb
	#define outb 0x00700901
#endif

#ifndef outl
	#define outl 0x00700985
#endif

#ifndef outw
	#define outw 0x00700943
#endif

#ifndef pageMapCount
	#define pageMapCount 0x00700a06
#endif

#ifndef parse_bootinfo
	#define parse_bootinfo 0x0070577e
#endif

#ifndef pfAsm
	#define pfAsm 0x00700134
#endif

#ifndef pfHandler
	#define pfHandler 0x007046f0
#endif

#ifndef Pip_AllocPage
	#define Pip_AllocPage 0x00700441
#endif

#ifndef Pip_Debug_Putc
	#define Pip_Debug_Putc 0x007008d5
#endif

#ifndef Pip_Debug_PutDec
	#define Pip_Debug_PutDec 0x00700305
#endif

#ifndef Pip_Debug_PutHex
	#define Pip_Debug_PutHex 0x0070029a
#endif

#ifndef Pip_Debug_Puts
	#define Pip_Debug_Puts 0x0070026a
#endif

#ifndef Pip_FreePage
	#define Pip_FreePage 0x0070048c
#endif

#ifndef Pip_InitPaging
	#define Pip_InitPaging 0x0070038d
#endif

#ifndef Pip_MapPageWrapper
	#define Pip_MapPageWrapper 0x00700519
#endif

#ifndef Pip_MapPageWrapper_RONLY
	#define Pip_MapPageWrapper_RONLY 0x0070060a
#endif

#ifndef Pip_Notify
	#define Pip_Notify 0x007006fb
#endif

#ifndef Pip_RegisterInterrupt
	#define Pip_RegisterInterrupt 0x007004c4
#endif

#ifndef pip_time
	#define pip_time 0x00700a6a
#endif

#ifndef Pip_VCLI
	#define Pip_VCLI 0x007004e3
#endif

#ifndef Pip_VSTI
	#define Pip_VSTI 0x007004fe
#endif

#ifndef PlatformPcal9555GpioPullup
	#define PlatformPcal9555GpioPullup 0x00706666
#endif

#ifndef PlatformPcal9555GpioSetDir
	#define PlatformPcal9555GpioSetDir 0x0070668a
#endif

#ifndef PlatformPcal9555GpioSetLevel
	#define PlatformPcal9555GpioSetLevel 0x007066ae
#endif

#ifndef prepare
	#define prepare 0x00700a16
#endif

#ifndef print
	#define print 0x00705515
#endif

#ifndef printf
	#define printf 0x00705749
#endif

#ifndef pvPortMalloc
	#define pvPortMalloc 0x00705dd6
#endif

#ifndef pvTaskIncrementMutexHeldCount
	#define pvTaskIncrementMutexHeldCount 0x00703a68
#endif

#ifndef pxPortInitialiseStack
	#define pxPortInitialiseStack 0x00704599
#endif

#ifndef Quark_x1000_Set_GPIO_BitDirection
	#define Quark_x1000_Set_GPIO_BitDirection 0x007076e9
#endif

#ifndef Quark_x1000_Set_GPIO_BitLevel
	#define Quark_x1000_Set_GPIO_BitLevel 0x00707789
#endif

#ifndef Quark_x1000_Set_GPIO_SUS_BitDirection
	#define Quark_x1000_Set_GPIO_SUS_BitDirection 0x00707863
#endif

#ifndef Quark_x1000_Set_GPIO_SUS_BitLevel
	#define Quark_x1000_Set_GPIO_SUS_BitLevel 0x0070788d
#endif

#ifndef queueCreateService
	#define queueCreateService 0x00704a0b
#endif

#ifndef queueReceiveService
	#define queueReceiveService 0x00704d49
#endif

#ifndef queueSendService
	#define queueSendService 0x00704b83
#endif

#ifndef registerIntBase
	#define registerIntBase 0x007004a5
#endif

#ifndef resume
	#define resume 0x00700a72
#endif

#ifndef sbrkService
	#define sbrkService 0x00704f06
#endif

#ifndef serviceRoutine
	#define serviceRoutine 0x00705178
#endif

#ifndef serviceRoutineAsm
	#define serviceRoutineAsm 0x0070014c
#endif

#ifndef set_dma_buffer
	#define set_dma_buffer 0x00708042
#endif

#ifndef setFunctionCallInfo
	#define setFunctionCallInfo 0x007049d1
#endif

#ifndef _start
	#define _start 0x00700000
#endif

#ifndef __udivdi3
	#define __udivdi3 0x00700160
#endif

#ifndef ulPortSetInterruptMask
	#define ulPortSetInterruptMask 0x00704987
#endif

#ifndef unmapPage
	#define unmapPage 0x00700a82
#endif

#ifndef uxListRemove
	#define uxListRemove 0x0070207a
#endif

#ifndef uxQueueMessagesWaiting
	#define uxQueueMessagesWaiting 0x00701a4c
#endif

#ifndef validChild
	#define validChild 0x007046c0
#endif

#ifndef validChildAsm
	#define validChildAsm 0x00700154
#endif

#ifndef vAssertCalled
	#define vAssertCalled 0x00705dd4
#endif

#ifndef vGalileoInitializeGpioController
	#define vGalileoInitializeGpioController 0x00707428
#endif

#ifndef vGalileoInitializeLegacyGPIO
	#define vGalileoInitializeLegacyGPIO 0x0070715d
#endif

#ifndef vGalileoRoute_IOs
	#define vGalileoRoute_IOs 0x007068db
#endif

#ifndef vInitializeGalileo_client_SerialPort
	#define vInitializeGalileo_client_SerialPort 0x00706f92
#endif

#ifndef vInitializeGalileo_client_SerialPort_RCVR_DMA
	#define vInitializeGalileo_client_SerialPort_RCVR_DMA 0x0070801a
#endif

#ifndef vListInitialise
	#define vListInitialise 0x00701f34
#endif

#ifndef vListInitialiseItem
	#define vListInitialiseItem 0x00701f75
#endif

#ifndef vListInsert
	#define vListInsert 0x00701fe1
#endif

#ifndef vListInsertEnd
	#define vListInsertEnd 0x00701f82
#endif

#ifndef vMicroSecondDelay
	#define vMicroSecondDelay 0x00707909
#endif

#ifndef vPortAPICErrorHandler
	#define vPortAPICErrorHandler 0x00704994
#endif

#ifndef vPortAPICErrorHandlerWrapper
	#define vPortAPICErrorHandlerWrapper 0x0070004c
#endif

#ifndef vPortAPICSpuriousHandler
	#define vPortAPICSpuriousHandler 0x00700128
#endif

#ifndef vPortCentralInterruptHandler
	#define vPortCentralInterruptHandler 0x007049a4
#endif

#ifndef vPortCentralInterruptWrapper
	#define vPortCentralInterruptWrapper 0x0070009c
#endif

#ifndef vPortClearInterruptMask
	#define vPortClearInterruptMask 0x00704992
#endif

#ifndef vPortEnterCritical
	#define vPortEnterCritical 0x0070493e
#endif

#ifndef vPortExitCritical
	#define vPortExitCritical 0x00704950
#endif

#ifndef vPortFree
	#define vPortFree 0x00705fba
#endif

#ifndef vPortStartFirstTask
	#define vPortStartFirstTask 0x0070003c
#endif

#ifndef vPortTimerHandler
	#define vPortTimerHandler 0x00700054
#endif

#ifndef vPortYieldCall
	#define vPortYieldCall 0x00700014
#endif

#ifndef vQueueAddToRegistry
	#define vQueueAddToRegistry 0x00701d93
#endif

#ifndef vQueueWaitForMessageRestricted
	#define vQueueWaitForMessageRestricted 0x00701ddf
#endif

#ifndef vSetTaskBuffer
	#define vSetTaskBuffer 0x00703ddb
#endif

#ifndef vTaskMissedYield
	#define vTaskMissedYield 0x00703363
#endif

#ifndef vTaskPlaceOnEventList
	#define vTaskPlaceOnEventList 0x00702fe1
#endif

#ifndef vTaskPlaceOnEventListRestricted
	#define vTaskPlaceOnEventListRestricted 0x00703099
#endif

#ifndef vTaskPriorityInherit
	#define vTaskPriorityInherit 0x007037c9
#endif

#ifndef vTaskSetTimeOutState
	#define vTaskSetTimeOutState 0x00703244
#endif

#ifndef vTaskStartScheduler
	#define vTaskStartScheduler 0x00702a64
#endif

#ifndef vTaskSuspendAll
	#define vTaskSuspendAll 0x00702af3
#endif

#ifndef vTaskSwitchContext
	#define vTaskSwitchContext 0x00702e53
#endif

#ifndef WriteMultipleByte
	#define WriteMultipleByte 0x00707ea7
#endif

#ifndef xGetTaskBuffer
	#define xGetTaskBuffer 0x00703df5
#endif

#ifndef xGetTaskWhereTo
	#define xGetTaskWhereTo 0x00703e0b
#endif

#ifndef xPortStartScheduler
	#define xPortStartScheduler 0x00704873
#endif

#ifndef xQueueGenericCreate
	#define xQueueGenericCreate 0x00700e7e
#endif

#ifndef xQueueGenericReceive
	#define xQueueGenericReceive 0x00701520
#endif

#ifndef xQueueGenericReset
	#define xQueueGenericReset 0x00700d67
#endif

#ifndef xQueueGenericSend
	#define xQueueGenericSend 0x00700f68
#endif

#ifndef xQueueGenericSendFromISR
	#define xQueueGenericSendFromISR 0x00701379
#endif

#ifndef xTaskCheckForTimeOut
	#define xTaskCheckForTimeOut 0x00703281
#endif

#ifndef xTaskGenericCreate
	#define xTaskGenericCreate 0x007027a0
#endif

#ifndef xTaskGenericNotify
	#define xTaskGenericNotify 0x00703a83
#endif

#ifndef xTaskGenericNotifyFromISR
	#define xTaskGenericNotifyFromISR 0x00703c0b
#endif

#ifndef xTaskGetSchedulerState
	#define xTaskGetSchedulerState 0x00703790
#endif

#ifndef xTaskGetTickCount
	#define xTaskGetTickCount 0x00702c65
#endif

#ifndef xTaskIncrementTick
	#define xTaskIncrementTick 0x00702c83
#endif

#ifndef xTaskPartitionCreate
	#define xTaskPartitionCreate 0x007020e9
#endif

#ifndef xTaskPriorityDisinherit
	#define xTaskPriorityDisinherit 0x00703906
#endif

#ifndef xTaskRemoveFromEventList
	#define xTaskRemoveFromEventList 0x00703151
#endif

#ifndef xTaskResumeAll
	#define xTaskResumeAll 0x00702b00
#endif

#ifndef xTaskSwitchToProtectedTask
	#define xTaskSwitchToProtectedTask 0x007026e4
#endif

#ifndef xTimerCreateTimerTask
	#define xTimerCreateTimerTask 0x00703e21
#endif

#ifndef xTimerGenericCommand
	#define xTimerGenericCommand 0x00703e98
#endif

#endif
