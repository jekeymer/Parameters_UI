all:
	gcc `pkg-config --cflags gtk+-3.0` -o notebook notebook.c `pkg-config --libs gtk+-3.0`
