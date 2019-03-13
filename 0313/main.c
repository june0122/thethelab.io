#include <stdio.h>

// 헤더 파일을 만들 때 주의할 점.
// => 중복 포함을 방지해야 한다.
#include "add.h"

// int add(int a, int b);
// 라이브러리의 설계자는 반드시 제공하는 모든 함수에 대한 선언을 제공해야한다.
// => 헤더파일

int main() {
	int n = add(10, 20);
	printf("%d\n", n);
}
