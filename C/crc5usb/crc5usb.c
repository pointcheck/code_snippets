// Cortesy: https://electronics.stackexchange.com/questions/718294/how-is-crc5-calculated-in-detail-for-a-usb-token

#include <stdio.h>
#include <stdlib.h>

unsigned char crc5usbrev(unsigned short input)
{
	unsigned char res = 0x1f;
	unsigned char b;
	int i;

	for (i = 0;  i < 11;  ++i) {
		b = (input ^ (res >> 4)) & 1;
		input >>= 1;
		if (b) {
			res = (res << 1) ^ 0x5; /* 00101 */
		} else {
			res = (res << 1);
		}
		res = res & 0x1f;
	}
	return res ^ 0x1f;
}

unsigned char crc5usb(unsigned short input)
{
	unsigned char res = 0x1f;
	unsigned char b;
	int i;

	for (i = 0;  i < 11;  ++i) {
		b = (input ^ res) & 1;
		input >>= 1;
		if (b) {
			res = (res >> 1) ^ 0x14;	/* 10100 */
		} else {
			res = (res >> 1);
		}
	}
	return res ^ 0x1f;
}

int main(int argc, char *argv[]) {
	unsigned short data = 0x0000;

	if(argc > 1)
		data = atoi(argv[1]);

	unsigned char crc = crc5usb(data);
	unsigned char crc_rev = crc5usbrev(data);
	printf("CRC5-USB: data = 0x%03x, crc = 0x%02x, crc_rev = 0x%02x\r\n", data, crc, crc_rev);
}

