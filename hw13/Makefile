EXECUTABLE = test_huffman
SRC_C = huffman.c priority_queue.c frequencies.c
SRC_H = huffman.h priority_queue.h frequencies.h miniunit.h clog.h
TEST_C = test_huffman.c
TEST_EXPECTED = expected.txt
TEST_ACTUAL = actual.txt
ASG_NICKNAME = HW13
CC = gcc
CFLAGS = -g -std=c11 -Wall -Wshadow -Wvla -Werror -pedantic
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
	
submit: $(SRC_C) $(SRC_H) $(TEST_C) 
	264submit $(ASG_NICKNAME) $(SRC_C) $(TEST_C) $(SRC_H) Makefile

pretest:
	264test $(ASG_NICKNAME)
	
debug: $(EXECUTABLE)
	 $(EXECUTABLE) -DDEBUG
	
coverage: 
	$(CC) -o $(EXECUTABLE) $(SRC_C) $(TEST_C) $(CFLAGS_GCOV) #-DNDEBUG
	./$(EXECUTABLE)
	gcov -f $(SRC_C)
	
clean: 
	#-rm -f $(EXECUTABLE) $(EXECUTABLE).{gcda,gcno} $(SRC_C).gcov $(SRC).{gcda, gcno} $(TEST_ACTUAL)
	-rm -f $(EXECUTABLE) $(TEST_ACTUAL) *.gcda *.gcno *.gcov 
	
.PHONY: clean pretest debug test submit debug coverage
