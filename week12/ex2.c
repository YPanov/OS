#include <stdio.h>
#include <errno.h>

int main(int args, char *argv[]) {
	if (args > 3) {
		perror("There are too many arguments\n");
		return E2BIG;
	}


	if (args == 1) {
		while (!feof(stdin)) {
			char c;
			scanf("%c", &c);
			printf("%c", c);
		}

		return 0;
	}


	if (args == 2) {
		FILE *fileOut = fopen(argv[1], "w");

		while (!feof(stdin)) {
			char c;
			scanf("%c", &c);
			fprintf(fileOut, "%c", c);
			printf("%c", c);
		}

		fclose(fileOut);
		return 0;
	}


	if (args == 3) {
		if (!(argv[1][0] == '-' && (argv[1][1] == 'a' || argv[1][1] == 'A'))) {
			perror("Unknown argument or there is a wrong order of arguments\n");
			return EINVAL;
		}

		FILE *fileOut = fopen(argv[2], "a");

		while (!feof(stdin)) {
			char c;
			scanf("%c", &c);
			fprintf(fileOut, "%c", c);
			printf("%c", c);
		}

		fclose(fileOut);
		return 0;
	}

	return 0;
}
