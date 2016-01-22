################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/core/curl/CurlTest.cpp 

OBJS += \
./src/core/curl/CurlTest.o 

CPP_DEPS += \
./src/core/curl/CurlTest.d 


# Each subdirectory must supply rules for building sources it contributes
src/core/curl/%.o: ../src/core/curl/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


