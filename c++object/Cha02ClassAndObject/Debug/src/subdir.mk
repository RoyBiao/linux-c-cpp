################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Arraymax.cpp \
../src/Cha02ClassAndObject.cpp \
../src/Rectangular.cpp \
../src/Time.cpp 

OBJS += \
./src/Arraymax.o \
./src/Cha02ClassAndObject.o \
./src/Rectangular.o \
./src/Time.o 

CPP_DEPS += \
./src/Arraymax.d \
./src/Cha02ClassAndObject.d \
./src/Rectangular.d \
./src/Time.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


