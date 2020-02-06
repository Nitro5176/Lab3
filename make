Main: Assignment1Retry.c helper.c helper.h
		gcc -g Assignment1Retry.c helper.c helper.h -w -wall -g

Assignment1Retry.o: Assignment1Retry.c helper.c helper.h
						gcc -c Assignment1Retry.c helper.c helper.h
helper.o: helper.c, helper.h
			-gcc -c helper.c helper.h


clean: Assignment1Retry.c, helper.c helper.h
		-rm Assignment1Retry.c helper.c helper.h