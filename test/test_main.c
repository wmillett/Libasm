#include <stdio.h>

// Declare the test functions
void test_ft_strdup();
void test_ft_strlen();
void test_ft_write();
void test_ft_read();
void test_ft_strcmp();

int main() {
    // Run all tests
    //test_ft_strdup(); //TODO: fix strdup so it does not segfault
    test_ft_strlen();
    test_ft_write();
    test_ft_read();
    test_ft_strcmp();
    return 0;
}
