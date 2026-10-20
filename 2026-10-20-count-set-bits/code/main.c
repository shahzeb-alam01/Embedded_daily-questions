#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Count set bits in one 32-bit value (your original function) */
int count_set_bits(uint32_t value)
{
    int count = 0;
    for (int i = 0; i < 32; i++) {
        if ((value >> i) & 1u) {
            count++;
        }
    }
    return count;
}

/* Count set bits across an array of n values */
size_t count_set_bits_array(const uint32_t *arr, size_t n)
{
    size_t total = 0;
    for (size_t i = 0; i < n; i++) {
        total += count_set_bits(arr[i]);
    }
    return total;
}

int main(void)
{
    size_t n;

    printf("Enter number of values: ");
    if (scanf("%zu", &n) != 1 || n == 0) {
        fprintf(stderr, "Invalid count\n");
        return 1;
    }

    /* Allocate n zero-filled elements on the heap */
    uint32_t *arr = calloc(n, sizeof *arr);
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    printf("Enter %zu hex values: ", n);
    for (size_t i = 0; i < n; i++) {
        if (scanf("%x", &arr[i]) != 1) {
            fprintf(stderr, "Invalid input\n");
            free(arr);
            return 1;
        }
    }

    printf("Total set bits: %zu\n", count_set_bits_array(arr, n));

    free(arr);
    return 0;
}
