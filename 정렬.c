#include <stdio.h>

int main() {
    int numbers[5]; // �Է¹��� �ټ� ���� ���ڸ� ������ �迭���� �����ϱ�
    int temp;       // Swap �ÿ� ����� �ӽ� ����

    // ���� �Է� �ޱ�
    printf("�������� �� ���ڵ��� �Է����ּ���: ");
    scanf("%d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]);

    // ���� ����
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5 - i - 1; j++) { //5���� i�� ���� �Ǵ� ����:�װ� ���ܽ�Ű�� ���ؼ�
            if (numbers[j] > numbers[j + 1]) {
                // �� ���ڸ� ��ȯ
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // ���ĵ� ���� ���
    printf("���ĵ� ���ڵ�: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
