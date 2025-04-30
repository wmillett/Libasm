#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <limits.h>

extern ssize_t ft_write(int fd, const void *buf, size_t count);

void run_write_test(const char *description, int fd, const void *buf, size_t count, 
                   ssize_t expected_bytes, int expected_errno) {
    printf("\n--- %s ---\n", description);
    
    errno = 0;
    ssize_t result = ft_write(fd, buf, count);
    int actual_errno = errno;
    
    if (result == expected_bytes) {
        if (expected_errno == 0) {
            printf("✓ PASS: Correct byte count (%zd)\n", result);
        } else {
            printf("✓ PASS: Correct error return (%zd)\n", result);
        }
    } else {
        printf("✗ FAIL: Expected %zd, got %zd\n", expected_bytes, result);
    }
    
    if (expected_errno != 0) {
        if (actual_errno == expected_errno) {
            printf("✓ PASS: Correct errno (%d: %s)\n", actual_errno, strerror(actual_errno));
        } else {
            printf("✗ FAIL: Expected errno %d (%s), got %d (%s)\n",
                  expected_errno, strerror(expected_errno),
                  actual_errno, strerror(actual_errno));
        }
    }
}

void test_ft_write() {
    const char *test_str = "Hello, World!\n";
    const char *empty_str = "";
    const char *long_str = "This is a longer string to test buffer limits and proper writing behavior.\n";
    
    printf("---------------------\n");
    printf("Running tests for ft_write...\n");
    // 1. Standard output test
    run_write_test("STDOUT: Normal write", STDOUT_FILENO, test_str, strlen(test_str), strlen(test_str), 0);
    
    // 2. File write test
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        return;
    }
    run_write_test("FILE: Normal write", fd, test_str, strlen(test_str), strlen(test_str), 0);
    close(fd);
    
    // 3. Empty string write
    fd = open("empty_write.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    run_write_test("FILE: Empty string write", fd, empty_str, 0, 0, 0);
    close(fd);
    
    // 4. Long string write
    fd = open("long_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    run_write_test("FILE: Long string write", fd, long_str, strlen(long_str), strlen(long_str), 0);
    close(fd);
    
    // 5. Invalid file descriptor
    run_write_test("ERROR: Bad file descriptor", -1, test_str, strlen(test_str), -1, EBADF);
    
    // 6. Write to read-only file descriptor
    fd = open("readonly.txt", O_RDONLY | O_CREAT, 0444);
    run_write_test("ERROR: Write to read-only fd", fd, test_str, strlen(test_str), -1, EBADF);
    close(fd);
    
    // 7. Partial write test (alternative approach)
    fd = open("partial.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    // Simulate partial write by limiting count
    run_write_test("FILE: Partial write simulation", fd, long_str, 10, 10, 0);
    close(fd);
    
    // 8. NULL buffer test (should return -1 with EFAULT)
    run_write_test("ERROR: NULL buffer", STDOUT_FILENO, NULL, 10, -1, EFAULT);
    
    // 9. Large buffer test (smaller size for portability)
    fd = open("large_buffer.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    char big_buf[1024]; // Reduced size for portability
    memset(big_buf, 'A', sizeof(big_buf));
    run_write_test("STRESS: Large buffer write", fd, big_buf, sizeof(big_buf), sizeof(big_buf), 0);
    close(fd);
    
    printf("\nNote: Some tests may behave differently depending on system implementation.\n");
    printf("All tests completed.\n");
    printf("---------------------\n");
    // Cleanup
    unlink("test_output.txt");
    unlink("empty_write.txt");
    unlink("long_output.txt");
    unlink("partial.txt");
    unlink("large_buffer.txt");
    unlink("readonly.txt");
}
