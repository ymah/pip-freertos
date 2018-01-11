



all: freertos



freertos:
	cp ../toolchain.mk Demo/pip-kernel/ 
	make -C Demo/pip-kernel/ all
	cp Demo/pip-kernel/Build/FreeRTOS.bin .

clean:
	make -C Demo/pip-kernel/ clean
	rm FreeRTOS.bin
