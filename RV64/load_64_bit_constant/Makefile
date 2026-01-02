main: main.S
	riscv64-none-elf-as -march=rv64im -g -o main.o main.S 
	riscv64-none-elf-objdump -d main.o > main.disasm

clean:
	rm -rf main.disasm main.o
