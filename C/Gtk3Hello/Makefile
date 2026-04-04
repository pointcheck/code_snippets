CFLAGS = `pkg-config --cflags gtk+-3.0` `pkg-config --libs gtk+-3.0`

gtk3hello: main.c
	cc $(CFLAGS) -o gtk3hello main.c

clean: gtk3hello
	rm -rf gtk3hello

	
