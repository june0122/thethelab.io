#include <stdio.h>
#include <math.h>

// a.c -> a.o
// b.c -> b.o => a.out
//          Linking

// 일반적으로 gcc 컴파일 할때, C 언어 표준 라이브러리에 대한
// 암묵적인 링킹이 수행된다.
//  => printf, scanf ...

// math 라이브러리는 암묵적인 링킹이 수행되지 않는다.
//  => 명시적인 링킹을 수행해야 한다.

// 라이브러리
// 1) 정적 라이브러리
//    Linux: .a
//    Windows: .lib
//  : 실행 파일안에 함수의 구현이 포함된다.
//  => 추가적인 로드가 필요없다.
//     실행 파일의 크기가 커진다.
//     : 라이브러리가 변경되면, 컴파일을 다시 해야 한다.
//     : 배포가 쉽다.
//   $ ar rcv libadd.a add.o ...
//   $ gcc main.o -ladd -L.

// 2) 동적 라이브러리
//     Linux: .so(shared object)
//     Windows: .dll(dynamic loading library)
//  : 실행 중에 필요한 라이브러리를 동적으로 메모리에 로드해서 사용한다.
//    => 실행 파일안에 함수의 구현이 존재하지 않는다.
//       실행 파일의 크기가 크지 않다.
//       추가적인 로드가 필요하다.
//     : 라이브러리가 변경되어도 다시 컴파일 할 필요가 없다.
//    $ gcc add.o -shared -fpic -o libadd.so
//    $ LD_LIBRARY_PATH=. ./a.out

// 실행 중에 동적라이브러리를 로드할 수 있다.


int main() {
	double a;
	scanf("%lf", &a);

	printf("%lf\n", sqrt(a));
}










