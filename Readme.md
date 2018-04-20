FreeRTOS portage to PIP kernel.

- `Demo/Common/`: FreeRTOS original extension (version 9.0)
- `Demo/pip-kernel/`: FreeRTOS entry point
- `libfreertos/`: user-space FreeRTOS library
- `Source/`: FreeRTOS core and portage sources



To adding new task-partitions :
- To add task-partitions for FreeRTOS, you have to put them into `Demo/pip-kernel/Support_Files/aes.hpartitions_images/`
- Include the binary corresponding to the task into `Demo/pip-kernel/Support_Files/partition.S`
- Create a new protected task into your source code, example :
  In partitions.S :
  ```
  .section .partition1
  .incbin "Support_Files/partitions_images/part1.bin"

  .section .partition2
  .incbin "Support_Files/partitions_images/part2.bin"
  ```
  In main.c :
  ```C
  extern void* _partition1, *_epartition1;
  extern void* _partition2, *_epartition2;

  static const struct {
      uint32_t start, end;
  } partitions[] = { { (uint32_t) &_partition1, (uint32_t) &_epartition1 },
      (uint32_t) &_partition2, (uint32_t) &_epartition2 };

  ```

  in main function :
  ```C
  uint32_t size = partitions[0].end - partitions[0].start;
  xTaskCreateProtected(partitions[0].start, "partition name", size, NULL, configMAX_PRIORITIES - 1, NULL);
  ```
