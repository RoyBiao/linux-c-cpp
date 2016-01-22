################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/core/point/Pointer.cpp 

OBJS += \
./src/core/point/Pointer.o 

CPP_DEPS += \
./src/core/point/Pointer.d 


# Each subdirectory must supply rules for building sources it contributes
src/core/point/%.o: ../src/core/point/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


