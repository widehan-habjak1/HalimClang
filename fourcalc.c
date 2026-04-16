#include <stdio.h>
int main() {
	int a, b;
	char op;
    printf("Enter 2 numbers & 1 operation (ex. 1 + 1)_ ");
	scanf("%d %c %d", &a, &op, &b);
	switch (op) { 
        case '+': 
            printf("%d + %d = %d\n", a, b, a + b);
            break; 

        case '-':
            printf("%d - %d = %d\n", a, b, a - b);
            break;

        case '*':
            printf("%d * %d = %d\n", a, b, a * b);
            break;

        case '/':
            if (b != 0) { 
                printf("%d / %d = %.2f\n", a, b, (float)a / b);
            } else {
                printf("0으로 나눌 수 없습니다.\n");
            }
            break;

        default:
            printf("%c는 사칙연산자가 아닙니다.\n", op);
            break;
    }
	
	return 0;
}