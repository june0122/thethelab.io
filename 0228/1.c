// - 자바의 char 타입은 2바이트 이다.
//  => 유니코드(UTF-16)를 지원하고 있기 때문에

// Ascii code => Code Page
// 'A' -> 65  
// 'a' -> 97
// '0' -> 48

// 유니코드(인코딩 방식)
// => UTF-8.ko_KR


// 주의사항: 타입의 크기는 플랫폼에 따라 다르다.
//           각각의 타입이 표현할 수 있는 범위에 대해서 기억을 할 것.
//   64bit
// 타입
// Built in Type  <-> User Defined Type
//                       struct, enum, union
// - 정수 타입
//  char    =>  1
//  short   =>  2
//  int     =>  4
//  long    =>  Linux(8) / Windows(4)
//  long long => 8

// - 부동 소수점 타입
//    => 오차가 있는 타입이다.
//       특정한 값을 정확하게 표현할 수 없다.
//    => 절대 ==, != 를 사용하면 안된다.
//       두 값의 차의 절대값이 특정 범위에 들어오는지 확인한다.

//  float   => 4
//  double  => 8
//  long double => 16

//  void

#include <stdio.h>
#include <string.h>

int main() {
	const char* s = "바보";

	printf("%ld\n", strlen(s));

	// int c = 65;
	// printf("%c", c);
}
