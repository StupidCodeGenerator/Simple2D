
LIB_TARGET := libSimple2D.a


LIB_SRC :=  \
   SOIL/image_helper.c \
   SOIL/stb_image_aug.c  \
   SOIL/image_DXT.c \
   SOIL/SOIL.c  \
   tinyxml2/tinyxml2.cpp \


all : $(LIB_TARGET)

LIB_C_SRC = $(filter %.c,$(LIB_SRC))
LIB_CPP_SRC  = $(filter %.cpp,$(LIB_SRC))

LIB_COBJ = $(LIB_C_SRC:.c=.o)
LIB_CPPOBJ = $(LIB_CPP_SRC:.cpp=.o)

$(LIB_TARGET) : $(LIB_COBJ) $(LIB_CPPOBJ)
	$(AR) rcs $(LIB_TARGET) $(LIB_COBJ) $(LIB_CPPOBJ)

$(LIB_COBJ): %.o : %.c
	$(CC) $(CXXFLAGS) -o $@ -c $<

$(LIB_CPPOBJ): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

## $ALL_TARGET += LIB_TARGET


