#include<stdio.h>
#include<stdlib.h>

typedef struct Node {

	int data;
	struct Node* next;
}; Node;
int createNode() {

	Node* newNode = (Node*)malloc(sizeof(Node));
	int num;
	printf("정수입력:");
	scanf("%d", &num);
	newNode->data = num;
	newNode->next = NULL;
	return newNode;
}

int main() {
	//Node a,b,c;

	//a.data = 10;
	//a.next = &b;
	//b.data = 20;
	//b.next = &c;
	//c.data = 30;
	//c.next = NULL;

	//Node* searcher; //써쳐 포인터
	//searcher = &a;

	//while (searcher != NULL) {
	//	printf("%d->", searcher->data);
	//	searcher = searcher->next;

	Node* head; //헤드가 스타트 포인트

	//head=(Node*)malloc(sizeof(Node)) //동적할당

	Node* second;
	head = createNode();
	second = createNode();
	head->next = second;

	Node* searcher;
	searcher = head;
	while(searcher!=NULL){
		printf("%d->", searcher->data);
		searcher = searcher->next;
}

	







	return 0;
}

