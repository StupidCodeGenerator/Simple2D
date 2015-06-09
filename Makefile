UANME = $(shell uname)
ROOT = $(shell pwd)

## TODO move to config.mk
#include $(PROJROOT)/config.mk
VERBOSE ?= 0
#
ifeq "$(VERBOSE)" "0"
QUIET=@
else
QUIET=
endif
#
CC = $(QUIET)g++
#CFLAGS :=  -pipe -c -Wall -g -O0 -std=c99
#CPPFLAG = -DDEBUG
#######################3


TARGET =
CLEAN_TARGETS =


INCDIRS ?= -I src
## FIXME
INCDIRS += -I libs/tinyxml2
INCDIRS += -I libs/SOIL/src
INCDIRS += -I libs
INCDIRS += -I .
CFLAGS := $(INCDIRS) -g -Wall -pipe -O2
LDFLAGS =  -lGL  -lGLU -lglut ./libs/SOIL/lib/libSOIL.a
TARGET := Simple2D


SOURCEDIR ?= ./src

TARGETS = 2DInterface.cpp \
		  Main.cpp \
		  Transactions.cpp \
		  tinyxml2.cpp \



OBJECTS := $(TARGETS:.cpp=.o)

all: $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)


$(OBJECTS): %.o : $(SOURCEDIR)/%.cpp
	@echo [CC] $<
	$(CC) -c $(TEST_CFLAG) $(CFLAGS) $(CPPFLAG)  $< -o $@



# TODO
.PHONY: clean

clean :
	rm -rf *.o










