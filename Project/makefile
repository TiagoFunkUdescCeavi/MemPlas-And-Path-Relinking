RM          = /bin/rm -f
CC          = g++
DEFS        = -std=c++11 -O3 -Wall -fmessage-length=0
PROGNAME    = memplas
INCLUDES    = 
LIBS        = 
#-----------------------------------------------------------------------
 
DEFINES     = $(INCLUDES) $(DEFS)
CFLAGS      = $(DEFINES)
 
SRC         = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
HEADERS     = $(wildcard src/*.h) $(wildcard src/**/*.h)
OBJS        = $(SRC:.cpp=.o)
 
DATE        = $(shell date +%Y-%d-%m)
 
.cpp.o:
	@echo 'Building file: $<'
	@echo 'Invoking: Cross GCC Compiler'
	$(CC) $(CFLAGS) -c $*.cpp -o $*.o
	@echo 'Finished building: $<'
	@echo ' '
     
all: $(PROGNAME)
 
$(PROGNAME) : $(OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: Cross GCC Linker'
	$(CC) $(LIBS) $(OBJS) -o $(PROGNAME)
	@echo 'Finished building target: $@'
	@echo ' '
     
clean:
	$(RM) $(PROGNAME) $(OBJS)
	@echo ' '
