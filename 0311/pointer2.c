#include <stdio.h>

// 포인터는 주소를 담을 수 있는 타입
//  int    -> int*
//  char   -> char*
//  double -> double*

// Call by reference
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int a = 10;
	int b = 20;
	
	swap(&a, &b);

	printf("swap: %d %d\n", a, b);
	return 0;
}
