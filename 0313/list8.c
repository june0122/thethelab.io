#include <stdio.h>
#include <stdlib.h>

struct user {
	char name[32];
	int age;
};

// void* 
struct node {
	void *data;
	struct node *prev;
	struct node *next;
};

struct node head = { 0, &head, &head };

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

#if 0
void add_next(struct node *s, struct node* new) {
	new->prev = s;
	new->next = s->next;
	s->next->prev = new;
	s->next = new;
}

void add_front(struct node *s, struct node* new) {
	new->prev = s->prev;
	new->next = s;
	s->prev->next = new;
	s->prev = new;
}
#endif

void print_list(struct node *head) {
	struct node *current = head->next;
	system("clear");

	printf("<head> ");
	while (current != head) {
		struct user *user = current->data;
		printf(" -> [%s(%d)]", user->name, user->age);
		current = current->next;
	}
	getchar();
}

struct user users[5] = {
	{ "Tom", 42 }, { "Bob", 30 }, { "Alice", 18 }, { "Steav", 24 }, { "John", 10 }
};

struct node data[5];
int main() {
	int i;
	for (i = 0; i < 5; ++i) {
		data[i].data = users + i;
		add_front(&head, data + i);
		print_list(&head);
	}
}































