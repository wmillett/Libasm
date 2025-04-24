#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// Declare the ft_read function
extern ssize_t ft_read(int fd, void *buf, size_t count);

void test_ft_read() {
    const char *filename = "testfile.txt";
    const char *expected_content = "Hello, World!";
    char buffer[50];
    ssize_t bytes_read;
    int fd;

    // Create a test file with known content
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    if (write(fd, expected_content, strlen(expected_content)) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }
    close(fd);

    // Open the file for reading
    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Call ft_read to read from the file
    bytes_read = ft_read(fd, buffer, sizeof(buffer) - 1);
    if (bytes_read == -1) {
        perror("ft_read");
        close(fd);
        exit(EXIT_FAILURE);
    }
    buffer[bytes_read] = '\0'; // Null-terminate the buffer

    // Verify the content
    if (strcmp(buffer, expected_content) == 0) {
        printf("Test passed: ft_read read the correct content.\n");
    } else {
        printf("Test failed: ft_read did not read the correct content.\n");
        printf("Expected: %s\n", expected_content);
        printf("Got: %s\n", buffer);
    }

    // Clean up
    close(fd);
    unlink(filename);
}
