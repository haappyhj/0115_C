#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("메모리 할당 오류\n");
        exit(EXIT_FAILURE);
    }

    int num;
    printf("정수 입력: ");
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
        printf("삭제할 것이 없어요\n");
        return;
    }
    else {
        Node* searcher = *head;
        Node* temp = NULL;
        int deleteTarget = 0; // 초기화
        while (searcher->next != NULL) {
            temp = searcher;
            deleteTarget = searcher->data;
            searcher = searcher->next;
        }
        printf("%d는 삭제되었습니다\n", deleteTarget);
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
        printf("1. 노드 추가 2. 끝의 노드 삭제 3. 종료\n");
        printf("번호 입력: ");
        scanf_s("%d", &code);
        if (code == 1)
            appendNode(&head);
        else if (code == 2)
            deleteLastNode(&head);
        else if (code == 3)
            break;
        else
            printf("잘못 입력했습니다.\n");
    }

    // 노드 탐색 및 출력
    Node* searcher = head;
    while (searcher != NULL) {
        printf("%d->", searcher->data);
        searcher = searcher->next;
    }
    printf("\n");

    // 메모리 해제
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


    //// 첫 번째 노드 생성
    //head = createNode();

    //// 두 번째 노드 생성
    //second = createNode();

    //// 세 번째 노드 생성
    //third = createNode();

    ////네 번째 노드 생성
    //fourth = createNode();

    //// 첫 번째 노드의 다음 노드로 두 번째 노드를 지정,두번째 세번째도 마찬가지
    //head->next = second;
    //second->next = third;
    //third->next = fourth;


 
    