#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <libelf.h>
#include <gelf.h>

int
main(int argc, char *argv[])
{
	int fd;
	char *filename = NULL;
	Elf *elf;

	if (argc < 2) {
		fprintf(stderr, "usage: %s: file\n", argv[0]);
		return 1;
	}

	filename = argv[1];

	if ((fd = open(filename, O_RDONLY)) < 0) {
		fprintf(stderr, "%s: can't open %s: %s\n", argv[0],
			filename, strerror(errno));
		return 2;
	}

	if (elf_version(EV_CURRENT) == EV_NONE) {
		fprintf(stderr, "%s: ELF library too old\n", argv[0]);
		return 3;
	}

	if ((elf = elf_begin(fd, ELF_C_READ, (Elf *) 0)) == 0) {
		fprintf(stderr, "%s: ELF read error: %s\n", argv[0],
			elf_errmsg(elf_errno()));
		return 4;
	}

	size_t scn_stab = 0;

	if(elf_getshdrstrndx(elf, &scn_stab) < 0) {
		fprintf(stderr, "%s: no string table: %s\n", argv[0],
			elf_errmsg(elf_errno()));
		return 5;
	}

	printf("Section names are in section #%lu\n", scn_stab);

	Elf_Scn *elf_scn = NULL;
	GElf_Shdr sh;

	while ((elf_scn = elf_nextscn(elf, elf_scn))) {

		if (gelf_getshdr(elf_scn, &sh) == NULL) {
			fprintf(stderr, "%s: no section header for %p\n",
				argv[0], elf_scn);
			continue;
		}

		char *name = elf_strptr(elf, scn_stab, sh.sh_name);
		size_t stab = sh.sh_link;

		printf("Elf Section: name = %s, addr = 0x%lx, stab = #%zu\n",
			name, sh.sh_addr, stab);

		Elf_Data *elf_data = NULL;

		while ((elf_data = elf_getdata(elf_scn, elf_data))) {
			printf("\tElf Data: off = 0x%lx, size = 0x%lu,"
				" type = %u\n",
				elf_data->d_off, elf_data->d_size,
				elf_data->d_type);

			if (strncmp(name, ".symtab", 7) != 0)
				continue;

			/* Extract symbols from .symtab section */

			int i = 0;
			GElf_Sym sym; 

     			while (gelf_getsym(elf_data, i++, &sym) == &sym) {

				/* Symbol had been read */

				if (GELF_ST_TYPE(sym.st_info) != STT_OBJECT)
					continue; /* we look for data symbols */

//				if (sym.st_value > 0xfffffff)
//					continue; /* not applicable for ELF */

				printf("\t\tSymbol = %s, info = 0x%02X, "
					"sect = #%u, size = %lu, addr = 0x%lx\n",
					elf_strptr(elf, stab, sym.st_name),
					sym.st_info, sym.st_shndx, sym.st_size,
					sym.st_value);

				/* Access section of symbol data */

				Elf_Scn *scn = elf_getscn(elf, sym.st_shndx);

				if (scn == NULL) {
					printf("\t\tCannot get section #%u\n",
						sym.st_shndx);
					continue;
				}

				if (gelf_getshdr(scn, &sh) == NULL) {
					printf("\t\tCannot get SH for #%u\n",
						sym.st_shndx);
					continue;
				}

				Elf_Data *data = elf_getdata(scn, NULL);

				if (data == NULL) {
					printf("\t\tCannot get data for #%u\n",
						sym.st_shndx);
					continue;
				}

				if (data->d_buf == NULL) {
					printf("\t\tNo data buf for sec #%u\n",
						sym.st_shndx);
					continue;
				} 

				uint32_t val1 =
				  *(uint32_t*)((uint8_t*)data->d_buf +
					0 + sym.st_value - sh.sh_addr);

				uint32_t val2 =
				  *(uint32_t*)((uint8_t*)data->d_buf +
					4 + sym.st_value - sh.sh_addr);

				uint32_t val3 =
				  *(uint32_t*)((uint8_t*)data->d_buf +
					8 + sym.st_value - sh.sh_addr);

				printf("\t\tval1 = 0x%0x (%u), val2 = 0x%0x (%u)"
					", val3 = 0x%0x (%u)\n",
					val1, val1, val2, val2, val3, val3);

			}

		}
	}

	elf_end(elf);

	return 0;
}
