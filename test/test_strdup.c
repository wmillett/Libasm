#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

// Declare the ft_strdup function
extern char* ft_strdup(const char* s);

// Function to test ft_strdup
void test_ft_strdup() {
    const char* original = "Hello, World!";
    char* duplicated = ft_strdup(original);

    printf("---------------------\n");
    printf("Running tests for ft_strdup...\n");
    printf("Original: '%s'\n", original);
    if (duplicated == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    if (strcmp(original, duplicated) == 0) {
        printf("Test passed: '%s' == '%s'\n", original, duplicated);
    } else {
        printf("Test failed: '%s' != '%s'\n", original, duplicated);
    }
    free(duplicated);

    // Test empty string
    original = "";
    duplicated = ft_strdup(original);
    if (duplicated && strcmp(original, duplicated) == 0) {
        printf("Test passed (empty string): '%s' == '%s'\n", original, duplicated);
    } else {
        printf("Test failed (empty string)\n");
    }
    free(duplicated);

    // Test single character
    original = "A";
    duplicated = ft_strdup(original);
    if (duplicated && strcmp(original, duplicated) == 0) {
        printf("Test passed (single char): '%s' == '%s'\n", original, duplicated);
    } else {
        printf("Test failed (single char)\n");
    }
    free(duplicated);

    // Test NULL input
    original = NULL;
    duplicated = ft_strdup(original);
    if (duplicated == NULL) {
        printf("Test passed (NULL input): handled correctly\n");
    } else {
        printf("Test failed (NULL input)\n");
        free(duplicated);
    }

    // Test special characters
    original = "Special\tchars\n!@#$%";
    duplicated = ft_strdup(original);
    if (duplicated && strcmp(original, duplicated) == 0) {
        printf("Test passed (special chars): '%s' == '%s'\n", original, duplicated);
    } else {
        printf("Test failed (special chars)\n");
    }
    free(duplicated);
    printf("All tests completed.\n");
    printf("---------------------\n");
}