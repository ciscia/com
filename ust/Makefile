#CROSS_COMPILE = arm-none-eabi-
AS = $(CROSS_COMPILE)as
CC = $(CROSS_COMPILE)g++
LD = $(CROSS_COMPILE)gcc
SIZE = $(CROSS_COMPILE)size
OBJCOPY = $(CROSS_COMPILE)objcopy

PROG = ust

LIBS=/home/linker/gtest-1.6.0/lib/.libs/libgtest.a -lpthread
INCLUDES+=-I../src -I../src/ext -I/home/linker/gtest-1.6.0/include

CFLAGS = -DPRE_UST $(INCLUDES) -Wall -g
VPATH += ../src ../src/ext

PROJ_OBJ  = com.o
PROJ_OBJ += oam.o oal.o

UST_OBJ   = ust_com.o

all: $(PROG)

$(PROG) : $(PROJ_OBJ) $(UST_OBJ)
	@echo [L] $@
	@$(CC) -o $@ $(PROJ_OBJ) $(UST_OBJ) $(INCLUDES) $(LIBS)
	@echo [R] $@
	@./ust

$(PROJ_OBJ) : %.o : %.c
	@echo [C] $@
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ 

$(UST_OBJ) : %.o : %.cpp
	@echo [C] $@
	@$(CC) -c $(CFLAGS) $(CPPFLAGS) $< -o $@ 

clean:
	@echo D ALL
	@rm -rf $(PROG) $(PROJ_OBJ) $(UST_OBJ)
