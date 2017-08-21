################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Car.cpp \
../src/Car_test.cpp \
../src/ParkingLotController.cpp \
../src/ParkingLotController_test.cpp \
../src/Slot.cpp \
../src/Slot_test.cpp \
../src/Test.cpp 

OBJS += \
./src/Car.o \
./src/Car_test.o \
./src/ParkingLotController.o \
./src/ParkingLotController_test.o \
./src/Slot.o \
./src/Slot_test.o \
./src/Test.o 

CPP_DEPS += \
./src/Car.d \
./src/Car_test.d \
./src/ParkingLotController.d \
./src/ParkingLotController_test.d \
./src/Slot.d \
./src/Slot_test.d \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/Users/debashish.g/Sites/progs/parking-lot/cute" -I"/Users/debashish.g/Sites/progs/parking-lot/boost" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


