all: compile diff

compile: main.c
	cc -Wno-implicit-function-declaration -o main main.c
	./main > main_new.c
	cc -Wno-implicit-function-declaration -o main_new main_new.c
	./main_new > main_new_new.c

diff:
	diff main.c main_new_new.c
	@echo "main_new_new.c is same as main.c"
	@echo "--- main.c ---"
	@cat main.c
	@echo "--- main_new_new.c ---"
	@cat main_new_new.c

clean:
	rm -f main main_new.c main_new main_new_new.c
