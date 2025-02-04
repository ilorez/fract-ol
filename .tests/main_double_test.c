#include "stdio.h"
#include <ctype.h>
#include <math.h>
#include <errno.h>
#include <ctype.h>
#include <math.h>
#include <errno.h>
#include <limits.h>

double my_strtod(const char *str, char **endptr) {
    const char *p = str;
    double result = 0.0;
    int sign = 1;
    long long significand = 0;
    int exponent = 0;
    int frac_digits = 0;

    // Skip whitespace
    while (isspace((unsigned char)*p)) p++;

    // Handle sign
    if (*p == '-') { sign = -1; p++; }
    else if (*p == '+') p++;

    // Parse special cases
    if (tolower(p[0]) == 'i' && tolower(p[1]) == 'n' && tolower(p[2]) == 'f') {
        p += 3;
        if (tolower(p[0]) == 'i' && tolower(p[1]) == 'n' && tolower(p[2]) == 'i' &&
            tolower(p[3]) == 't' && tolower(p[4]) == 'y') p += 5;
        if (endptr) *endptr = (char *)p;
        return sign * INFINITY;
    }
    if (tolower(p[0]) == 'n' && tolower(p[1]) == 'a' && tolower(p[2]) == 'n') {
        p += 3;
        if (endptr) *endptr = (char *)p;
        return NAN;
    }

    // Parse digits (simplified decimal case)
    while (isdigit((unsigned char)*p)) {
        significand = significand * 10 + (*p - '0');
        p++;
    }

    if (*p == '.') {
        p++;
        while (isdigit((unsigned char)*p)) {
            significand = significand * 10 + (*p - '0');
            frac_digits++;
            p++;
        }
    }

    if (tolower(*p) == 'e') {
        p++;
        int exp_sign = 1;
        if (*p == '-') { exp_sign = -1; p++; }
        else if (*p == '+') p++;
        while (isdigit((unsigned char)*p)) {
            exponent = exponent * 10 + (*p - '0');
            p++;
        }
        exponent *= exp_sign;
    }

    exponent -= frac_digits;

    // Check for overflow
    if (exponent > 1023) {
        errno = ERANGE;
        if (endptr) *endptr = (char *)p;
        return sign * HUGE_VAL;
    }

    // Convert significand and exponent to double (simplified)
    result = (double)significand;
    result *= pow(10, exponent);
    result *= sign;

    if (endptr) *endptr = (char *)p;
    return result;
}int main()
{
  double dou = 2147483648123.19 ;

  printf("%lf\n", dou);

}
#include <ctype.h>
#include <math.h>
#include <errno.h>

double my_strtod(const char *str, char **endptr) {
    const char *p = str;
    double result = 0.0;
    int sign = 1;
    long long significand = 0;
    int exponent = 0;
    int frac_digits = 0;

    // Skip whitespace
    while (isspace((unsigned char)*p)) p++;

    // Handle sign
    if (*p == '-') { sign = -1; p++; }
    else if (*p == '+') p++;

    // Parse special cases
    if (tolower(p[0]) == 'i' && tolower(p[1]) == 'n' && tolower(p[2]) == 'f') {
        p += 3;
        if (tolower(p[0]) == 'i' && tolower(p[1]) == 'n' && tolower(p[2]) == 'i' &&
            tolower(p[3]) == 't' && tolower(p[4]) == 'y') p += 5;
        if (endptr) *endptr = (char *)p;
        return sign * INFINITY;
    }
    if (tolower(p[0]) == 'n' && tolower(p[1]) == 'a' && tolower(p[2]) == 'n') {
        p += 3;
        if (endptr) *endptr = (char *)p;
        return NAN;
    }

    // Parse digits (simplified decimal case)
    while (isdigit((unsigned char)*p)) {
        significand = significand * 10 + (*p - '0');
        p++;
    }

    if (*p == '.') {
        p++;
        while (isdigit((unsigned char)*p)) {
            significand = significand * 10 + (*p - '0');
            frac_digits++;
            p++;
        }
    }

    if (tolower(*p) == 'e') {
        p++;
        int exp_sign = 1;
        if (*p == '-') { exp_sign = -1; p++; }
        else if (*p == '+') p++;
        while (isdigit((unsigned char)*p)) {
            exponent = exponent * 10 + (*p - '0');
            p++;
        }
        exponent *= exp_sign;
    }

    exponent -= frac_digits;

    // Convert significand and exponent to double (simplified)
    result = (double)significand;
    result *= pow(10, exponent);
    result *= sign;

    if (endptr) *endptr = (char *)p;
    return result;
}
