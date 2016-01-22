################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Box.cpp \
../src/Cha03ClassAndObject2.cpp \
../src/Compare.cpp \
../src/SaleStaff.cpp \
../src/Student.cpp \
../src/Time.cpp 

OBJS += \
./src/Box.o \
./src/Cha03ClassAndObject2.o \
./src/Compare.o \
./src/SaleStaff.o \
./src/Student.o \
./src/Time.o 

CPP_DEPS += \
./src/Box.d \
./src/Cha03ClassAndObject2.d \
./src/Compare.d \
./src/SaleStaff.d \
./src/Student.d \
./src/Time.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


