
#include <stdio.h>
// ftell은 파일의 크기를 구하는 목적으로 사용할 수 있다.
// $ ./a.out <filename>
int main(int argc, char *argv[]) {
	FILE *fp;
	if (argc != 2) {
		fprintf(stderr, "Usage: ./a.out <filename>\n");
		return -1;
	}

	fp = fopen(argv[1], "r");
	if (fp == NULL) {
		fprintf(stderr, "File open error...\n");
		return -1;
	}

	fseek(fp, 0, SEEK_END);
	printf("filesize: %ld\n", ftell(fp));

	fclose(fp);

}
