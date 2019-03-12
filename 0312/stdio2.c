#include <stdio.h>
// fflush(stdin);
//  : 표준이 아닙니다.
//    stdin에 대해서는 fflush를 사용할 수 없습니다.

int main() {
	int a;
	char c;

	scanf("%d", &a);
	scanf(" %c", &c);

	printf("a: %d, c: %c\n", a, c);
}
