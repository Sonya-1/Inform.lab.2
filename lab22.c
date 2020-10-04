#include <stdio.h>

void init_arr(char* arr, int len, int value) {
	int i;
	for (i = 0; i < len; i++) {
		arr[i] = value;
	}
}

void fill_table(char* sub, int sub_len, char* table) {
	int i;
	char c;

	init_arr(table, 256, sub_len);

	for (i = sub_len - 2; i >= 0; i--) {
		c = sub[i];
		if (table[c] == sub_len) {
			table[c] = sub_len - i - 1;
		}
	}
	c = sub[sub_len - 1];
	table[c] = sub_len;
}

int strlen(char* str, int max_len) {
	int i;
	for (i = 0; i < max_len; i++) {
		if (str[i] == '\0') {
			break;
		}
	}
	return i;
}

int strcomp(char* a, char* b, int len) {
	int i;
	for (i = 0; i < len; i++) {
		if (a[i] != b[i]) {
			return 0;
		}
	}
	return 1;
}

int strstr(char* str, char* sub, int strlen, int sublen, char* table) {
	int i, step;
	char c;

	for (i = 0, step = 1; i <= strlen - sublen && step >= 1; i += step) {
		if (1 == strcomp(str + i, sub, sublen)) {
			return i;
		}
		c = str[i + sublen - 1];
		step = table[c];
	}
	return -1;
}

int main()
{
	char str[256], sub[256], table[256];
	int len_str, len_sub, pos, counter = 0;
	char* cursor;

	printf("Input string: ");
	gets_s(str, 256);
	len_str = strlen(str, 256);

	if (len_str == 0) {
		printf("Empty string\n");
		return 0;
	}

	printf("Input model: ");
	gets_s(sub, 256);
	len_sub = strlen(sub, 256);

	fill_table(sub, len_sub, table);

	if (len_sub == 0) {
		printf("No data\n");
		return 0;
	}

	cursor = str;

	while (1) {
		pos = strstr(cursor, sub, len_str, len_sub, table);

		if (pos < 0) {
			if (counter == 0) {
				printf("Model not found\n");
			}
			break;
		}
		counter += 1;

		printf("Position: %d\n", cursor - str + pos);
		cursor += pos + len_sub;
	}
	return 0;
}
