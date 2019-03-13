#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node *prev;
	struct node *next;
};

struct user {
	char name[32];
	int age;

	struct node links;
};

#define list_entry(ptr, type, member) \
		(type*)((char*)ptr - (unsigned long)&(((type*)0)->member))

struct node head = { &head, &head };

void __add_node(struct node *prev, struct node* next, struct node* new) {
	new->next = next;
	new->prev = prev;
	prev->next = new;
	next->prev = new;
}

// s, s->next, new
void add_next(struct node *s, struct node* new) {
	__add_node(s, s->next, new);
}

// s->prev, s, new
void add_front(struct node *s, struct node* new) {
	__add_node(s->prev, s, new);
}

void print_list(struct node *head) {
	struct node *current = head->next;
	system("clear");

	printf("<head> ");
	while (current != head) {
		struct user *user = list_entry(current, struct user, links);
	
		printf(" -> [%s(%d)]", user->name, user->age);
		current = current->next;
	}
	getchar();
}

// 데이터와 노드가 별도로 존재하므로, 관리하기 어렵다.
struct user users[5] = {
	{ "Tom", 42 }, { "Bob", 30 }, { "Alice", 18 }, { "Steav", 24 }, { "John", 10 }
};

int main() {
	int i;
	for (i = 0; i < 5; ++i) {
		add_front(&head, &users[i].links);
		print_list(&head);
	}
}































