#include <stdio.h>

void test_ft_strdup();
void test_ft_strlen();
void test_ft_write();
void test_ft_read();
void test_ft_strcmp();
void test_ft_strcpy();

int main() {
    printf("\033[38;5;208m");  // Orange
    test_ft_strdup();
    
    printf("\033[38;5;46m");   // Bright Green
    test_ft_strlen();
    
    printf("\033[38;5;201m");  // Pink
    test_ft_write();
    
    printf("\033[38;5;51m");   // Cyan
    test_ft_read();
    
    printf("\033[38;5;226m");  // Yellow
    test_ft_strcmp();
    
    printf("\033[38;5;165m");  // Purple
    test_ft_strcpy();
    
    printf("\033[0m");         // Reset
    return 0;
}