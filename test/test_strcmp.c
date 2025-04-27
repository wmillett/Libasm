#include <stdio.h>
#include <string.h>

// Declare the ft_strcmp function
int ft_strcmp(const char *s1, const char *s2);

void test_ft_strcmp() {
    // Test cases
    const char *test1_s1 = "Hello, World!";
    const char *test1_s2 = "Hello, World!";
    const char *test2_s1 = "Hello";
    const char *test2_s2 = "Hello, World!";
    const char *test3_s1 = "Hello, World!";
    const char *test3_s2 = "Hello";
    const char *test4_s1 = "";
    const char *test4_s2 = "";
    const char *test5_s1 = "a";
    const char *test5_s2 = "b";
    const char *test6_s1 = "abc";
    const char *test6_s2 = "";

    // Expected results using standard strcmp
    int expected1 = strcmp(test1_s1, test1_s2);
    int expected2 = strcmp(test2_s1, test2_s2);
    int expected3 = strcmp(test3_s1, test3_s2);
    int expected4 = strcmp(test4_s1, test4_s2);
    int expected5 = strcmp(test5_s1, test5_s2);
    int expected6 = strcmp(test6_s1, test6_s2);

    // Actual results using ft_strcmp
    int actual1 = ft_strcmp(test1_s1, test1_s2);
    int actual2 = ft_strcmp(test2_s1, test2_s2);
    int actual3 = ft_strcmp(test3_s1, test3_s2);
    int actual4 = ft_strcmp(test4_s1, test4_s2);
    int actual5 = ft_strcmp(test5_s1, test5_s2);
    int actual6 = ft_strcmp(test6_s1, test6_s2);

    // Print results
    printf("Test 1: %s vs %s (Expected: %d, Actual: %d) %s\n", test1_s1, test1_s2, expected1, actual1, (expected1 == actual1) ? "PASS" : "FAIL");
    printf("Test 2: %s vs %s (Expected: %d, Actual: %d) %s\n", test2_s1, test2_s2, expected2, actual2, (expected2 == actual2) ? "PASS" : "FAIL");
    printf("Test 3: %s vs %s (Expected: %d, Actual: %d) %s\n", test3_s1, test3_s2, expected3, actual3, (expected3 == actual3) ? "PASS" : "FAIL");
    printf("Test 4: %s vs %s (Expected: %d, Actual: %d) %s\n", test4_s1, test4_s2, expected4, actual4, (expected4 == actual4) ? "PASS" : "FAIL");
    printf("Test 5: %s vs %s (Expected: %d, Actual: %d) %s\n", test5_s1, test5_s2, expected5, actual5, (expected5 == actual5) ? "PASS" : "FAIL");
    printf("Test 6: %s vs %s (Expected: %d, Actual: %d) %s\n", test6_s1, test6_s2, expected6, actual6, (expected6 == actual6) ? "PASS" : "FAIL");
}
