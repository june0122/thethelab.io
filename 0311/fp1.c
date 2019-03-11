
#include <stdio.h>

// 함수 포인터
//  : 함수를 가르키는 포인터

// 함수의 타입
//  : 함수의 시그니쳐에 의해서 결정된다.
//    함수의 인자의 개수와 인자의 타입과 반환 타입으로 결정된다.

// 함수 포인터?
//   변수: 런타임에 변경되는 값.
//     -> 실행 시간에 어떤 함수를 호출할지 결정하고 싶다.


// add: int(int a, int b)
int add(int a, int b) {
	return a + b;
}

// sub: int(int a, int b)
int sub(int a, int b) {
	return a - b;
}

// int (*p)(int a, int b)
int main() {
	int (*p)(int, int);

	// 함수의 이름은 함수 포인터로 해석된다.
	//   add => &add
	//   sub => &sub

	// 1 번 방법
	p = &add;
	printf("%d\n", (*p)(10, 20));

	// 2 번 방법
	p = sub;
	printf("%d\n", p(30, 20));
}












