################################################################################
# 自动生成的文件。不要编辑！
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../libraries/drivers/drv_common.c \
../libraries/drivers/drv_dcmi.c \
../libraries/drivers/drv_gc0328c.c \
../libraries/drivers/drv_gpio.c \
../libraries/drivers/drv_lcd.c \
../libraries/drivers/drv_sdio.c \
../libraries/drivers/drv_sdram.c \
../libraries/drivers/drv_soft_i2c.c \
../libraries/drivers/drv_spi.c \
../libraries/drivers/drv_spi_ili9488.c \
../libraries/drivers/drv_usart.c \
../libraries/drivers/drv_wlan.c 

OBJS += \
./libraries/drivers/drv_common.o \
./libraries/drivers/drv_dcmi.o \
./libraries/drivers/drv_gc0328c.o \
./libraries/drivers/drv_gpio.o \
./libraries/drivers/drv_lcd.o \
./libraries/drivers/drv_sdio.o \
./libraries/drivers/drv_sdram.o \
./libraries/drivers/drv_soft_i2c.o \
./libraries/drivers/drv_spi.o \
./libraries/drivers/drv_spi_ili9488.o \
./libraries/drivers/drv_usart.o \
./libraries/drivers/drv_wlan.o 

C_DEPS += \
./libraries/drivers/drv_common.d \
./libraries/drivers/drv_dcmi.d \
./libraries/drivers/drv_gc0328c.d \
./libraries/drivers/drv_gpio.d \
./libraries/drivers/drv_lcd.d \
./libraries/drivers/drv_sdio.d \
./libraries/drivers/drv_sdram.d \
./libraries/drivers/drv_soft_i2c.d \
./libraries/drivers/drv_spi.d \
./libraries/drivers/drv_spi_ili9488.d \
./libraries/drivers/drv_usart.d \
./libraries/drivers/drv_wlan.d 


# Each subdirectory must supply rules for building sources it contributes
libraries/drivers/%.o: ../libraries/drivers/%.c
	arm-none-eabi-gcc -mcpu=cortex-m7 -mthumb -mfloat-abi=hard -mfpu=fpv5-d16 -O0 -ffunction-sections -fdata-sections -Wall  -g -gdwarf-2 -DDEBUG -I"C:\code\rtthread\RT-identify" -I"C:\code\rtthread\RT-identify\Middlewares\ST\AI\Inc" -I"C:\code\rtthread\RT-identify\X-CUBE-AI\App" -I"C:\code\rtthread\RT-identify\X-CUBE-AI" -I"C:\code\rtthread\RT-identify\applications" -I"C:\code\rtthread\RT-identify\board\CubeMX_Config\Core\Inc" -I"C:\code\rtthread\RT-identify\board\port" -I"C:\code\rtthread\RT-identify\board" -I"C:\code\rtthread\RT-identify\libraries\Persimmon\inc" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\CMSIS\Device\ST\STM32H7xx\Include" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\CMSIS\Include" -I"C:\code\rtthread\RT-identify\libraries\STM32H7xx_HAL\STM32H7xx_HAL_Driver\Inc" -I"C:\code\rtthread\RT-identify\libraries\drivers\include\config" -I"C:\code\rtthread\RT-identify\libraries\drivers\include" -I"C:\code\rtthread\RT-identify\libraries\drivers" -I"C:\code\rtthread\RT-identify\libraries\samples" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\devfs" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\elmfat" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\filesystems\romfs" -I"C:\code\rtthread\RT-identify\rt-thread\components\dfs\include" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\include" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\spi" -I"C:\code\rtthread\RT-identify\rt-thread\components\drivers\touch" -I"C:\code\rtthread\RT-identify\rt-thread\components\finsh" -I"C:\code\rtthread\RT-identify\rt-thread\components\libc\compilers\newlib" -I"C:\code\rtthread\RT-identify\rt-thread\include" -I"C:\code\rtthread\RT-identify\rt-thread\libcpu\arm\common" -I"C:\code\rtthread\RT-identify\rt-thread\libcpu\arm\cortex-m7" -I"C:\code\rtthread\RT-identify\rt_ai_lib\backend_plugin_stm32" -I"C:\code\rtthread\RT-identify\rt_ai_lib\img" -I"C:\code\rtthread\RT-identify\rt_ai_lib\include" -I"C:\code\rtthread\RT-identify\rt_ai_lib" -include"C:\code\rtthread\RT-identify\rtconfig_preinc.h" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"

