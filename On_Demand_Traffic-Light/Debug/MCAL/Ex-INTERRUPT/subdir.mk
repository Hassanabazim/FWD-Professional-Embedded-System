################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/Ex-INTERRUPT/interrupt.c 

OBJS += \
./MCAL/Ex-INTERRUPT/interrupt.o 

C_DEPS += \
./MCAL/Ex-INTERRUPT/interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/Ex-INTERRUPT/%.o: ../MCAL/Ex-INTERRUPT/%.c MCAL/Ex-INTERRUPT/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


