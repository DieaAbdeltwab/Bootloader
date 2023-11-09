################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Src/BOOTLOADER_program.c \
../Src/CRC_program.c \
../Src/EXTI_program.c \
../Src/FLASH_program.c \
../Src/GPIO_program.c \
../Src/GPTIMER_program.c \
../Src/NVIC_program.c \
../Src/PRELOADER_program.c \
../Src/RCC_program.c \
../Src/SCB_program.c \
../Src/STK_program.c \
../Src/SYSCFG_program.c \
../Src/TIMERS_program.c \
../Src/USART_program.c \
../Src/main.c \
../Src/syscalls.c \
../Src/sysmem.c 

OBJS += \
./Src/BOOTLOADER_program.o \
./Src/CRC_program.o \
./Src/EXTI_program.o \
./Src/FLASH_program.o \
./Src/GPIO_program.o \
./Src/GPTIMER_program.o \
./Src/NVIC_program.o \
./Src/PRELOADER_program.o \
./Src/RCC_program.o \
./Src/SCB_program.o \
./Src/STK_program.o \
./Src/SYSCFG_program.o \
./Src/TIMERS_program.o \
./Src/USART_program.o \
./Src/main.o \
./Src/syscalls.o \
./Src/sysmem.o 

C_DEPS += \
./Src/BOOTLOADER_program.d \
./Src/CRC_program.d \
./Src/EXTI_program.d \
./Src/FLASH_program.d \
./Src/GPIO_program.d \
./Src/GPTIMER_program.d \
./Src/NVIC_program.d \
./Src/PRELOADER_program.d \
./Src/RCC_program.d \
./Src/SCB_program.d \
./Src/STK_program.d \
./Src/SYSCFG_program.d \
./Src/TIMERS_program.d \
./Src/USART_program.d \
./Src/main.d \
./Src/syscalls.d \
./Src/sysmem.d 


# Each subdirectory must supply rules for building sources it contributes
Src/%.o Src/%.su: ../Src/%.c Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -c -I../Inc -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Src

clean-Src:
	-$(RM) ./Src/BOOTLOADER_program.d ./Src/BOOTLOADER_program.o ./Src/BOOTLOADER_program.su ./Src/CRC_program.d ./Src/CRC_program.o ./Src/CRC_program.su ./Src/EXTI_program.d ./Src/EXTI_program.o ./Src/EXTI_program.su ./Src/FLASH_program.d ./Src/FLASH_program.o ./Src/FLASH_program.su ./Src/GPIO_program.d ./Src/GPIO_program.o ./Src/GPIO_program.su ./Src/GPTIMER_program.d ./Src/GPTIMER_program.o ./Src/GPTIMER_program.su ./Src/NVIC_program.d ./Src/NVIC_program.o ./Src/NVIC_program.su ./Src/PRELOADER_program.d ./Src/PRELOADER_program.o ./Src/PRELOADER_program.su ./Src/RCC_program.d ./Src/RCC_program.o ./Src/RCC_program.su ./Src/SCB_program.d ./Src/SCB_program.o ./Src/SCB_program.su ./Src/STK_program.d ./Src/STK_program.o ./Src/STK_program.su ./Src/SYSCFG_program.d ./Src/SYSCFG_program.o ./Src/SYSCFG_program.su ./Src/TIMERS_program.d ./Src/TIMERS_program.o ./Src/TIMERS_program.su ./Src/USART_program.d ./Src/USART_program.o ./Src/USART_program.su ./Src/main.d ./Src/main.o ./Src/main.su ./Src/syscalls.d ./Src/syscalls.o ./Src/syscalls.su ./Src/sysmem.d ./Src/sysmem.o ./Src/sysmem.su

.PHONY: clean-Src

