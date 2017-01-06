################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
./Client.cpp \
./General.cpp \
./MSG_Compose.cpp \
./MSG_Delete_Mail.cpp \
./MSG_Get_Mail.cpp \
./MSG_Login.cpp \
./MSG_Quit.cpp \
./MSG_Show_Inbox.cpp \
./Message.cpp \
./Reply.cpp \
./main.cpp 

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
Client.o: ./Client.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Client.d" -MT"Client.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

General.o: ./General.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"General.d" -MT"General.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSG_Compose.o: ./MSG_Compose.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"MSG_Compose.d" -MT"MSG_Compose.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSG_Delete_Mail.o: ./MSG_Delete_Mail.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"MSG_Delete_Mail.d" -MT"MSG_Delete_Mail.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSG_Get_Mail.o: ./MSG_Get_Mail.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"MSG_Get_Mail.d" -MT"MSG_Get_Mail.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSG_Login.o: ./MSG_Login.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"MSG_Login.d" -MT"MSG_Login.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSG_Quit.o: ./MSG_Quit.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"MSG_Quit.d" -MT"MSG_Quit.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

MSG_Show_Inbox.o: ./MSG_Show_Inbox.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"MSG_Show_Inbox.d" -MT"MSG_Show_Inbox.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Message.o: ./Message.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Message.d" -MT"Message.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Reply.o: ./Reply.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Reply.d" -MT"Reply.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.o: ./main.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"main.d" -MT"main.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


