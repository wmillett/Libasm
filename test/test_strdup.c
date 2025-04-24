#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Declare the ft_strdup function
extern char* ft_strdup(const char* s);

// Function to test ft_strdup
void test_ft_strdup() {
    const char* original = "Hello, World!";
    char* duplicated = ft_strdup(original);

    // if (duplicated == NULL) {
    //     printf("Memory allocation failed.\n");
    //     return;
    // }

    // if (strcmp(original, duplicated) == 0) {
    //     printf("Test passed: '%s' == '%s'\n", original, duplicated);
    // } else {
    //     printf("Test failed: '%s' != '%s'\n", original, duplicated);
    // }

    // Free the allocated memory
    free(duplicated);
}
