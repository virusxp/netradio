CC=gcc
CXX=g++

CFLAGS=-std=c99 -Wall -Werror -pedantic
CXXFLAGS=-std=c++11 -Wall -Werror -pedantic

INCDIR=inc
SRCDIR=src

SRCS_C=
SRCS_CXX=
OBJS=$(SRCS_CXX:.cpp=.o)$(SRCS_CXX:.c=.o)

.PHONY all, clean

all: $(OBJ)

clean:

%.o: %.c
    $(CC) $(CFLAGS) -c $< 

%.o: %.cpp
