
#include <stdio.h>
#include <stdlib.h>

#define REV_POLYNOMIAL	0xa001 // Reversed polynomial: 0b1000000000000101

unsigned short crc16usb(unsigned short input, unsigned short res)
{
	unsigned short b;
	int i;

	for (i = 0;  i < 16;  ++i) {
		b = (input ^ res) & 1;
		input >>= 1;
		if (b) {
			res = (res >> 1) ^ REV_POLYNOMIAL; /* 1010 0000 0000 0001 */
		} else {
			res = (res >> 1);
		}
	}
	return res;
}

int main(int argc, char *argv[]) {
	unsigned short data;
	unsigned short crc = 0xffff; // initial value
	unsigned short mask = 0x001;

	if(argc < 2) {
		printf("Usage: %s <16bit_data0> <16bit_data1> <16bit_data2> ... <16bit_dataN>\n", argv[0]);
		return -1;
	}

	argv++;

	while(argc-- > 1) {

		data = strtol(*argv++, NULL, 0) & 0xffff; // only low 16 bits are valid

		printf("CRC16-USB data: 0x%04x\n", data);

		crc = crc16usb(data, crc);
	}

	crc = crc ^ 0xffff; // XOR all bits as per USB specification 
		
	printf("CRC16-USB: crc = 0x%04x, bits to send: ", crc);

	for(int i = 0; i < 16; i++)
		printf("%d ", (crc & mask) ? 1 : 0), mask <<= 1; 

	printf("\n");

	return crc;
}

