#include <stdio.h>

static int is_delim(char c, const char *delim)
{
    while (*delim) {
        if (c == *delim++) return 1;
    }
    return 0;
}

char *my_strtok(char *str, const char *delim)
{
    static char *next = NULL;      /* remembers position between calls */

    if (str != NULL) next = str;   /* first call: start of new string */
    if (next == NULL) return NULL;

    while (*next && is_delim(*next, delim)) next++;   /* skip leading delimiters */
    if (*next == '\0') { next = NULL; return NULL; }

    char *token = next;
    while (*next && !is_delim(*next, delim)) next++;  /* find end of token */

    if (*next != '\0') { *next = '\0'; next++; }      /* cut token, resume after it */
    else               { next = NULL; }               /* end of string reached */

    return token;
}

int main(void)
{
    char data[] = "ADC1,ADC2;;UART3 SPI1";   /* must be an array, not a string literal */
    char *tok = my_strtok(data, ",; ");

    while (tok != NULL) {
        printf("%s\n", tok);
        tok = my_strtok(NULL, ",; ");
    }
    return 0;
}
