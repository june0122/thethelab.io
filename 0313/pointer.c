#include <stdio.h>

int main() {
	int n = 42;
	int *p = &n;

	printf("%016lx\n", (unsigned long)p);
	printf("%p\n", p);
}
