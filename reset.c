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
    scanf_s("%d", &num);

    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

void appendNode(Node** head) {
    Node* newNode = createNode();
    if (*head == NULL) {
        *head = newNode;
    }
    else {
        Node* searcher = *head;
        while (searcher->next != NULL) {
            searcher = searcher->next;
        }
        searcher->next = newNode;
    }
}

void deleteLastNode(Node** head) {
    if (*head == NULL) {
        printf("������ ���� �����\n");
        return;
    }
    else {
        Node* searcher = *head;
        Node* temp = NULL;
        int deleteTarget = 0; // �ʱ�ȭ
        while (searcher->next != NULL) {
            temp = searcher;
            deleteTarget = searcher->data;
            searcher = searcher->next;
        }
        printf("%d�� �����Ǿ����ϴ�\n", deleteTarget);
        free(searcher);
        if (temp != NULL) {
            temp->next = NULL;
        }
        else {
            *head = NULL;
        }
    }
}

int main() {
    Node* head = NULL;

    while (1) {
        int code;
        printf("1. ��� �߰� 2. ���� ��� ���� 3. ����\n");
        printf("��ȣ �Է�: ");
        scanf_s("%d", &code);
        if (code == 1)
            appendNode(&head);
        else if (code == 2)
            deleteLastNode(&head);
        else if (code == 3)
            break;
        else
            printf("�߸� �Է��߽��ϴ�.\n");
    }

    // ��� Ž�� �� ���
    Node* searcher = head;
    while (searcher != NULL) {
        printf("%d->", searcher->data);
        searcher = searcher->next;
    }
    printf("\n");

    // �޸� ����
    searcher = head;
    while (searcher != NULL) {
        Node* temp = searcher;
        searcher = searcher->next;
        free(temp);
    }

    return 0;
}

    //Node* second;
    //Node* third;
    //Node* fourth;


    //// ù ��° ��� ����
    //head = createNode();

    //// �� ��° ��� ����
    //second = createNode();

    //// �� ��° ��� ����
    //third = createNode();

    ////�� ��° ��� ����
    //fourth = createNode();

    //// ù ��° ����� ���� ���� �� ��° ��带 ����,�ι�° ����°�� ��������
    //head->next = second;
    //second->next = third;
    //third->next = fourth;


 
    