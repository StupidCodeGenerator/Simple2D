UANME = $(shell uname)
ROOT = $(shell pwd)
TARGET =
CLEAN_TARGETS =
ALL_TARGET =

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
CXX = $(QUIET)g++
#CFLAGS :=  -pipe -c -Wall -g -O0 -std=c99
#CPPFLAG = -DDEBUG
#######################3
LDFLAGS =  -lGL  -lGLU -lglut ./libs/libSimple2D.a
INCDIRS ?= -I src
## FIXME
INCDIRS += -I libs/tinyxml2
INCDIRS += -I libs/SOIL
INCDIRS += -I .
CFLAGS := $(INCDIRS) -g -Wall -pipe -O2

FINAL_TARGET := Simple2D
SOURCEDIR ?= ./src

TARGETS = 2DInterface.cpp \
		  Main.cpp \
		  Transactions.cpp \

OBJECTS := $(TARGETS:.cpp=.o)

ALL_TARGET += $(FINAL_TARGET)


all: $(ALL_TARGET)

$(FINAL_TARGET) : $(OBJECTS)
	$(CXX) -o $@ $^ $(LDFLAGS)


$(OBJECTS): %.o : $(SOURCEDIR)/%.cpp
	@echo [CC] $<
	$(CXX) -c $(TEST_CFLAG) $(CFLAGS) $(CPPFLAG)  $< -o $@


# TODO
.PHONY: clean

clean :
	rm -rf *.o










