all:
	cc -o bof1 bof1.c
	cc -fsanitize=address -g -o bof1-sanitized bof1.c

test:
	-./bof1 Test1
	-./bof1 Test22222222222222222222222222222222222222222222222222222
	-./bof1-sanitized Test33333333333333333333333333333333333333333333333333333

clean:
	-rm bof1
	-rm bof1-sanitized
