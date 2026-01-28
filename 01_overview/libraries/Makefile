CC = gcc
CFLAGS = -Wall

all: main_static main_dynamic

# 1. Static Library
# Compile source to object file
math_functions.o: math_functions.c
	$(CC) $(CFLAGS) -c math_functions.c

# Create static library archive (.a)
libmath.a: math_functions.o
	ar rcs libmath.a math_functions.o

# Link main with static library
main_static: main.c libmath.a
	$(CC) $(CFLAGS) main.c -L. -lmath -o main_static

# 2. Dynamic Library
# Create dynamic library shared object (.so)
# -fPIC: Position Independent Code
libmath.so: math_functions.c
	$(CC) $(CFLAGS) -fPIC -shared -o libmath.so math_functions.c

# Link main with dynamic library
main_dynamic: main.c libmath.so
	$(CC) $(CFLAGS) main.c -L. -lmath -o main_dynamic

clean:
	rm -f *.o *.a *.so main_static main_dynamic

run_static: main_static
	./main_static

run_dynamic: main_dynamic
	@echo "Note: Need to set LD_LIBRARY_PATH for dynamic linking at runtime"
	LD_LIBRARY_PATH=. ./main_dynamic
