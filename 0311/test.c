
#include <stdio.h>

void foo() {
	char *s = "hello";
	s[0] = 'x';
}

int main() {
	foo();
}
