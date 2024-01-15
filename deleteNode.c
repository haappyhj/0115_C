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
    scanf("%d", &num);

    newNode->data = num;
    newNode->next = NULL;

    return newNode;
}

Node* deleteLastNode(Node** head) {
    if (*head == NULL) {
        printf("리스트가 비어있습니다.\n");
        return NULL;
    }

    Node* lastNode = *head;
    Node* prevNode = NULL;

    // 마지막 노드까지 이동
    while (lastNode->next != NULL) {
        prevNode = lastNode;
        lastNode = lastNode->next;
    }

    // 이전 노드의 다음을 NULL로 설정하여 마지막 노드를 삭제
    if (prevNode != NULL) {
        prevNode->next = NULL;
    }
    else {
        // 삭제된 노드가 헤드일 경우, 헤드를 두 번째 노드로 갱신
        *head = NULL;
    }

    // 삭제된 노드의 데이터 값을 반환
    int deletedData = lastNode->data;
    free(lastNode);

    return deletedData;
}

int main() {
    Node* head = NULL;
    Node* second = NULL;

    // 첫 번째 노드 생성
    head = createNode();

    // 두 번째 노드 생성
    second = createNode();

    // 첫 번째 노드의 다음 노드로 두 번째 노드를 지정
    head->next = second;

    // 노드 탐색 및 출력
    Node* searcher = head;
    while (searcher != NULL) {
        printf("%d->", searcher->data);
        searcher = searcher->next;
    }
    printf("\n");

    // 맨 끝의 노드 삭제
    int deletedData = deleteLastNode(&head);
    printf("맨 끝의 노드 삭제, 삭제된 데이터: %d\n", deletedData);

    // 수정된 리스트 출력
    searcher = head;
    while (searcher != NULL) {
        printf("%d->", searcher->data);
        searcher = searcher->next;
    }
    printf("\n");

    // 메모리 해제
    free(second); // head가 이미 해제되었음

    return 0;
}
