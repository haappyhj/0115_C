#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("�޸� �Ҵ� ����\n");
        exit(EXIT_FAILURE);
    }

    int num;
    printf("���� �Է�: ");
    scanf("%d", &num);

    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

Node* deleteLastNode(Node** head) {
    if (*head == NULL) {
        printf("����Ʈ�� ����ֽ��ϴ�.\n");
        return NULL;
    }

    Node* lastNode = *head;
    Node* prevNode = NULL;

    // ������ ������ �̵�
    while (lastNode->next != NULL) {
        prevNode = lastNode;
        lastNode = lastNode->next;
    }

    // ���� ����� ������ NULL�� �����Ͽ� ������ ��带 ����
    if (prevNode != NULL) {
        prevNode->next = NULL;
    }
    else {
        // ������ ��尡 ����� ���, ��带 �� ��° ���� ����
        *head = NULL;
    }

    // ������ ����� ������ ���� ��ȯ
    int deletedData = lastNode->data;
    free(lastNode);

    return deletedData;
}

int main() {
    Node* head = NULL;
    Node* second = NULL;

    // ù ��° ��� ����
    head = createNode();

    // �� ��° ��� ����
    second = createNode();

    // ù ��° ����� ���� ���� �� ��° ��带 ����
    head->next = second;

    // ��� Ž�� �� ���
    Node* searcher = head;
    while (searcher != NULL) {
        printf("%d->", searcher->data);
        searcher = searcher->next;
    }
    printf("\n");

    // �� ���� ��� ����
    int deletedData = deleteLastNode(&head);
    printf("�� ���� ��� ����, ������ ������: %d\n", deletedData);

    // ������ ����Ʈ ���
    searcher = head;
    while (searcher != NULL) {
        printf("%d->", searcher->data);
        searcher = searcher->next;
    }
    printf("\n");

    // �޸� ����
    free(second); // head�� �̹� �����Ǿ���

    return 0;
}
