
#include <stdio.h>
#include "parser.h"

int main(int argc, char** argv)
{
	char str[100];
	char result[300];
	scanf("%s", str);
	parse(str, result);
	printf("%s", result);
	return 0;
}
