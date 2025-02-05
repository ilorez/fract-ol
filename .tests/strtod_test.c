#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <limits.h>

typedef struct {
    const char *input;
    double expected_value;
    const char *expected_end;
    const char *description;
} TestCase;

int ft_isspace(char c) {
    return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int ft_isdigit(char c) {
    return (c >= '0' && c <= '9');
}


static void _ft_get_signe(const char **nptr, int *signe)
{
  if (**nptr == '-' || **nptr == '+')
        if (*(*nptr)++ == '-')
            *signe = -1;
}

double ft_strtod(const char *nptr, char **endptr)
{
    unsigned long long div;
    int signe;
    double re;

    signe = 1;
    div = 10;
    re = 0.0;
    if (!nptr)
        return (0);
    while (ft_isspace(*nptr))
        nptr++;
    _ft_get_signe( &nptr, &signe);
    while (ft_isdigit(*nptr))
        re = re * 10 + (*nptr++ - '0');
    if (*nptr == '.')
        nptr++;
    while (ft_isdigit(*nptr) && div < LLONG_MAX)
    {
        re += (double)(*nptr++ - '0') / div;
        div *= 10;
    }
    if (*nptr && endptr)
        *endptr = (char *)nptr;
    return (re * signe);
}

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

int main() {
    TestCase tests[] = {
        {"123.45", 123.45, NULL, "Basic positive number"},
        {"-123.45", -123.45, NULL, "Basic negative number"},
        {"+123.45", 123.45, NULL, "Positive with explicit sign"},
        {"123.45abc", 123.45, "123.45abc" + 6, "Trailing non-digit characters"},
        {"123abc", 123.0, "123abc" + 3, "Integer part with trailing characters"},
        {"   123.45", 123.45, NULL, "Leading whitespace"},
        {"123.45   ", 123.45, "123.45   " + 6, "Trailing whitespace"},
        {"123", 123.0, NULL, "No decimal part"},
        {".45", 0.45, NULL, "No integer part"},
        {"123.", 123.0, NULL, "No digits after decimal"},
        {"12.34.56", 12.34, "12.34.56" + 5, "Multiple decimal points"},
        {"abc", 0.0, "abc", "Invalid characters"},
        {"   abc", 0.0, "   abc" + 3, "Whitespace followed by invalid"},
        {"", 0.0, NULL, "empty string"},
        {"              ", 0.0, NULL, "whitespace string"},
        {".", 0.0, NULL, "only point"},
        {"44.", 44.0, NULL, "number and point"},
        {".44", 0.44, NULL, "point and number"},
        {"0", 0.0, NULL, "Zero integer"},
        {"0.0", 0.0, NULL, "Zero with decimal"},
        {"-0.0", -0.0, NULL, "Negative zero"},
        {"0.123456789012345678", 0.123456789012345678, NULL, "18 fractional digits"},
        {"0.123456789012345678901234567890", 0.123456789012345678, "0.123456789012345678901234567890" + 20, "More than 18 fractional digits"},
        {NULL, 0.0, NULL, "NULL input"}
    };

    int num_tests = ARRAY_SIZE(tests);
    int passed = 0;

    for (int i = 0; i < num_tests; i++) {
        TestCase *tc = &tests[i];
        printf("Test %d: %s\n", i + 1, tc->description);

        char *endptr = NULL;
        double result = ft_strtod(tc->input, &endptr);

        if (tc->input == NULL) {
            if (result == 0.0 && endptr == NULL) {
                printf("PASS\n");
                passed++;
            } else {
                printf("FAIL: Expected 0.0 and NULL endptr, got %f and %p\n", result, (void*)endptr);
            }
            continue;
        }

        double diff = fabs(result - tc->expected_value);
        int value_ok = (diff < 1e-9) || (diff < fabs(tc->expected_value) * DBL_EPSILON);
        int endptr_ok = (tc->expected_end == NULL) ? (endptr == NULL) : (endptr == tc->expected_end);

        if (value_ok && endptr_ok) {
            printf("PASS\n");
            passed++;
        } else {
            printf("FAIL\n");
            printf("  Expected value: %.15f, got %.15f\n", tc->expected_value, result);
            printf("  Expected endptr: %p (%s), got %p (%s)\n",
                   (void*)tc->expected_end, tc->expected_end ? tc->expected_end : "NULL",
                   (void*)endptr, endptr ? endptr : "NULL");
        }
    }

    printf("\nPassed %d out of %d tests.\n", passed, num_tests);
    return (passed == num_tests) ? 0 : 1;
}

