
#include <stdio.h>

// Type
//  1. built-in type
//  2. user define type
//     enum, struct, union

// 전처리 문법은 컴파일 이전에 코드를 변환하므로,
// 문제가 발생하였을 때, 찾기 어렵다.
#if 0
#define HELLO 10
#define WORLD 20
#endif

enum MyEnum {
	HELLO = 10,
	WORLD,
};

int main() {
	// int a = HELLO;        // - X
	enum MyEnum a = HELLO;   // - O
	// a = 30;
}











