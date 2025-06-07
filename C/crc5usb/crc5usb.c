// Cortesy: https://electronics.stackexchange.com/questions/718294/how-is-crc5-calculated-in-detail-for-a-usb-token

#include <stdio.h>
#include <stdlib.h>

#define REV_POLYNOMIAL	0x14 // Reversed polynomial: 0b00101

unsigned char crc5usb(unsigned short input)
{
	unsigned char res = 0x1f;
	unsigned char b;
	int i;

	for (i = 0;  i < 11;  ++i) {
		b = (input ^ res) & 1;
		input >>= 1;
		if (b) {
			res = (res >> 1) ^ REV_POLYNOMIAL; /* 10100 */
		} else {
			res = (res >> 1);
		}
	}
	return res ^ 0x1f;
}

int main(int argc, char *argv[]) {
	unsigned short data = 0x0000;
	unsigned char mask = 0x01;
	

	if(argc > 1)
		data = strtol(argv[1], NULL, 0);

	unsigned char crc = crc5usb(data);

	printf("CRC5-USB: data = 0x%03x, crc = 0x%02x, bits to send: ", data, crc);

	for(int i = 0; i < 5; i++)
		printf("%d ", (crc & mask) ? 1 : 0), mask <<= 1; 

	printf("\n");
		
	return crc;
}

