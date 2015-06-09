UANME = $(shell uname)
ROOT = $(shell pwd)

## TODO move to config.mk
#include $(PROJROOT)/config.mk
#VERBOSE ?= 0
#
#ifeq "$(VERBOSE)" "0"
#QUIET=@
#else
#QUIET=
#endif
#
CC = $(QUIET)g++
#CFLAGS :=  -pipe -c -Wall -g -O0 -std=c99
#CPPFLAG = -DDEBUG
#######################3


TARGET =
CLEAN_TARGETS =


INCDIRS ?= -I$(ROOT)/src
## FIXME
INCDIRS += -I$(ROOT)/libs/tinyxml2
INCDIRS += -I$(ROOT)/libs/SOIL/src
INCDIRS += -I$(ROOT)/libs
CFLAGS := -I.  $(INCDIRS)
LDFLAGS =  -lGLU
TARGET := Simple2D

SOURCEDIR ?= $(ROOT)/src

TARGETS = 2DInterface.cpp \
		  Main.cpp \
		  Transactions.cpp \

OBJECTS := $(TARGETS:.cpp=.o)

all: $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)


$(OBJECTS): %.o : $(SOURCEDIR)/%.cpp
	@echo [CC] $(SOURCEDIR)/$<
	$(CC) -c $(TEST_CFLAG) $(CFLAGS) $(CPPFLAG)  $< -o $@



# TODO
#all: $(ALL_TARGES)









