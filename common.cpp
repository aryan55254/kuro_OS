#include "common.hpp"

void putchar(char ch);

void printf(const char *fmt, ...)
{
    va_list vargs;
    va_start(vargs, fmt);

    while (*fmt)
    {
        if (*fmt == '%')
        {
            fmt++;
            switch (*fmt)
            {
            case '\0':
                putchar('%');
                goto end;
            case '%':
                putchar('%');
                break;
            case 's':
            {
                const char *s = va_arg(vargs, const char *);
                if (!s)
                    s = "(null)";
                while (*s)
                {
                    putchar(*s++);
                }
                break;
            }
            case 'd':
            {
                int value = va_arg(vargs, int);
                if (value == 0)
                {
                    putchar('0');
                    break;
                }

                unsigned magnitude = value;
                if (value < 0)
                {
                    putchar('-');
                    magnitude = static_cast<unsigned>(-value);
                }

                unsigned divisor = 1;
                while (magnitude / divisor >= 10)
                {
                    divisor *= 10;
                }

                while (divisor > 0)
                {
                    putchar('0' + (magnitude / divisor));
                    magnitude %= divisor;
                    divisor /= 10;
                }
                break;
            }
            case 'x':
            case 'p':
            {
                unsigned value = va_arg(vargs, unsigned);
                for (int i = 7; i >= 0; i--)
                {
                    unsigned nibble = (value >> (i * 4)) & 0xf;
                    putchar("0123456789abcdef"[nibble]);
                }
                break;
            }
            default:
                putchar('%');
                putchar(*fmt);
                break;
            }
        }
        else
        {
            putchar(*fmt);
        }
        fmt++;
    }

end:
    va_end(vargs);
}