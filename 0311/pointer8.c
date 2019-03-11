#include <stdio.h>

void swap(int **pa, int **pb) {
	int *temp = *pa;
	*pa = &b;
	*pb = temp;
}

int main() {
	int a = 10;
	int b = 20;

	int *pa = &a;
	int *pb = &b;
	swap(&pa, &pb);
}
