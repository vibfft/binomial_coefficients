#---------------------------------------------------
# Makefile for Subset.c 
#---------------------------------------------------
EXEBIN = Subset
SOURCES = $(EXEBIN).c
OBJECTS = $(EXEBIN).o
FLAGS = -std=c99 -Wall
FILES = $(SOURCES) Makefile
$(EXEBIN) : $(OBJECTS)
	gcc -o $(EXEBIN) $(OBJECTS)
$(OBJECTS) : $(SOURCES)
	gcc -c $(FLAGS) $(SOURCES)
unit :
	/bin/bash Test${EXEBIN}.sh
clean :
	rm -f $(EXEBIN) $(OBJECTS)
submit: $(FILES)
	$(SUBMIT) $(FILES)
