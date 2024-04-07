# Author: Rafael Garibotti

GCC_COMPILER=gcc
CLANG_COMPILER=clang

UNITY_ROOT=../Unity

CFLAGS=-std=c99
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpointer-arith
CFLAGS += -Wcast-align
CFLAGS += -Wwrite-strings
CFLAGS += -Wswitch-default
CFLAGS += -Wunreachable-code
CFLAGS += -Winit-self
CFLAGS += -Wmissing-field-initializers
CFLAGS += -Wno-unknown-pragmas
CFLAGS += -Wstrict-prototypes
CFLAGS += -Wundef
CFLAGS += -Wold-style-definition

TARGET = all_tests.out
SRC_FILES=\
  $(UNITY_ROOT)/src/unity.c \
  $(UNITY_ROOT)/extras/fixture/src/unity_fixture.c \
  src/foo.c \
  test/Test.c \
  test/test_runners/Test_Runner.c \
  test/test_runners/all_tests.c
INC_DIRS=-Isrc -I$(UNITY_ROOT)/src -I$(UNITY_ROOT)/extras/fixture/src

all: clean compile run

compile:
	$(GCC_COMPILER) $(CFLAGS) $(INC_DIRS) $(SRC_FILES) -o $(TARGET)

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem --suppress=unusedFunction $(INC_DIRS) src/foo.c

valgrind:
	$(GCC_COMPILER) -g -Wall -Wfatal-errors $(INC_DIRS) $(SRC_FILES) -o $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all ./$(TARGET) -v

sanitizer:
	$(CLANG_COMPILER) -g -Wall -Wfatal-errors -fsanitize=address $(INC_DIRS) $(SRC_FILES) -o $(TARGET)
	./$(TARGET) -v

cov:
	$(GCC_COMPILER) $(CFLAGS) -fprofile-arcs -ftest-coverage $(INC_DIRS) $(SRC_FILES) -o $(TARGET)
	./$(TARGET) -v
	gcov -b foo.c

run:
	./$(TARGET) -v

clean:
	rm -fr $(TARGET) *.gcno *.gcda *.gcov *.dSYM 
