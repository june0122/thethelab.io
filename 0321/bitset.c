// bitset
#include <stdio.h>

#if 0
#define SWORD  0
#define DAGGER 1
#define SHIELD 2
#define SPEAR  3
#define AXE    4
#define GUN    5
#define STAFF  6
#define WAND   7
#define MAX_ITEM_COUNT 8
#endif
enum {
	SWORD,
	DAGGER,
	SHIELD,
	SPEAR,
	AXE,
	GUN,
	STAFF,
	WAND,
	MAX_ITEM_COUNT,
};

struct user {
	char items[MAX_ITEM_COUNT];  // 8
};

int main() {
	struct user user = { 0, };
	printf("%ld\n", sizeof(user));

	user.items[SWORD] = 1;
	user.items[GUN] = 0;

	if (user.items[SWORD]) {
		printf("검이 있다..\n");
	} else {
		printf("검이 없다..\n");
	}

	if (user.items[GUN]) {
		printf("총이 있다..\n");
	} else {
		printf("총이 없다..\n");
	}
}








