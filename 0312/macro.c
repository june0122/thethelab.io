#include <stdio.h>

// #: 전처리기
//  => 텍스트 처리를 C 언어 문법과 상관없이 할 수 있다.
//  => 코드를 생성하는 기술
//  => 매크로 함수

#define MUL(x, y) ((x) * (y))
#define POW(x) ((x) * (x))

int xpow(int x) {
	return x * x;
}

int mul(int a, int b) {
	return a * b;
}

int main() {
	// printf("add: %d\n", add(10, 32));
	// printf("ADD: %d\n", ADD(10, 32));
	int a = 10;
	int b = 32;

	printf("mul: %d\n", mul(a + b, a + b));
	printf("mul: %d\n", MUL(a + b, a + b));

	int n = 2;
	printf("pow: %d\n", xpow(++n));
	printf("pow: %d\n", POW(++n));
}









