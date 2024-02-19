#include <stdio.h>

int main() {
	char s[7] = "aaaaaa";
	int v4;

	v4 = (s[3] ^ 0x1337) + 6221293;
    for (int i = 0; i < 6; ++i ) {
      if ( s[i] <= 31 )
        return 1;
      v4 += (v4 ^ (unsigned int)s[i]) % 0x539;
    }
		printf("%i\n", v4);
    return 0;
}