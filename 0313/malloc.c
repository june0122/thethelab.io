// Storage Class(기억 부류)
// 1. data => 실행 파일의 용량이 커진다. 
//   전역 변수
//   내부 정적 변수
//   => 프로그램 종료 때까지 유효한 영역
// 2. stack
//   지역 변수
//   => 함수가 시작할 때 생성되고,
//      함수가 종료할 때 유효하지 않음.
//   => 메모리 할당과 해지의 비용이 0 이다.

// 3. heap
//   => 개발자가 원하는 시점에 생성하고,
//      파괴할 수 있다.
//     malloc / free
//    Java: new
//   => 할당과 해지의 비용이 크다.

#include <stdio.h>
#include <stdlib.h>

// int arr[10000] = { 1, };
void foo() {
	int arr[100];
}

// C 언어는 void*를 다른 타입으로 암묵적인 변환을 허용한다.

int main() {
		int *p = malloc(sizeof(int) * 4);
		p = calloc(4, sizeof(int));
		// int *p = (int *)malloc(sizeof(int));  // C++ 고려!
}























