################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/src/clock.c \
../rt-thread/src/components.c \
../rt-thread/src/device.c \
../rt-thread/src/idle.c \
../rt-thread/src/ipc.c \
../rt-thread/src/irq.c \
../rt-thread/src/kservice.c \
../rt-thread/src/memheap.c \
../rt-thread/src/mempool.c \
../rt-thread/src/object.c \
../rt-thread/src/scheduler.c \
../rt-thread/src/signal.c \
../rt-thread/src/thread.c \
../rt-thread/src/timer.c 

OBJS += \
./rt-thread/src/clock.o \
./rt-thread/src/components.o \
./rt-thread/src/device.o \
./rt-thread/src/idle.o \
./rt-thread/src/ipc.o \
./rt-thread/src/irq.o \
./rt-thread/src/kservice.o \
./rt-thread/src/memheap.o \
./rt-thread/src/mempool.o \
./rt-thread/src/object.o \
./rt-thread/src/scheduler.o \
./rt-thread/src/signal.o \
./rt-thread/src/thread.o \
./rt-thread/src/timer.o 

C_DEPS += \
./rt-thread/src/clock.d \
./rt-thread/src/components.d \
./rt-thread/src/device.d \
./rt-thread/src/idle.d \
./rt-thread/src/ipc.d \
./rt-thread/src/irq.d \
./rt-thread/src/kservice.d \
./rt-thread/src/memheap.d \
./rt-thread/src/mempool.d \
./rt-thread/src/object.d \
./rt-thread/src/scheduler.d \
./rt-thread/src/signal.d \
./rt-thread/src/thread.d \
./rt-thread/src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/src/%.o: ../rt-thread/src/%.c
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DDEBUG -I"C:\code\rtthread\RT-identify" -I"C:\code\rtthread\RT-identify\Middlewares\ST\AI\Inc" -I"C:\code\rtthread\RT-identify\X-CUBE-AI\App" -I"C:\code\rtthread\RT-identify\X-CUBE-AI" -I"C:\code\rtthread\RT-identify\applications" -I"C:\code\rtthread\RT-identify\board\CubeMX_Config\Core\Inc" -I"C:\code\rtthread\RT-identify\board\port" -I"C:\code\rtthread\RT-identify\board" -I"C:\code\rtthread\RT-identify\libraries\Persimmon\inc" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\CMSIS\Device\ST\STM32H7xx\Include" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\CMSIS\Include" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\STM32H7xx_HAL_Driver\Inc" -I"C:\code\rtthread\RT-identify\libraries\drivers\include\config" -I"C:\code\rtthread\RT-identify\libraries\drivers\include" -I"C:\code\rtthread\RT-identify\libraries\drivers" -I"C:\code\rtthread\RT-identify\libraries\samples" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\devfs" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\elmfat" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\romfs" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\include" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\include" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\spi" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\touch" -I"C:\code\rtthread\RT-identify\rt-thread\components\finsh" -I"C:\code\rtthread\RT-identify\rt-thread\components\libc\compilers\newlib" -I"C:\code\rtthread\RT-identify\rt-thread\include" -I"C:\code\rtthread\RT-identify\rt-thread\libcpu\arm\common" -I"C:\code\rtthread\RT-identify\rt-thread\libcpu\arm\cortex-m7" -I"C:\code\rtthread\RT-identify\rt_ai_lib\backend_plugin_stm32" -I"C:\code\rtthread\RT-identify\rt_ai_lib\img" -I"C:\code\rtthread\RT-identify\rt_ai_lib\include" -I"C:\code\rtthread\RT-identify\rt_ai_lib" -include"C:\code\rtthread\RT-identify\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

