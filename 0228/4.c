
// K: manpage
//  => 1: Shell
//     2: System Call
//     3: Library

#include <stdio.h>
#include <math.h>

int main() {
	double a = 0.7;
	double b = 0.1 * 7.0;

	printf("a: %lf\n", a);
	printf("b: %lf\n", b);

	if (fabs(a-b) < 0.000001) {
		printf("Same\n");
	} else {
		printf("Diff\n");
	}
}
#if 0
int main() {
	double a = 0.7;
	double b = 0.1 * 7.0;

	if (a == b) {
		printf("Same\n");
	} else {
		printf("Diff\n");
	}
}
#endif
