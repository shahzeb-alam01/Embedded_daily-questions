#include <stdio.h>

int my_atoi(const char data[]) {
    int result = 0;
    int sign = 1;
    int i = 0;

    if (data[i] == '-') {            // optional minus sign
        sign = -1;
        i++;
    }

    for (; data[i] != '\0'; i++) {   // loop until the terminating '\0'
        if (data[i] < '0' || data[i] > '9')
            break;                   // stop at the first non-digit
        result = result * 10 + (data[i] - '0');
    }

    return sign * result;
}

int main(void) {
    char data[100];

    printf("Enter the data: ");
    scanf("%99s", data);

    printf("%d\n", my_atoi(data));
    return 0;
}
