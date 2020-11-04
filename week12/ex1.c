#include <stdio.h>

int main() {
	FILE *randomC = fopen("/dev/random", "r");
	char randomChars[21];
	fscanf(randomC, "%c", randomChars);
	fclose(randomC);
	randomChars[20] = '\0';
	char *iterat = randomChars;

	for (int i = 0; i < 20; ++i, iterat++)
		*iterat = (*iterat % (char) 62) + (char) 65;
	

	FILE *fileOut = fopen("ex1.txt", "w");
	fprintf(fileOut, "%s\n", randomChars);
	fclose(fileOut);

	return 0;
}
