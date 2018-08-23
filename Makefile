CC=$(CROSS_COMPILE)gcc
CXX=$(CROSS_COMPILE)g++
CFLAGS=-Wall -std=gnu++11 

SRC_EXT:= cpp
HDR_EXT:= hpp
HEADERS         := $(wildcard *.$(HDR_EXT))
SOURCES         := $(wildcard *.$(SRC_EXT))
OBJECTS         := $(patsubst %.$(SRC_EXT),%.o,$(SOURCES))

HOME=$(shell echo ~)
INCLUDES=-I/usr/include/
LDLIBS= -lpthread -lgnutls

EXECUTABLE=doit
 
OBJS := $(SOURCES:.$(SRC_EXT)=.o)
 
all: $(OBJS)
	$(CXX) $(CFLAGS)  -o $(EXECUTABLE) $(OBJS) $(LDLIBS)
 
.$(SRC_EXT).o:
	$(CXX) $(CFLAGS) -c $(CXXFLAGS) $(INCLUDES)  -o $@ $<
 
clean:
	rm -rf $(OBJS)
	rm -rf $(EXECUTABLE)
	rm -rf ./*.o
