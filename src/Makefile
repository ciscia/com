############### Compilation configuration ################
#CROSS_COMPILE = arm-none-eabi-
AS = $(CROSS_COMPILE)as
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)gcc
SIZE = $(CROSS_COMPILE)size
OBJCOPY = $(CROSS_COMPILE)objcopy

#Program name
PROG = com
#Where to compile the .o
BUILD_DIR = bin

INCLUDES+=-Iext

CFLAGS += -Wall -g $(INCLUDES)
VPATH += ext
LIBS=-lpthread

PROJ_OBJ = oam.o oal.o com.o
OBJS = $(PROJ_OBJ)

all: $(PROG)

$(PROG) : $(OBJS)
	@$(CC) -o $(BUILD_DIR)/$@ $(addprefix $(BUILD_DIR)/, $(OBJS)) $(INCLUDES) $(LIBS)
	@echo [L] $(PROG)

%.o : %.c
	@echo [C] $@
	@$(CC) -o $(BUILD_DIR)/$@ -c $< $(CFLAGS)

clean:
	@rm -rf $(BUILD_DIR)/$(PROG) $(addprefix $(BUILD_DIR)/, $(OBJS))
	@echo D ALL
