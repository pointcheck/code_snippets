OBJS = program.o a.o b.o c.o
HDRS = defs.h
CFLAGS =
CC = gcc

program : $(OBJS)
	$(CC) $(CFLAGS) -o $(.TARGET) $(.ALLSRC)

$(OBJS) : $(.PREFIX).c $(HDRS)
	$(CC) $(CFLAGS) -c $(.PREFIX).c


clean:
	rm -rf *.o program
