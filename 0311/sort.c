
#include <stdio.h>

void swap(int *a , int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}	


// bsort / bsort2 는 전체적인 알고리즘은 동일한데, 정책만 다르다.
//  => 오름차순 / 내림차순의 정책은 사용자에 의해 변경된다.
//  => 변하지 않는 전체 알고리즘에서 변해야 하는 정책만 분리해야 한다.
void bsort(int *arr, int n, int (*compare)(int, int)) {
	int i, j;
	for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j < n; ++j) {
			// if (arr[i] > arr[j]) {
			if (compare(arr[i], arr[j]) > 0) {
				// swap(&arr[i], &arr[j]);
				// swap(&*(arr + i), &*(arr + j));
				swap(arr + i, arr + j);
			}
		}
	}
}
#if 0
void bsort(int *arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j < n; ++j) {
			if (arr[i] > arr[j]) {
				// swap(&arr[i], &arr[j]);
				// swap(&*(arr + i), &*(arr + j));
				swap(arr + i, arr + j);
			}
		}
	}
}

void bsort2(int *arr, int n) {
	int i, j;
	for (i = 0; i < n - 1; ++i) {
		for (j = i + 1; j < n; ++j) {
			if (arr[i] < arr[j]) {
				swap(arr + i, arr + j);
			}
		}
	}
}
#endif

int compare1(int a, int b) {
	return a - b;
}	

int compare2(int a, int b) {
	return b - a;
}	


int main() {
	int i;
	int arr[10] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };
	bsort(arr, 10, compare2);

	for (i = 0; i < 10; ++i) {
		printf("%d\n", arr[i]);
	}
}





