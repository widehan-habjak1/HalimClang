#include <stdio.h>

int hosu(int b, int n) {
    int remainder = n % 4;

    if (remainder < 0) {
        remainder += 4;
    }

    if (remainder == 1) {
        return b;
    }

    if (remainder == 3) {
        return -b;
    }

    return 0;
}

int main() {
    char input[100];
    int a, b, n;
    int i;
    int real_part;
    int i_part;

    printf("복소수 a+bi^n을 입력하세요 (띄어쓰기 금지)> ");
    fgets(input, sizeof(input), stdin);

    if (sscanf(input, "%d%d""i^%d", &a, &b, &n) != 3) {
        if (sscanf(input, "%d%d""i", &a, &b) == 2) {
            n = 1;
        } else {
            printf("형식 똑바로 지키세요.\n");
            return 1;
        }
    }

    i = n % 4;
    if (i < 0) {
        i += 4;
    }

    if (i == 0) {
        real_part = a + b;
        printf("결과:  %d\n", real_part);
    } else if (i == 2) {
        real_part = a - b;
        printf("결과: %d\n", real_part);
    } else {
        i_part = hosu(b, n);

        if (i_part >= 0) {
            printf("결과: %d + %di\n", a, i_part);
        } else {
            printf("결과: %d - %di\n", a, -i_part);
        }
    }

    return 0;
}
