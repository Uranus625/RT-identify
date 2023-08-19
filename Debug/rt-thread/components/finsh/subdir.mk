################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../rt-thread/components/finsh/cmd.c \
../rt-thread/components/finsh/finsh_compiler.c \
../rt-thread/components/finsh/finsh_error.c \
../rt-thread/components/finsh/finsh_heap.c \
../rt-thread/components/finsh/finsh_init.c \
../rt-thread/components/finsh/finsh_node.c \
../rt-thread/components/finsh/finsh_ops.c \
../rt-thread/components/finsh/finsh_parser.c \
../rt-thread/components/finsh/finsh_token.c \
../rt-thread/components/finsh/finsh_var.c \
../rt-thread/components/finsh/finsh_vm.c \
../rt-thread/components/finsh/msh.c \
../rt-thread/components/finsh/msh_file.c \
../rt-thread/components/finsh/shell.c 

OBJS += \
./rt-thread/components/finsh/cmd.o \
./rt-thread/components/finsh/finsh_compiler.o \
./rt-thread/components/finsh/finsh_error.o \
./rt-thread/components/finsh/finsh_heap.o \
./rt-thread/components/finsh/finsh_init.o \
./rt-thread/components/finsh/finsh_node.o \
./rt-thread/components/finsh/finsh_ops.o \
./rt-thread/components/finsh/finsh_parser.o \
./rt-thread/components/finsh/finsh_token.o \
./rt-thread/components/finsh/finsh_var.o \
./rt-thread/components/finsh/finsh_vm.o \
./rt-thread/components/finsh/msh.o \
./rt-thread/components/finsh/msh_file.o \
./rt-thread/components/finsh/shell.o 

C_DEPS += \
./rt-thread/components/finsh/cmd.d \
./rt-thread/components/finsh/finsh_compiler.d \
./rt-thread/components/finsh/finsh_error.d \
./rt-thread/components/finsh/finsh_heap.d \
./rt-thread/components/finsh/finsh_init.d \
./rt-thread/components/finsh/finsh_node.d \
./rt-thread/components/finsh/finsh_ops.d \
./rt-thread/components/finsh/finsh_parser.d \
./rt-thread/components/finsh/finsh_token.d \
./rt-thread/components/finsh/finsh_var.d \
./rt-thread/components/finsh/finsh_vm.d \
./rt-thread/components/finsh/msh.d \
./rt-thread/components/finsh/msh_file.d \
./rt-thread/components/finsh/shell.d 


# Each subdirectory must supply rules for building sources it contributes
rt-thread/components/finsh/%.o: ../rt-thread/components/finsh/%.c
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DDEBUG -I"C:\code\rtthread\RT-identify" -I"C:\code\rtthread\RT-identify\Middlewares\ST\AI\Inc" -I"C:\code\rtthread\RT-identify\X-CUBE-AI\App" -I"C:\code\rtthread\RT-identify\X-CUBE-AI" -I"C:\code\rtthread\RT-identify\applications" -I"C:\code\rtthread\RT-identify\board\CubeMX_Config\Core\Inc" -I"C:\code\rtthread\RT-identify\board\port" -I"C:\code\rtthread\RT-identify\board" -I"C:\code\rtthread\RT-identify\libraries\Persimmon\inc" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\CMSIS\Device\ST\STM32H7xx\Include" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\CMSIS\Include" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\STM32H7xx_HAL_Driver\Inc" -I"C:\code\rtthread\RT-identify\libraries\drivers\include\config" -I"C:\code\rtthread\RT-identify\libraries\drivers\include" -I"C:\code\rtthread\RT-identify\libraries\drivers" -I"C:\code\rtthread\RT-identify\libraries\samples" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\devfs" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\elmfat" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\romfs" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\include" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\include" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\spi" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\touch" -I"C:\code\rtthread\RT-identify\rt-thread\components\finsh" -I"C:\code\rtthread\RT-identify\rt-thread\components\libc\compilers\newlib" -I"C:\code\rtthread\RT-identify\rt-thread\include" -I"C:\code\rtthread\RT-identify\rt-thread\libcpu\arm\common" -I"C:\code\rtthread\RT-identify\rt-thread\libcpu\arm\cortex-m7" -I"C:\code\rtthread\RT-identify\rt_ai_lib\backend_plugin_stm32" -I"C:\code\rtthread\RT-identify\rt_ai_lib\img" -I"C:\code\rtthread\RT-identify\rt_ai_lib\include" -I"C:\code\rtthread\RT-identify\rt_ai_lib" -include"C:\code\rtthread\RT-identify\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

