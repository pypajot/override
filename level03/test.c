int main() {
	char *str = "Q}|u`sfg~sf{}|a3";
	char str_result[17];
	for(int i = 1; i < 22; i++) {
		for (int j = 0; j < strlen(str); j++) {
			str_result[j] = str[j] ^ i;
		}
		printf("%s   %i\n", str_result, i);
	}
}
