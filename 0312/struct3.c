#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // strlen

// const struct user * const p;
//  const *: 포인터가 가르키는 대상체를 변경할 수 없다.
//  * const: 포인터 변수가 다른 대상체를 가르킬 수 없다.

struct user {
	char name[32];
	int age;
};

// 아래 코드의 문제점
//  => Call by value
//   : 구조체의 크기가 크면, 함수의 인자를 복사하는데 시간이 걸린다.
#if 0
void print_user(struct user user) {
	printf("%s %d\n", user.name, user.age);
}
#endif

// 포인터를 인자로 전달할 때, 수정되지 않아야 한다.
// => const
void print_user(const struct user *user) {
	// struct user *p = (struct user*)user; // X
	// printf("%s %d\n", (*user).name, (*user).age);
	printf("%s %d\n", user->name, user->age);
	// ++user->age;
}

int main() {
	struct user user = { 
		"Tom", 42 
	};

	// printf("%s %d\n", user.name, user.age);
	print_user(&user);
}





