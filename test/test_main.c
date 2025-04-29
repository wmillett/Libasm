#include <stdio.h>

// Declare the test functions
void test_ft_strdup();
void test_ft_strlen();
void test_ft_write();
void test_ft_read();
void test_ft_strcmp();
void test_ft_strcpy();

int main() {
    // Run all tests
    printf("\033[31m");
    //test_ft_strdup(); //TODO: fix strdup so it does not segfault
    printf("\033[32m");
    test_ft_strlen();
    printf("\033[33m");
    test_ft_write();
    printf("\033[34m");
    test_ft_read();
    printf("\033[35m");
    test_ft_strcmp();
    printf("\033[36m");
    test_ft_strcpy();
    printf("\033[0m");
    return 0;
}
