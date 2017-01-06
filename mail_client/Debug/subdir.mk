################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Client.cpp \
../General.cpp \
../MSG_Compose.cpp \
../MSG_Delete_Mail.cpp \
../MSG_Get_Mail.cpp \
../MSG_Login.cpp \
../MSG_Quit.cpp \
../MSG_Show_Inbox.cpp \
../Message.cpp \
../Reply.cpp \
../main.cpp 

OBJS += \
./Client.o \
./General.o \
./MSG_Compose.o \
./MSG_Delete_Mail.o \
./MSG_Get_Mail.o \
./MSG_Login.o \
./MSG_Quit.o \
./MSG_Show_Inbox.o \
./Message.o \
./Reply.o \
./main.o 

CPP_DEPS += \
./Client.d \
./General.d \
./MSG_Compose.d \
./MSG_Delete_Mail.d \
./MSG_Get_Mail.d \
./MSG_Login.d \
./MSG_Quit.d \
./MSG_Show_Inbox.d \
./Message.d \
./Reply.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


