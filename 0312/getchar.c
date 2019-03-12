// 아래코드는 a.out 같은 바이너리에서는 제대로 동작하지 않습니다.
#include <stdio.h>

// getchar() / getc() / fgetc()
//  : 반환타입이 int 인 이유는?
//   => 0xFF를 EOF로 인식하는 문제가 발생할 수 있다.

int main() {
	int c;
	int filesize = 0;

	// c: char
	//  0xFF == EOF 

	//  0x000000FF == EOF(0xFFFFFFFF)

	while ((c = getchar()) != EOF) {
		++filesize;
	}

	printf("filesize: %d\n", filesize);
}
