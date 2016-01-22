################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/A.cpp \
../src/B.cpp \
../src/C.cpp \
../src/Cha05InheritanceAndDerivation.cpp \
../src/D.cpp 

OBJS += \
./src/A.o \
./src/B.o \
./src/C.o \
./src/Cha05InheritanceAndDerivation.o \
./src/D.o 

CPP_DEPS += \
./src/A.d \
./src/B.d \
./src/C.d \
./src/Cha05InheritanceAndDerivation.d \
./src/D.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


