
#include <stdio.h>

int main() {
	int n = 42;
	int *p = &n;
	printf("%d\n", *&*&*p);
}
