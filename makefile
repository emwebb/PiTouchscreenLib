test.o : test.c
	gcc -c test.c
tsscreen.o : tsscreen.c
	gcc -c tsscreen.c
tsdrawutil.o : tsdrawutil.c
	gcc -c tsdrawutil.c
bin :
	mkdir bin
test : test.o tsscreen.o tsdrawutil.o bin
	gcc -o bin/test test.o tsdrawutil.o tsscreen.o
clean :
	rm -rf *.o bin
