#include<stdio.h>
#include<stdlib.h>

typedef struct Node {

	int data;
	struct Node* next;
}; Node;
int createNode() {

	Node* newNode = (Node*)malloc(sizeof(Node));
	int num;
	printf("�����Է�:");
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

	//Node* searcher; //���� ������
	//searcher = &a;

	//while (searcher != NULL) {
	//	printf("%d->", searcher->data);
	//	searcher = searcher->next;

	Node* head; //��尡 ��ŸƮ ����Ʈ

	//head=(Node*)malloc(sizeof(Node)) //�����Ҵ�

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

