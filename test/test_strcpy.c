#include <stdio.h>
#include <string.h>

// Declaration of the assembly function
extern char *ft_strcpy(char *dest, const char *src);

void test_ft_strcpy_case(const char *src, const char *expected) {
    char dest[100]; // Ensure this is large enough for the test cases
    char *result = ft_strcpy(dest, src);

    if (strcmp(result, expected) == 0 && strcmp(dest, expected) == 0) {
        printf("Test passed for src: \"%s\". Expected: \"%s\"\n", src, expected);
    } else {
        printf("Test failed for src: \"%s\". Expected: \"%s\", Got: \"%s\"\n", src, expected, result);
    }
}
// Function to test ft_strcpy
void test_ft_strcpy() {
    // Test cases
    printf("---------------------\n");
    printf("Running tests for ft_strcpy...\n");
    test_ft_strcpy_case("", "");                    // Test with an empty string
    test_ft_strcpy_case("A", "A");                   // Test with a single character
    test_ft_strcpy_case("Hello, World!", "Hello, World!"); // Test with a typical string
    test_ft_strcpy_case("1234567890", "1234567890");          // Test with a numeric string
    test_ft_strcpy_case("This is a longer string to test.", "This is a longer string to test."); // Test with a longer string
    printf("All tests completed.\n");
    printf("---------------------\n");
}
