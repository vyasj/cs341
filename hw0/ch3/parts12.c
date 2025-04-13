#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
	printf("argc: %d\n", argc);
	printf("executable name: %s\n", *argv);
	int count = 1;
	int total = 0;
	for ( ; count < argc; count++) {
		total = total + atoi(argv[count]);
		printf("argument %d: %s\n", count, argv[count]);
	}
	printf("total: %d\n", total);
	return 0;
}
