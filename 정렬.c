#include <stdio.h>

int main() {
    int numbers[5]; // 입력받을 다섯 개의 숫자를 저장할 배열부터 선언하기
    int temp;       // Swap 시에 사용할 임시 변수

    // 숫자 입력 받기
    printf("버블정렬 할 숫자들을 입력해주세요: ");
    scanf("%d %d %d %d %d", &numbers[0], &numbers[1], &numbers[2], &numbers[3], &numbers[4]);

    // 버블 정렬
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5 - i - 1; j++) { //5에서 i를 빼야 되는 이유:그걸 제외시키기 위해서
            if (numbers[j] > numbers[j + 1]) {
                // 두 숫자를 교환
                temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }

    // 정렬된 숫자 출력
    printf("정렬된 숫자들: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
