#include <stdio.h>

int add(int a, int b)      { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b)   { return a / b; }   /* integer division, b != 0 */

/* Array of function pointers: index 0..3 maps to the command code */
int (*operations[])(int, int) = { add, subtract, multiply, divide };

#define NUM_OPS (sizeof(operations) / sizeof(operations[0]))

int calculate(int a, int b, int cmd)
{
    if (cmd < 0 || cmd >= (int)NUM_OPS) {
        return 0;                        /* invalid command code */
    }
    return operations[cmd](a, b);        /* call through the function pointer */
}

int main(void)
{
    int a, b, cmd;

    if (scanf("%d %d %d", &a, &b, &cmd) != 3) {
        return 1;
    }
    printf("%d\n", calculate(a, b, cmd));
    return 0;
}
