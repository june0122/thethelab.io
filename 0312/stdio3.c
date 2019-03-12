
// EOF 를 통해서 입출력 처리를 해야 한다.
// ^D: EOF를 키보드를 통해 입력할 수 있다.
#include <stdio.h>

// <: 파일의 내용을 키보드로 리다이렉션해준다.
// >: 프로세스의 출력을 파일로 리다이렉션해준다.

// 100mb - File
//  1. 모든 파일의 내용을 읽어서, 변환하고 다시 저장한다.
//  2. 파일을 처음부터 읽어서 변환한 내용을 파일에 저장한다. - Stream


int main() {
	char name[32];
	int age;

	while (scanf("%s %d", name, &age) != EOF) {
		printf("%s %d\n", name, age);
		fprintf(stderr, "shit...\n");
	}
}
