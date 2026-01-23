##basics
#
#file = test.c
#
#display:
#	@echo "hello dafiicult"
#all : display
#	@gcc -W -W -W $(file) -o pro
#
#clean:
#	@clear
#	@rm cprogram
#
##functions
## @ '$@' is name of 'target'
#define func
#	@echo "desplay this..."
#	@echo " 0 is $0"
#	@echo " 1 is $1"
#	@echo " 2 is $2"
#	@echo " @ is $@"
#	@echo "exit function"
#endef
## x = is variable name you can do x:= it's the samething
#x = hamza
#target1:
#	$(call func,dafiicult,$(x))
#	@echo
#	@echo "target is $@"
#target2:
#
##loops in makefile
#
#LIST = one two three
#loop1:
#	@for i in $(LIST); do \
#		echo $$i; \
#	done
#
##loop foreach function
#
#LIST2 = am not in three
#	LIST_2 = $(foreach i,$(LIST2),"\nWord is $(i)")
#loop2:
#	@echo $(LIST_2)
#
##if condition
## ifeq = if equal
#
#file = test.c
#ifeq '$(file)' 'test.c'
#cond1:
#	@echo "true"
#endif
#
#cond2:
#ifeq '$(file)' 'test.c'
#	@echo "TRUE"
#endif
#
##ifdef = 'bar' take 'var' is this 'var' is define or not
#
#var = true
#bar = var
#cond3:
#ifdef $(bar)
#	@echo "YES"
#else
#	@echo "NO"
#endif
#
## PHONY
#
##if we have file name "clean" and rull name "clean" it's error when you make
##the erro is show you this msg "make: 'clean1' is up to date." ---> use : .PHONY: "name rul"
#.PHONY: clean1
#clean1: 
#	@echo "if you see me it's working :|"
##################################################################################################
##include -----> use
##create a file nameit "makeconfig"
##and use it as library
#include makeconfig
#
#
#build: compile
#	$(CC) $(fileC) -o cprogram
#
#compile:
#	$(CC) -c $(fileC)
###############################
#include makeconfig
#
#var2 = $(file:.c=.o)
#
#build2: $(var2)
#	@echo "compilation is done"
#	@echo "var2 is $(var2)"
#build3 : build2
#	$(CC) $(var2) -o runprogram
#clean2:
#	@rm test.o
#	@rm runprogram
#	@clear
###################################
#create library

file := test.c test2.c
CC := gcc
FLAGS := -Wall -Wextra -Werror 
PATH_TO := "run"
LIB_PATH := ./lib


CRlib:
	@$(MAKE) -C $(LIB_PATH) $@

build4:CRlib
	$(CC) $(FLAGS) $(file) -I $(LIB_PATH) -lmylib -L $(LIB_PATH) -o $(PATH_TO)

.PHONY:clean
clean:
	@echo "remove file $(PATH_TO)"	
	@rm -f *.o
	@rm run
	@$(MAKE) -C $(LIB_PATH) $@