#include <stdio.h>

struct node {
	struct node *prev;
	struct node *next;
};

struct user {
	char name[32];
	struct node links;
	int age;
};

// struct user* p;
#if 0
p->age = *(31)
000     -------
         name
 31     -------
         age
 35     -------
         links

#endif

#define list_entry(ptr, type, member) \
		(type*)((char*)ptr - (unsigned long)&(((type*)0)->member))


int main() {
	struct user user = { .name="Tom", .age=42 };
	struct node *current = &user.links;

	// current을 통해 user의 시작 주소를 얻어낼 수 있어야 한다.
	struct user *p = list_entry(current, struct user, links);
#if 0
	struct user *p =
		(struct user*)((char*)current - (unsigned long)&(((struct user*)0)->links));
#endif
	printf("%s %d\n", p->name, p->age);
}













