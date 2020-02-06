main: Assignment1Retry.o helper.o
		gcc -o main Assignment1Retry.o helper.o

Assignment1Retry.o: Assignment1Retry.c helper.h
						gcc -c Assignment1Retry.c helper.h
helper.o: helper.c
			gcc -c helper.c
			
clean: del assignment.o helper.o


