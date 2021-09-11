################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC.c \
../DCmotor.c \
../INT1.c \
../Mini_Project2.c \
../Timer.c \
../lcd.c 

OBJS += \
./ADC.o \
./DCmotor.o \
./INT1.o \
./Mini_Project2.o \
./Timer.o \
./lcd.o 

C_DEPS += \
./ADC.d \
./DCmotor.d \
./INT1.d \
./Mini_Project2.d \
./Timer.d \
./lcd.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


