#include <stdio.h>
#include <stdlib.h> // malloc, free
#include <string.h> // strlen

struct user {
	// char name[32];
	char *name;
	int age;
};


int main() {
	struct user user = { 
		"Tom", 42 
	};

	user.name = malloc(strlen("Tom") + 1);
	strcpy(user.name, "Tom");

	user.name[0] = 'x';
	printf("%s %d\n", user.name, user.age);

	free(user.name);
}
