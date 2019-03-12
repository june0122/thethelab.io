// fopen("a.txt", "r+")
//  - 파일이 존재하지 않으면, NULL을 반환한다.

// fopen("a.txt", "w+")
//  - 파일이 존재하지 않으면, 새로운 파일을 생성한다.
//  - 파일의 내용을 지운다. (TRUNCATE)

// 아래 개념은 Windows 에서만 사용한다.
// fopen("a.txt", "rt") - text
// fopen("a.txt", "rb") - binary

#include <stdio.h>

int main() {
	char word[32];
	FILE *fp = fopen("a.txt", "w"); // FILE 구조체(offset)
	FILE *fp2 = fopen("a.txt", "r");

	while (1) {
		int len = fprintf(fp, "hello\n");
		fflush(fp);
		getchar();
		// fseek(fp, -len, SEEK_CUR);
		fscanf(fp2, "%s", word);
		printf("%s\n", word);
		getchar();
	}

}

