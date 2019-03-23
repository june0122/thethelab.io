#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 512  // buf 크기 지정
#define ROW 400
#define list_entry(ptr, type, member) \
	(type*)((char*)ptr - (unsigned long)&(((type*)0)->member))

typedef enum kind {
	CELL_DX = 1 << 0,     
	SPORTS_CAR = 1 << 1, 
	SUV = 1 << 2,       
	WAGON = 1 << 3,    
	MINIVAN = 1 << 4,
	PICKUP = 1 << 5,
	AWD = 1 << 6,
	RWD = 1 << 7,
} kind;

kind types[8] = {
	CELL_DX,
	SPORTS_CAR,
	SUV,
	WAGON,
	MINIVAN,
	PICKUP,
	AWD,
	RWD	
};

struct node {
	struct node *prev;
	struct node *next;
};

struct node head = { &head, &head };

typedef struct car {
	char *name;
	unsigned char kind;
	int retail_price;
	int dealer_cost;
	double engine_size;
	int weight;
	int width;
	struct node links;
} CAR;

void __add_node(struct node *prev, struct node* next, struct node* new) {
	new->next = next;  
	new->prev = prev;
	prev->next = new;
	next->prev = new;
}

void add_next(struct node *s, struct node* new) {
	__add_node(s, s->next, new);
}

void add_front(struct node *s, struct node* new) {
	__add_node(s->prev, s, new); 
}

CAR* setCar(char *buf) {
	char *pToken;
	int i;
	CAR *car;


	car = (CAR*)malloc(sizeof(CAR));

	for(i = 0, pToken = strtok(buf, ","); pToken != NULL; pToken = strtok(NULL, ","), i++ ) {
		switch(i) {
			case 0 :
				car->name = strdup(pToken);
				// printf("%s\n", car->name);
				break;
			case 1 : case 2 : case 3 : case 4 : case 5 : case 6 : case 7 : case 8 :  // fall-through 방식
				if(atoi(pToken) == 1)
					car->kind |= types[i - 1];
				break;
			case 9 :
				car->retail_price = atoi(pToken);
				break;
			case 10 :
				car->dealer_cost = atoi(pToken);
				break;
			case 11 :
				car->engine_size = atof(pToken);  // double 타입은 atof 함수를 이용해 변환
				break;
			case 12 :
				car->weight = atoi(pToken);
				break;
			case 13 :
				car->width = atoi(pToken);
				break;
		}
	}
	return car;
}

void setKind(CAR *car, char** kind1, char** kind2) {
	int i;

	// kind 1 : CellDx, Sports Car, SUV ...
	if (car->kind & types[0]) 
		*kind1 = strdup("CellDx");
	else if (car->kind & types[1])
		*kind1 = strdup("Sports Car");
	else if (car->kind & types[2])
		*kind1 = strdup("SUV");
	else if (car->kind & types[3])
		*kind1 = strdup("Wagon");
	else if (car->kind & types[4])
		*kind1 = strdup("Minivan");
	else if (car->kind & types[5])
		*kind1 = strdup("Pickup");

	// kind 2 : AWD, RWD
	if (car->kind & types[6])
		*kind2 = strdup("AWD");
	else if(car->kind & types[7])
		*kind2 = strdup("RWD");
	else
		*kind2 = strdup("NONE");
}

void print_list(struct node *head) {
	struct node *current = head->next;
	char *kind1, *kind2;
	//	system("clear");

	// printf("<head> ");
	while (current != head) {
		CAR *car = list_entry(current, CAR, links);

		setKind(car, &kind1, &kind2);

		//	printf(" -> [%s %s %s] \n", car->name, kind1, kind2);

		current = current->next;
	}

	free(kind1);
	free(kind2);

	//getchar();
}

void print_car(CAR *car, FILE * snapshot) {
	char *kind1, *kind2;
	setKind(car, &kind1, &kind2);

	if(snapshot == NULL) {
		printf("%-50s %-15s %-10s %-10d %-10d %-10.2g %-10d %-10d \n",
				car->name,
				kind1,
				kind2,
				car->retail_price,
				car->dealer_cost,
				car->engine_size,
				car->weight,
				car->width
				);
	} else {
		fprintf(snapshot, "%-50s %-15s %-10s %-10d %-10d %-10.2g %-10d %-10d \n",
				car->name,
				kind1,
				kind2,
				car->retail_price,
				car->dealer_cost,
				car->engine_size,
				car->weight,
				car->width
				);
	}
	free(kind1);  // setKind에서 strdup 함수를 통한 malloc 제거
	free(kind2);
}

int compare_info;

// 오름차순
int ascending_sort(const void *a, const void *b) {  // 198번째 줄 주소값 받아옴
	switch(compare_info) {
		case 1 :
			return (*(CAR**)a)->retail_price - (*(CAR**)b)->retail_price;
		case 2 :
			return (*(CAR**)a)->dealer_cost  - (*(CAR**)b)->dealer_cost;
		case 3 :
			return (*(CAR**)a)->engine_size - (*(CAR**)b)->engine_size;
		case 4 :
			return (*(CAR**)a)->weight - (*(CAR**)b)->weight;
		case 5 :
			return (*(CAR**)a)->width - (*(CAR**)b)->width;
	}
}

// 내림차순
int descending_sort(const void *a, const void *b) {
	switch(compare_info) {
		case 1 :
			return (*(CAR**)b)->retail_price - (*(CAR**)a)->retail_price;
		case 2 :
			return (*(CAR**)b)->dealer_cost  - (*(CAR**)a)->dealer_cost;
		case 3 :
			return (*(CAR**)b)->engine_size - (*(CAR**)a)->engine_size;
		case 4 :
			return (*(CAR**)b)->weight - (*(CAR**)a)->weight;
		case 5 :
			return (*(CAR**)b)->width - (*(CAR**)a)->width;
	}
}

int filter(CAR **car, struct node *head, int sel_type, int sel_info, int sel_sort) { 
	struct node *current = head->next;
	int i, num = 0;

	while(current != head) {
		CAR *filted_car = list_entry(current, CAR, links);

		if(filted_car->kind & types[sel_type]){ 
			car[num++] = filted_car;
			// printf("%s\n", car[i-1]->name); 
		}
		current = current->next;
	}

	compare_info = sel_info;

	if (sel_sort == 1)
		qsort(car, num, sizeof(car[0]), ascending_sort);
	else if (sel_sort == 2)
		qsort(car, num, sizeof(car[0]), descending_sort);
	else {
		printf("입력 오류입니다.\n");
		printf("다시 선택해주세요.\n\n");
	}
	for(i = 0; i < num; i++) 
		print_car(car[i], NULL);  // 파일을 생성하는 과정이 아니므로 NULL을 인자로 전달

	return num;
}

int main(void){
	FILE * fp = fopen("car_data.csv", "r");  // 데이터를 불러 올 파일
	FILE * snapshot;  // 정렬한 데이터를 저장할 파일
	char buf[MAX];
	char file_name[20];
	int i = 0;
	int num, status, sel_menu, sel_type, sel_info, sel_sort, sel_save;
	CAR *car;
	CAR *cars[MAX];

	if(fp == NULL) {
		fprintf(stderr,"파일 로드에 실패하였습니다");
		return 1;
	}

	while(fgets(buf, MAX, fp) != NULL) {
		if (i++ == 0)  // 첫 번째 라인을 출력하지 않고 넘어간다.
			continue;

		int len = strlen(buf);  // fgets 함수는 끝에 개행이 생기므로 개행을 없애주는 코드를 작성
		if(buf[len-1] == '\n')  // 배열의 마지막 요소가 개행이면
			buf[len-1] = '\0';  // 제거해준다.

		car = setCar(buf);

		if(car == NULL)
			continue;

		add_front(&head, &car->links); 
	}

	printf("총 %d개의 데이터가 로드되었습니다.\n", i - 1);  // i-1은 데이터의 갯수


	while(1) {
		printf("1. 검색\n");
		printf("2. 종료\n");
		printf("선택> ");
		scanf("%d", &sel_menu);

		switch(sel_menu) {
			case 1 :
				printf("\n\n1. CellDx\n");
				printf("2. Sports Car\n");
				printf("3. SUV\n");
				printf("4. Wagon\n");
				printf("5. AWD\n");
				printf("6. RWD\n");
				printf("선택> ");
				scanf("%d", &sel_type);

				printf("\n\n1. Retail Price\n");
				printf("2. Dealer Cost\n");
				printf("3. Engine Size\n");
				printf("4. Weight\n");
				printf("5. Width\n");
				printf("선택> ");
				scanf("%d", &sel_info);

				printf("\n\n1. 오름차순 정렬\n");
				printf("2. 내림차순 정렬\n");
				printf("선택> ");
				scanf("%d", &sel_sort);

				//	print_list(&head);
				num = filter(cars, &head, sel_type, sel_info, sel_sort);

				printf("\n\n파일로 저장하시겠습니까?\n");
				printf("1. 예\n");
				printf("2. 아니오\n");
				printf("선택> ");
				scanf("%d", &sel_save);

				if(sel_save == 1) {
					printf("파일이름> ");
					scanf("%s", file_name);

					snapshot = fopen(file_name, "w");
					for(i = 0; i < num; i++)
						print_car(cars[i], snapshot);
					fclose(snapshot);
					printf("%s 에 저장되었습니다.\n\n", file_name);
					break;
				} 
				break;

			case 2 :
				status = 1;
				break;
		}
		if(status == 1)
			break;
	}

	fclose(fp);
	system("clear");
	return 0;
}
