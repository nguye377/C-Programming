EXECUTABLE = test_smintf
SRC_C = smintf.c
SRC_H = smintf.h clog.h miniunit.h
TEST_C = test_smintf.c
TEST_EXPECTED = expected.txt
TEST_ACTUAL = actual.txt
ASG_NICKNAME = HW06
CC = gcc
CFLAGS = -g -std=c99 -Wall -Wshadow -Wvla -Werror -pedantic
CFLAGS_GCOV = $(CFLAGS) -fprofile-arcs -ftest-coverage
ANSI_RED = \x1b[31m
ANSI_GREEN = \x1b[32m
WHITE = \x1b[0m

#CFLAGS_GCOV = $(CFLAGS) $(SRC_C) $(TEST_C) 
SHELL = /bin/bash

$(EXECUTABLE): $(SRC_C) $(TEST_C) $(SRC_H)
	$(CC) -o $(EXECUTABLE) $(SRC_C) $(TEST_C) $(CFLAGS)
	
test: $(EXECUTABLE) $(TEST_EXPECTED) 
	@if diff -a -B <("./$(EXECUTABLE)") $(TEST_EXPECTED) &> /dev/null ; then \
	    echo -e '$(ANSI_GREEN)Test passed: output of $(EXECUTABLE) matches $(TEST_EXPECTED) $(WHITE)'; \
	    else \
	    echo -e '$(ANSI_RED)Test failed: output of $(EXECUTABLE) does NOT match $(TEST_EXPECTED) $(WHITE)'; \
	    fi
	valgrind ./$(EXECUTABLE)
	
submit: $(SRC_C) $(SRC_H) $(TEST_C) 
	264submit $(ASG_NICKNAME) $(SRC_C) $(TEST_C) $(TEST_EXPECTED)

pretest:
	264test $(ASG_NICKNAME)
	
debug: $(EXECUTABLE)
	 $(EXECUTABLE) -DDEBUG
	
coverage: $(SRC_C) $(TEST_C) $(SRC_H)
	$(CC) -o $(EXECUTABLE) $(SRC_C) $(TEST_C) $(SRC_H) $(CFLAGS_GCOV) -DNDEBUG
	./$(EXECUTABLE)
	gcov -f $(SRC_C)
	
clean: 
	#-rm -f $(EXECUTABLE) $(EXECUTABLE).{gcda,gcno} $(SRC_C).gcov $(SRC).{gcda, gcno} $(TEST_ACTUAL)
	-rm -f $(EXECUTABLE) $(TEST_ACTUAL) *.gcda *.gcno *.gcov 
	
.PHONY: clean pretest debug test submit debug coverage
