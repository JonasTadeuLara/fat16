all:
	gcc main.c -o fat -g -Wall
run:
	./fat
clean:
	clear
	rm fat
