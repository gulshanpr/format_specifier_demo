#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void test_printf(const char *format, ...) __attribute__((format(printf, 1, 2)));

void test_printf(const char *format, ...) {
    va_list args;
    va_start(args, format);


    while (*format) {
        if (*format == '%' && *(format + 1) == 's' && *(format + 2) == 'T') {
            char *truncatedString = va_arg(args, char *);
            size_t len = strlen(truncatedString);
            if (len > 10) {
                
                printf("Truncated String: ");
                for (size_t i = 0; i < 15; i++) {
                    putchar(truncatedString[i]);
                }
                printf("...\n");
            } else {
                printf("Truncated String: %s\n", truncatedString);
            }

            format += 3;
        } else {
            putchar(*format);
            format++;
        }
    }

    va_end(args);
}

int main() {
    test_printf("Testing %sT", "This is a long string that should be truncated");
    return 0;
}
