#include <stdio.h>
#include <string.h>

// Declaration of the assembly function
extern int ft_strlen(const char *str);

void test_ft_strlen_case(const char *test_str) {
    int result = ft_strlen(test_str);
    int expected = strlen(test_str);

    if (result == expected) {
        printf("Test passed for: \"%s\" (Length: %d)\n", test_str, result);
    } else {
        printf("Test failed for: \"%s\". Expected: %d, Got: %d\n", test_str, expected, result);
    }
}
// Function to test ft_strlen
void test_ft_strlen() {
    // Test cases
    printf("Running tests for ft_strlen...\n");
    test_ft_strlen_case("");                    // Test with an empty string
    test_ft_strlen_case("A");                   // Test with a single character
    test_ft_strlen_case("Hello, World!");       // Test with a typical string
    test_ft_strlen_case("1234567890");          // Test with a numeric string
    test_ft_strlen_case("This is a longer string to test."); // Test with a longer string
    printf("All tests completed.\n");
}

