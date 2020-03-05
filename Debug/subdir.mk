################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../circularBuffer.c \
../main.c \
../motors.c \
../servo.c \
../uart.c \
../ultrasonic.c 

OBJS += \
./circularBuffer.o \
./main.o \
./motors.o \
./servo.o \
./uart.o \
./ultrasonic.o 

C_DEPS += \
./circularBuffer.d \
./main.d \
./motors.d \
./servo.d \
./uart.d \
./ultrasonic.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


