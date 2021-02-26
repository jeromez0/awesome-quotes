## str_maxlenoc
## File description: This C make file can help to build the str_maxlenoc program/executable.

CC = gcc

# The CFLAGS variable sets compile flags for gcc:
#  -g        				compile with debug information
#  -Wall -Werror -Wextra    give verbose compiler warnings
#  -O0       				do not optimize generated code
CFLAGS = -g -Wall -Werror -Wextra -O0 -fsanitize=address

# The LDFLAGS variable sets flags for linker
#  -lm   says to link in libm (the math library)
LDFLAGS = -lm

# In this section, you list the files that are part of the project.
SOURCES = main.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = read_quotes

# The first target defined in the makefile is the one
# used when make is invoked with no argument. 

$(TARGET) : $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

# Phony means not a "real" target, it doesn't build anything
# The phony target "clean" is used to remove all compiled object files.

.PHONY: clean

clean:
	@rm -f $(TARGET) $(OBJECTS) core