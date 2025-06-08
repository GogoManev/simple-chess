all:
	gcc ./main.c ./board.c
	./a.exe

clean:
	del a.exe