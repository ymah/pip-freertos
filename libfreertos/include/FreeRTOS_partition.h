#ifndef _FREERTOS_ACCESS_h
#define _FREERTOS_ACCESS_h
#ifndef anyIntAsm
	#define anyIntAsm 0x00700144
#endif

#ifndef anyIntHandler
	#define anyIntHandler 0x0070479b
#endif

#ifndef __Arch_APICall_0
	#define __Arch_APICall_0 0x00700610
#endif

#ifndef __Arch_APICall_1
	#define __Arch_APICall_1 0x00700632
#endif

#ifndef __Arch_APICall_2
	#define __Arch_APICall_2 0x00700699
#endif

#ifndef __Arch_APICall_3
	#define __Arch_APICall_3 0x0070070d
#endif

#ifndef __Arch_APICall_4
	#define __Arch_APICall_4 0x00700713
#endif

#ifndef __Arch_APICall_5
	#define __Arch_APICall_5 0x00700744
#endif

#ifndef __Arch_APICall_6
	#define __Arch_APICall_6 0x0070078d
#endif

#ifndef channelService
	#define channelService 0x0070508d
#endif

#ifndef checkAccess
	#define checkAccess 0x007049fe
#endif

#ifndef code
	#define code 0x00700000
#endif

#ifndef collect
	#define collect 0x007009b0
#endif

#ifndef createPartition
	#define createPartition 0x007008f0
#endif

#ifndef deletePartition
	#define deletePartition 0x007009a4
#endif

#ifndef disableSerialInChild
	#define disableSerialInChild 0x00702679
#endif

#ifndef dispatch
	#define dispatch 0x00700954
#endif

#ifndef dRegTest1_st1
	#define dRegTest1_st1 0x00706a98
#endif

#ifndef dRegTest1_st2
	#define dRegTest1_st2 0x00706a90
#endif

#ifndef dRegTest1_st3
	#define dRegTest1_st3 0x00706a88
#endif

#ifndef dRegTest1_st4
	#define dRegTest1_st4 0x00706a80
#endif

#ifndef dRegTest1_st5
	#define dRegTest1_st5 0x00706a78
#endif

#ifndef dRegTest1_st6
	#define dRegTest1_st6 0x00706a70
#endif

#ifndef dRegTest1_st7
	#define dRegTest1_st7 0x00706a68
#endif

#ifndef dRegTest2_st1
	#define dRegTest2_st1 0x00706ad0
#endif

#ifndef dRegTest2_st2
	#define dRegTest2_st2 0x00706ac8
#endif

#ifndef dRegTest2_st3
	#define dRegTest2_st3 0x00706ac0
#endif

#ifndef dRegTest2_st4
	#define dRegTest2_st4 0x00706ab8
#endif

#ifndef dRegTest2_st5
	#define dRegTest2_st5 0x00706ab0
#endif

#ifndef dRegTest2_st6
	#define dRegTest2_st6 0x00706aa8
#endif

#ifndef dRegTest2_st7
	#define dRegTest2_st7 0x00706aa0
#endif

#ifndef enableSerialInChild
	#define enableSerialInChild 0x007025c3
#endif

#ifndef getFunctionCallInfo
	#define getFunctionCallInfo 0x00704a04
#endif

#ifndef getNumberOfPartition
	#define getNumberOfPartition 0x00702aa0
#endif

#ifndef getPartitionList
	#define getPartitionList 0x00702aa6
#endif

#ifndef halt
	#define halt 0x0070000e
#endif

#ifndef handleGPF
	#define handleGPF 0x007046fe
#endif

#ifndef inb
	#define inb 0x0070082a
#endif

#ifndef initPartitionServices
	#define initPartitionServices 0x007052af
#endif

#ifndef inl
	#define inl 0x007008ae
#endif

#ifndef inw
	#define inw 0x0070086c
#endif

#ifndef irqTimer
	#define irqTimer 0x0070012c
#endif

#ifndef keyAsm
	#define keyAsm 0x0070013c
#endif

#ifndef keyHandler
	#define keyHandler 0x0070476b
#endif

#ifndef main
	#define main 0x0070580e
#endif

#ifndef mapPage
	#define mapPage 0x00700934
#endif

#ifndef mappedInChild
	#define mappedInChild 0x00700998
#endif

#ifndef memcpy
	#define memcpy 0x007052d1
#endif

#ifndef my_memcpy
	#define my_memcpy 0x00704b90
#endif

#ifndef outaddrl
	#define outaddrl 0x007008cd
#endif

#ifndef outb
	#define outb 0x00700807
#endif

#ifndef outl
	#define outl 0x0070088b
#endif

#ifndef outw
	#define outw 0x00700849
#endif

#ifndef pageMapCount
	#define pageMapCount 0x0070090c
#endif

#ifndef parse_bootinfo
	#define parse_bootinfo 0x0070579f
#endif

#ifndef pfAsm
	#define pfAsm 0x00700134
#endif

#ifndef pfHandler
	#define pfHandler 0x00704748
#endif

#ifndef Pip_AllocPage
	#define Pip_AllocPage 0x00700333
#endif

#ifndef Pip_Debug_Putc
	#define Pip_Debug_Putc 0x007007c7
#endif

#ifndef Pip_Debug_PutDec
	#define Pip_Debug_PutDec 0x007001f7
#endif

#ifndef Pip_Debug_PutHex
	#define Pip_Debug_PutHex 0x0070018c
#endif

#ifndef Pip_Debug_Puts
	#define Pip_Debug_Puts 0x0070015c
#endif

#ifndef Pip_FreePage
	#define Pip_FreePage 0x0070037e
#endif

#ifndef Pip_InitPaging
	#define Pip_InitPaging 0x0070027f
#endif

#ifndef Pip_MapPageWrapper
	#define Pip_MapPageWrapper 0x0070040b
#endif

#ifndef Pip_MapPageWrapper_RONLY
	#define Pip_MapPageWrapper_RONLY 0x007004fc
#endif

#ifndef Pip_Notify
	#define Pip_Notify 0x007005ed
#endif

#ifndef Pip_RegisterInterrupt
	#define Pip_RegisterInterrupt 0x007003b6
#endif

#ifndef pip_time
	#define pip_time 0x00700970
#endif

#ifndef Pip_VCLI
	#define Pip_VCLI 0x007003d5
#endif

#ifndef Pip_VSTI
	#define Pip_VSTI 0x007003f0
#endif

#ifndef prepare
	#define prepare 0x0070091c
#endif

#ifndef print
	#define print 0x00705536
#endif

#ifndef printf
	#define printf 0x0070576a
#endif

#ifndef pvPortMalloc
	#define pvPortMalloc 0x0070588b
#endif

#ifndef pvTaskIncrementMutexHeldCount
	#define pvTaskIncrementMutexHeldCount 0x00703ab0
#endif

#ifndef pxPortInitialiseStack
	#define pxPortInitialiseStack 0x007045f1
#endif

#ifndef queueCreateService
	#define queueCreateService 0x00704a63
#endif

#ifndef queueReceiveService
	#define queueReceiveService 0x00704daa
#endif

#ifndef queueSendService
	#define queueSendService 0x00704bdb
#endif

#ifndef registerIntBase
	#define registerIntBase 0x00700397
#endif

#ifndef resume
	#define resume 0x00700978
#endif

#ifndef sbrkService
	#define sbrkService 0x00704f6c
#endif

#ifndef serviceRoutine
	#define serviceRoutine 0x007051de
#endif

#ifndef serviceRoutineAsm
	#define serviceRoutineAsm 0x0070014c
#endif

#ifndef setFunctionCallInfo
	#define setFunctionCallInfo 0x00704a29
#endif

#ifndef _start
	#define _start 0x00700000
#endif

#ifndef ulPortSetInterruptMask
	#define ulPortSetInterruptMask 0x007049df
#endif

#ifndef unmapPage
	#define unmapPage 0x00700988
#endif

#ifndef uxListRemove
	#define uxListRemove 0x007020c2
#endif

#ifndef uxQueueMessagesWaiting
	#define uxQueueMessagesWaiting 0x00701a94
#endif

#ifndef validChild
	#define validChild 0x00704718
#endif

#ifndef validChildAsm
	#define validChildAsm 0x00700154
#endif

#ifndef vAssertCalled
	#define vAssertCalled 0x00705889
#endif

#ifndef vListInitialise
	#define vListInitialise 0x00701f7c
#endif

#ifndef vListInitialiseItem
	#define vListInitialiseItem 0x00701fbd
#endif

#ifndef vListInsert
	#define vListInsert 0x00702029
#endif

#ifndef vListInsertEnd
	#define vListInsertEnd 0x00701fca
#endif

#ifndef vPortAPICErrorHandler
	#define vPortAPICErrorHandler 0x007049ec
#endif

#ifndef vPortAPICErrorHandlerWrapper
	#define vPortAPICErrorHandlerWrapper 0x0070004c
#endif

#ifndef vPortAPICSpuriousHandler
	#define vPortAPICSpuriousHandler 0x00700128
#endif

#ifndef vPortCentralInterruptHandler
	#define vPortCentralInterruptHandler 0x007049fc
#endif

#ifndef vPortCentralInterruptWrapper
	#define vPortCentralInterruptWrapper 0x0070009c
#endif

#ifndef vPortClearInterruptMask
	#define vPortClearInterruptMask 0x007049ea
#endif

#ifndef vPortEnterCritical
	#define vPortEnterCritical 0x00704996
#endif

#ifndef vPortExitCritical
	#define vPortExitCritical 0x007049a8
#endif

#ifndef vPortFree
	#define vPortFree 0x00705a6f
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
	#define vQueueAddToRegistry 0x00701ddb
#endif

#ifndef vQueueWaitForMessageRestricted
	#define vQueueWaitForMessageRestricted 0x00701e27
#endif

#ifndef vSetTaskBuffer
	#define vSetTaskBuffer 0x00703e23
#endif

#ifndef vTaskMissedYield
	#define vTaskMissedYield 0x007033ab
#endif

#ifndef vTaskPlaceOnEventList
	#define vTaskPlaceOnEventList 0x00703029
#endif

#ifndef vTaskPlaceOnEventListRestricted
	#define vTaskPlaceOnEventListRestricted 0x007030e1
#endif

#ifndef vTaskPriorityInherit
	#define vTaskPriorityInherit 0x00703811
#endif

#ifndef vTaskSetTimeOutState
	#define vTaskSetTimeOutState 0x0070328c
#endif

#ifndef vTaskStartScheduler
	#define vTaskStartScheduler 0x00702aac
#endif

#ifndef vTaskSuspendAll
	#define vTaskSuspendAll 0x00702b3b
#endif

#ifndef vTaskSwitchContext
	#define vTaskSwitchContext 0x00702e9b
#endif

#ifndef xGetTaskBuffer
	#define xGetTaskBuffer 0x00703e3d
#endif

#ifndef xGetTaskWhereTo
	#define xGetTaskWhereTo 0x00703e53
#endif

#ifndef xPortStartScheduler
	#define xPortStartScheduler 0x007048cb
#endif

#ifndef xQueueGenericCreate
	#define xQueueGenericCreate 0x00700ad7
#endif

#ifndef xQueueGenericReceive
	#define xQueueGenericReceive 0x007012b9
#endif

#ifndef xQueueGenericReset
	#define xQueueGenericReset 0x007009c0
#endif

#ifndef xQueueGenericSend
	#define xQueueGenericSend 0x00700bc1
#endif

#ifndef xQueueGenericSendFromISR
	#define xQueueGenericSendFromISR 0x00701112
#endif

#ifndef xTaskCheckForTimeOut
	#define xTaskCheckForTimeOut 0x007032c9
#endif

#ifndef xTaskGenericCreate
	#define xTaskGenericCreate 0x007027e8
#endif

#ifndef xTaskGenericNotify
	#define xTaskGenericNotify 0x00703acb
#endif

#ifndef xTaskGenericNotifyFromISR
	#define xTaskGenericNotifyFromISR 0x00703c53
#endif

#ifndef xTaskGetSchedulerState
	#define xTaskGetSchedulerState 0x007037d8
#endif

#ifndef xTaskGetTickCount
	#define xTaskGetTickCount 0x00702cad
#endif

#ifndef xTaskIncrementTick
	#define xTaskIncrementTick 0x00702ccb
#endif

#ifndef xTaskPartitionCreate
	#define xTaskPartitionCreate 0x00702131
#endif

#ifndef xTaskPriorityDisinherit
	#define xTaskPriorityDisinherit 0x0070394e
#endif

#ifndef xTaskRemoveFromEventList
	#define xTaskRemoveFromEventList 0x00703199
#endif

#ifndef xTaskResumeAll
	#define xTaskResumeAll 0x00702b48
#endif

#ifndef xTaskSwitchToProtectedTask
	#define xTaskSwitchToProtectedTask 0x0070272c
#endif

#ifndef xTimerCreateTimerTask
	#define xTimerCreateTimerTask 0x00703e69
#endif

#ifndef xTimerGenericCommand
	#define xTimerGenericCommand 0x00703ee0
#endif

#endif
