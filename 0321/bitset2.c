// bitset
#include <stdio.h>

// 0010 0001
enum {
	SWORD = 1 << 0,
	DAGGER = 1 << 1,
	SHIELD = 1 << 2,
	SPEAR = 1 << 3,
	AXE = 1 << 4,
	GUN = 1 << 5,
	STAFF = 1 << 6,
	WAND = 1 << 7,
};

struct user {
	unsigned char items;
};

#define ADD_ITEM(items, item) \
	items |= item

#define REMOVE_ITEM(items, item) \
	items &= ~item

#define HAS_ITEM(items, item) \
	items & item

int main() {
	struct user user;
	printf("%ld\n", sizeof(user));

	ADD_ITEM(user.items, SWORD);
	ADD_ITEM(user.items, GUN);

	if (HAS_ITEM(user.items, SWORD)) {
		printf("검이 있다.\n");
	} else {
		printf("검이 없다.\n");
	}

	REMOVE_ITEM(user.items, SWORD);
	if (HAS_ITEM(user.items, SWORD)) {
		printf("검이 있다.\n");
	} else {
		printf("검이 없다.\n");
	}
}

#if 0
int main() {
	struct user user;
	printf("%ld\n", sizeof(user));

	// user.items[SWORD] = 1;
	user.items |= SWORD; 
	user.items |= GUN;

	if (user.items & SWORD) {
		printf("검이 있다.\n");
	} else {
		printf("검이 없다.\n");
	}

	user.items &= ~SWORD;
	if (user.items & SWORD) {
		printf("검이 있다.\n");
	} else {
		printf("검이 없다.\n");
	}

	if (user.items & GUN) {
		printf("GUN이 있다.\n");
	} else {
		printf("GUN이 없다.\n");
	}
}
#endif
