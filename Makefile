all:
	gcc ./main.c ./board.c ./replay.c
	./a.out

clean:
	rm a.out