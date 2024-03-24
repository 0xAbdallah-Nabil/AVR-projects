################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/DIO_Program.c \
../source/EXT_interrupt_program.c \
../source/GI_program.c \
../source/LCD_Program.c \
../source/SSD_Program.c \
../source/TIMER_program.c \
../source/main.c \
../source/motor_program.c \
../source/servo_program.c \
../source/ultrasonic_program.c 

OBJS += \
./source/DIO_Program.o \
./source/EXT_interrupt_program.o \
./source/GI_program.o \
./source/LCD_Program.o \
./source/SSD_Program.o \
./source/TIMER_program.o \
./source/main.o \
./source/motor_program.o \
./source/servo_program.o \
./source/ultrasonic_program.o 

C_DEPS += \
./source/DIO_Program.d \
./source/EXT_interrupt_program.d \
./source/GI_program.d \
./source/LCD_Program.d \
./source/SSD_Program.d \
./source/TIMER_program.d \
./source/main.d \
./source/motor_program.d \
./source/servo_program.d \
./source/ultrasonic_program.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


