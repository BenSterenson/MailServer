################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS_S += \
./Mail_server.cpp \
./Server.cpp \
./Server_General.cpp \
./Server_MSG_Compose.cpp \
./Server_MSG_Delete_Mail.cpp \
./Server_MSG_Get_Mail.cpp \
./Server_MSG_Login.cpp \
./Server_MSG_Quit.cpp \
./Server_MSG_Show_Inbox.cpp \
./Server_Message.cpp 

OBJS_S += \
./Mail_server.o \
./Server.o \
./Server_General.o \
./Server_MSG_Compose.o \
./Server_MSG_Delete_Mail.o \
./Server_MSG_Get_Mail.o \
./Server_MSG_Login.o \
./Server_MSG_Quit.o \
./Server_MSG_Show_Inbox.o \
./Server_Message.o 

CPP_DEPS_S += \
./Mail_server.d \
./Server.d \
./Server_General.d \
./Server_MSG_Compose.d \
./Server_MSG_Delete_Mail.d \
./Server_MSG_Get_Mail.d \
./Server_MSG_Login.d \
./Server_MSG_Quit.d \
./Server_MSG_Show_Inbox.d \
./Server_Message.d 



# Each subdirectory must supply rules for building sources it contributes
Mail_server.o: ./Mail_server.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Mail_server.d" -MT"Mail_server.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Server.o: ./Server.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Server.d" -MT"Server.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Server_General.o: ./Server_General.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Server_General.d" -MT"Server_General.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Server_MSG_Compose.o: ./Server_MSG_Compose.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Server_MSG_Compose.d" -MT"Server_MSG_Compose.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Server_MSG_Delete_Mail.o: ./Server_MSG_Delete_Mail.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Server_MSG_Delete_Mail.d" -MT"Server_MSG_Delete_Mail.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Server_MSG_Get_Mail.o: ./Server_MSG_Get_Mail.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Server_MSG_Get_Mail.d" -MT"Server_MSG_Get_Mail.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Server_MSG_Login.o: ./Server_MSG_Login.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Server_MSG_Login.d" -MT"Server_MSG_Login.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Server_MSG_Quit.o: ./Server_MSG_Quit.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Server_MSG_Quit.d" -MT"Server_MSG_Quit.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Server_MSG_Show_Inbox.o: ./Server_MSG_Show_Inbox.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Server_MSG_Show_Inbox.d" -MT"Server_MSG_Show_Inbox.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

Server_Message.o: ./Server_Message.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O0 -g -Wall -c -MMD -MP -MF"Server_Message.d" -MT"Server_Message.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


