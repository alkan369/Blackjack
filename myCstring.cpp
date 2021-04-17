#include "myCstring.h"

void myStrCpy(char text1[],size_t size ,const char text2[]) {
	int i = 0;
	for (; text2[i] != '\0' && i < size; i++) {
		text1[i] = text2[i];
	}
	text1[i] = '\0';
}

int myStrlen(const char arr[]) {
	int cnt = 0;
	while (arr[cnt]) {
		++cnt;
	}
	return cnt;
}

void toSmall(char arr[]) {
	for (int i = 0; arr[i] != '\0'; i++) {
		if (arr[i] >= 'A' && arr[i] <= 'Z') {
			arr[i] = arr[i] + 32;
		}
	}
}

int myStrcmp(char text1[],const char text2[]) {
	while (*text1 && *text2 && *text1 == *text2) {
		++text1;
		++text2;
	}
	return *text1 - *text2;
}