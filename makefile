main.o : main.c
	gcc -c main.c
tsscreen.o : tsscreen.c
	gcc -c tsscreen.c
tsdrawutil.o : tsdrawutil.c
	gcc -c tsdrawutil.c
test : main.o tsscreen.o tsdrawutil.o
	gcc -o test main.o tsdrawutil.o tsscreen.o
clean : 
	rm *.o test
