#Compiler
CC = g++

#Compiler flags
CFLAGS = -Wall -g -std=c++11

# Include directory
IDIR = -I../include/

# SRC directory
SRCDIR = ../src/

# SRC targets
SRC = avl_tree

# TEST directory
TESTDIR = ../test/

TEST = main

#OBJ directory
OBJDIR = ../obj/

#UNIT directory
UNIT = ../uni/

#UNIT Targets
UNI = unittest

all: $(SRC) $(TEST) $(UNI)
	@$(CC) $(CFLAGS) $(IDIR) -o AVL_TREE $(OBJDIR)$(SRC).o $(OBJDIR)$(TEST).o
	@$(CC) $(CFLAGS) $(IDIR) -o uni_test $(OBJDIR)$(SRC).o $(OBJDIR)$(UNI).o

$(TEST):
	@$(CC) $(CFLAGS) $(IDIR) -c $(TESTDIR)$@.cpp
	@mv $(TEST).o $(OBJDIR)

$(SRC):
	@$(CC) $(CFLAGS) $(IDIR) -c $(SRCDIR)$@.cpp
	@mv $(SRC).o $(OBJDIR)

$(UNI):
	@$(CC) $(CFLAGS) $(IDIR) -c $(UNIT)$@.cpp
	@mv $(UNI).o $(OBJDIR)

clean:
	@rm -f $(OBJDIR)*.o
	@rm AVL_TREE
	@rm uni_test

run_unittest:
	@./uni_test

run:
	@./AVL_TREE
