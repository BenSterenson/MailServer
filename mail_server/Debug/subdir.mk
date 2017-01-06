################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Mail_server.cpp \
../Server.cpp \
../Server_General.cpp \
../Server_MSG_Compose.cpp \
../Server_MSG_Delete_Mail.cpp \
../Server_MSG_Get_Mail.cpp \
../Server_MSG_Login.cpp \
../Server_MSG_Online_Users.cpp \
../Server_MSG_Quit.cpp \
../Server_MSG_Show_Inbox.cpp \
../Server_Message.cpp 

OBJS += \
./Mail_server.o \
./Server.o \
./Server_General.o \
./Server_MSG_Compose.o \
./Server_MSG_Delete_Mail.o \
./Server_MSG_Get_Mail.o \
./Server_MSG_Login.o \
./Server_MSG_Online_Users.o \
./Server_MSG_Quit.o \
./Server_MSG_Show_Inbox.o \
./Server_Message.o 

CPP_DEPS += \
./Mail_server.d \
./Server.d \
./Server_General.d \
./Server_MSG_Compose.d \
./Server_MSG_Delete_Mail.d \
./Server_MSG_Get_Mail.d \
./Server_MSG_Login.d \
./Server_MSG_Online_Users.d \
./Server_MSG_Quit.d \
./Server_MSG_Show_Inbox.d \
./Server_Message.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


