################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources_client.mk
-include subdir_client.mk
-include objects_client.mk

-include sources_server.mk
-include subdir_server.mk
-include objects_server.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C++_DEPS_S)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_DEPS_S)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CC_DEPS_S)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CPP_DEPS_S)),)
-include $(CPP_DEPS_S)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CXX_DEPS_S)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS_S)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

.DEFAULT_GOAL := all

# All Target
all: mail_client mail_server

# Tool invocations
mail_client: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o "mail_client" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

mail_server: $(OBJS_S) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross G++ Linker'
	g++  -o "mail_server" $(OBJS_S) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	$(RM) mail_client mail_server $(C++_DEPS_S)$(C++_DEPS)$(OBJS)$(OBJS_S)$(C_DEPS)$(C_DEPS_S)$(CC_DEPS)$(CC_DEPS_S)$(EXECUTABLES)$(EXECUTABLES_S)$(CXX_DEPS)$(C_UPPER_DEPS)$(CXX_DEPS_S)$(C_UPPER_DEPS_S)$(CPP_DEPS)$(CPP_DEPS_S)


.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets