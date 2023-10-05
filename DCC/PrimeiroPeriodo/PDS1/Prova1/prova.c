#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{

	int a = 4;
	int b = 3;

	int x = (a&&b)&(a||b);

	printf("%d", x);
	return EXIT_SUCCESS;

}
