OBJS= main.cc cpu.cc cpu.h main_class.h main_class.cc traits.h debug.cc debug.h system.cc system.h thread.h thread.cc
OBJ_NAME = main
CC= g++

COMPILER_FLAGS= -v

LINKER_FLAGS= -lrt -lpthread

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

