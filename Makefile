all: program1 program2 program3

program1: lcsup.o
	g++ -std=c++1y -lm -o program1 lcsup.o
	
lcsup.o: lcsup.cpp lcsup.h
	g++ -std=c++1y -g -c lcsup.cpp -o lcsup.o
	
program2: lcsrec.o
	g++ -std=c++1y -lm -o program2 lcsrec.o
	
lcsrec.o: lcsrec.cpp lcsrec.h
	g++ -std=c++1y -g -c lcsrec.cpp -o lcsrec.o
	
program3: lcsdown.o
	g++ -std=c++1y -lm -o program3 lcsdown.o
	
lcsdown.o: lcsdown.cpp lcsdown.h
	g++ -std=c++1y -g -c lcsdown.cpp -o lcsdown.o
	
checkmem: program3
	valgrind --track-origins=yes ./program3 $(ARGS)

run: program3
	./program3 $(ARGS)

clean:
	rm *.o program1 program2 program3 vgcore.* output.txt output1.txt output2.txt output3.txt
	
full: program1 program2 program3
	./program1 filex.txt filey.txt output1.txt
	./program2 filex.txt filey.txt output2.txt
	./program3 filex.txt filey.txt output3.txt