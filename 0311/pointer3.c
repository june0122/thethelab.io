#include <stdio.h>

// C 언어는 배열을 다루는 방법이, 일반 타입과 조금 다르다.
//  * 

// void foo(int arr[3]) {
// 제약: 배열은 배열의 첫번째 원소의 시작 주소로 전달하기 때문에,
//      함수에서 배열의 크기를 알 수 없다.
//     => 배열을 전달하는 함수를 설계할 때, 배열의 길이를 추가적으로
//        전달해야 한다.
void foo(int *arr) {
	int i;
	for (i = 0; i < 3; ++i) {
		arr[i] += 10;
	}

	printf("sizeof(arr): %ld\n", sizeof(arr));
}

// C 언어에서 타입을 보는 방법
//  int i;
//  => 이름을 뺀 나머지가 타입이다.
//  => int
//  int arr[3]
//  => int[3]
//  => 배열의 이름은 배열의 첫번째 원소의 시작 주소로 해석된다.
//   : Decay

//  => Decay 예외
//   1) sizeof 연산
//   2) & 연산

int main() {
	int i;
	int arr[3] = { 1, 2, 3 };

	printf("sizeof(arr): %ld\n", sizeof(arr));

	foo(arr);
	// foo(&arr[0])

	for (i = 0; i < 3; ++i) {
		printf("%d\n", arr[i]);   
	}
}
