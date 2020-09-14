# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

CXX=g++
LDFLAGS= -lpthread
CPPFLAGS= -O3 -Wall -pedantic -s
RM=rm -f
SRCS=$(shell find . -name '*.cpp')
OBJS=$(subst .cc,.o,$(SRCS))

all: make

make: $(OBJS)
	$(CXX) $(CPPFLAGS) $(LDFLAGS) -o ./dist/sircppsim $(OBJS)

clean:
	$(RM) $(OBJS)

distclean: clean
	$(RM) ./dist/sircppsim