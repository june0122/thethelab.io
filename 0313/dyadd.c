
#include <stdio.h>
#include <dlfcn.h>

// libadd.so 
//   위의 파일 안에서 add 함수를 찾아서 호출하는 기법.


int main() {
	void *addr = dlopen("./libadd.so", RTLD_LAZY);
	if (addr == NULL) {
		return 1;
	}

	int (*p)(int, int) = dlsym(addr, "add");

	printf("%d\n", p(10, 20));



}
