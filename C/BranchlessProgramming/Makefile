branchless: branchless.c
	cc -o $@ $<
	objdump -d -M intel -S $@ > $@.S

clean:
	rm -f branchless branchless.S 

