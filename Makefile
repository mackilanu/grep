# _*_ MakeFile _*_

grep: main.o grep.o
	gcc -Wall -o grep main.o grep.o

main.o: src/main.c
	gcc -c src/main.c

grep.o: src/grep.c
	gcc -c src/grep.c

clean:
	rm *.o grep