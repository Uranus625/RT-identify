################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/components/drivers/src/completion.c \
../rt-thread/components/drivers/src/dataqueue.c \
../rt-thread/components/drivers/src/pipe.c \
../rt-thread/components/drivers/src/ringblk_buf.c \
../rt-thread/components/drivers/src/ringbuffer.c \
../rt-thread/components/drivers/src/waitqueue.c \
../rt-thread/components/drivers/src/workqueue.c 

OBJS += \
./rt-thread/components/drivers/src/completion.o \
./rt-thread/components/drivers/src/dataqueue.o \
./rt-thread/components/drivers/src/pipe.o \
./rt-thread/components/drivers/src/ringblk_buf.o \
./rt-thread/components/drivers/src/ringbuffer.o \
./rt-thread/components/drivers/src/waitqueue.o \
./rt-thread/components/drivers/src/workqueue.o 

C_DEPS += \
./rt-thread/components/drivers/src/completion.d \
./rt-thread/components/drivers/src/dataqueue.d \
./rt-thread/components/drivers/src/pipe.d \
./rt-thread/components/drivers/src/ringblk_buf.d \
./rt-thread/components/drivers/src/ringbuffer.d \
./rt-thread/components/drivers/src/waitqueue.d \
./rt-thread/components/drivers/src/workqueue.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/components/drivers/src/%.o: ../rt-thread/components/drivers/src/%.c
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DDEBUG -I"C:\code\rtthread\RT-identify" -I"C:\code\rtthread\RT-identify\Middlewares\ST\AI\Inc" -I"C:\code\rtthread\RT-identify\X-CUBE-AI\App" -I"C:\code\rtthread\RT-identify\X-CUBE-AI" -I"C:\code\rtthread\RT-identify\applications" -I"C:\code\rtthread\RT-identify\board\CubeMX_Config\Core\Inc" -I"C:\code\rtthread\RT-identify\board\port" -I"C:\code\rtthread\RT-identify\board" -I"C:\code\rtthread\RT-identify\libraries\Persimmon\inc" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\CMSIS\Device\ST\STM32H7xx\Include" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\CMSIS\Include" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\STM32H7xx_HAL_Driver\Inc" -I"C:\code\rtthread\RT-identify\libraries\drivers\include\config" -I"C:\code\rtthread\RT-identify\libraries\drivers\include" -I"C:\code\rtthread\RT-identify\libraries\drivers" -I"C:\code\rtthread\RT-identify\libraries\samples" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\devfs" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\elmfat" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\romfs" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\include" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\include" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\spi" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\touch" -I"C:\code\rtthread\RT-identify\rt-thread\components\finsh" -I"C:\code\rtthread\RT-identify\rt-thread\components\libc\compilers\newlib" -I"C:\code\rtthread\RT-identify\rt-thread\include" -I"C:\code\rtthread\RT-identify\rt-thread\libcpu\arm\common" -I"C:\code\rtthread\RT-identify\rt-thread\libcpu\arm\cortex-m7" -I"C:\code\rtthread\RT-identify\rt_ai_lib\backend_plugin_stm32" -I"C:\code\rtthread\RT-identify\rt_ai_lib\img" -I"C:\code\rtthread\RT-identify\rt_ai_lib\include" -I"C:\code\rtthread\RT-identify\rt_ai_lib" -include"C:\code\rtthread\RT-identify\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

