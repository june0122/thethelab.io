#include <stdio.h>
#include <stdlib.h>

// GCC는 void*에 대한 연산을 char*로 취급해준다.
// => 1 바이트 연산을 지원한다.
//    +/- 연산에 대해서만 지원한다.

void swap(char *a , char *b, size_t size) {
	char *temp = malloc(size);
	int i;

	for (i = 0; i < size; ++i) {
		temp[i] = a[i];
		a[i] = b[i];
		b[i] = temp[i];
	}

	free(temp);
}	

// 모든 배열 타입에서 대해서, 정렬할 수 있어야 한다.
// => void*
// qsort
#if 0
void qsort(void *base, size_t nmemb, size_t size,
		int (*compar)(const void *, const void *));

#endif

// arr[i]
//  *(arr + i)
//   void*: offset 정보가 없다.
//    arr + size * i

void bsort(void *arr, size_t n, size_t size, 
	int (*compare)(const void *, const void *)) {

	int i, j;
	for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j < n; ++j) {
			if (compare(arr + i * size, arr + j * size) > 0) {
				swap(arr + i * size, arr + j * size, size);
			}
		}
	}
}

int compare1(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}	

int main() {
	int i;
	int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	qsort(arr, 10, sizeof(arr[0]), compare1);

	for (i = 0; i < 10; ++i) {
		printf("%d\n", arr[i]);
	}
}





