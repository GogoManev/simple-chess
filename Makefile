all:
	gcc ./main.c ./board.c ./replay.c
	./a.exe

clean:
	del a.exe