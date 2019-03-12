
#include <stdio.h>

// 구조체 정렬
//  : CPU가 구조체를 처리할 때, 최선의 성능을 낼 수 있도록 
//    각 필드를 배치하는 방법

// int(4): 정수형 타입의 메모리의 주소가 4의 배수
// double(8): 8의 배수
// char: 1의 배수(4의 배수)
// => 구조체의 필드 중에서 가장 큰 크기를 갖는 필드의 배수로 떨어지도록 한다.

// 구조체의 네트워크 교환용으로 사용할 때는,
// 1 바이트 단위로 패킹이 필요하다.
//   => 컴파일러 확장 명령

struct A {
	int a;
	double b;
	char c;
} __attribute__((packed));

struct B {
	char c;
	int a;
	double b;
} __attribute__((packed));

int main() {
	printf("%ld\n", sizeof(struct A));   // 
	printf("%ld\n", sizeof(struct B));   // 
}








