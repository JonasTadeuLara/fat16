all:
	gcc main.c fat.c -o fat -g -Wall
run:
	./fat
clean:
	clear
	rm fat
