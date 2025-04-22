#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>

// Declare the ft_write function
extern ssize_t ft_write(int fd, const void *buf, size_t count);

// Function to test ft_write
void test_ft_write() {
    const char *test_str = "Hello, World!\n";
    ssize_t bytes_written;

    // Test writing to standard output
    printf("Testing ft_write to stdout...\n");
    bytes_written = ft_write(STDOUT_FILENO, test_str, strlen(test_str));
    if (bytes_written == (ssize_t)strlen(test_str)) {
        printf("Test passed: wrote %zd bytes to stdout\n", bytes_written);
    } else {
        printf("Test failed: expected %zu bytes, wrote %zd bytes\n", strlen(test_str), bytes_written);
    }

    // Test writing to a file
    int fd = open("test_output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Failed to open file");
        return;
    }

    printf("Testing ft_write to file...\n");
    bytes_written = ft_write(fd, test_str, strlen(test_str));
    if (bytes_written == (ssize_t)strlen(test_str)) {
        printf("Test passed: wrote %zd bytes to file\n", bytes_written);
    } else {
        printf("Test failed: expected %zu bytes, wrote %zd bytes\n", strlen(test_str), bytes_written);
    }

    close(fd);

    // Test writing to an invalid file descriptor
    printf("Testing ft_write to invalid file descriptor...\n");
    bytes_written = ft_write(-1, test_str, strlen(test_str));
    int saved_errno = errno;  // Save errno immediately after the call
    if (bytes_written == -1 && saved_errno == EBADF) {
        printf("Test passed: ft_write returned -1 and set errno to EBADF\n");
    } else {
        printf("Test failed: expected -1 and EBADF, got %zd and errno %d\n", bytes_written, saved_errno);
    }
}
