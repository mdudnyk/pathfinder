#include "pathfinder.h"

int my_atoull(const char *str) {
	unsigned long long num = 0;
	int index = 0;

	for ( ; str[index]; index++)
		if (mx_isdigit(str[index])) {
			num = (num * 10) + (str[index] - '0');
		}
		else
			break;
	if (num > 2147483647)
		return (int)-1;
	return (int)num;
}
