
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

extern ssize_t ft_read(int fd, void *buf, size_t count);

void run_read_test(const char *description, int fd, void *buf, size_t count, 
                  ssize_t expected_bytes, int expected_errno) {
    printf("Test: %s\n", description);
    
    errno = 0; // Reset errno before test
    ssize_t result = ft_read(fd, buf, count);
    
    if (result == expected_bytes) {
        if (expected_errno == 0) {
            printf("✓ Passed (correct byte count)\n");
        } else {
            printf("✓ Passed (correct error)\n");
        }
    } else {
        printf("✗ Failed: Expected %zd, got %zd\n", expected_bytes, result);
    }
    
    if (expected_errno != 0 && errno != expected_errno) {
        printf("✗ Wrong errno: Expected %d (%s), got %d (%s)\n",
               expected_errno, strerror(expected_errno),
               errno, strerror(errno));
    }
    
    printf("-----\n");
}

void test_ft_read() {
    char buffer[50];
    const char *filename = "testfile.txt";
    const char *content = "This is test content for ft_read testing.";
    
    // Setup - create test file
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    write(fd, content, strlen(content));
    close(fd);

    // 1. Normal read test
    fd = open(filename, O_RDONLY);
    run_read_test("Normal read", fd, buffer, sizeof(buffer), strlen(content), 0);
    close(fd);

    // 2. Partial read test
    fd = open(filename, O_RDONLY);
    run_read_test("Partial read (5 bytes)", fd, buffer, 5, 5, 0);
    close(fd);

    // 3. Empty file test
    system("touch empty.txt");
    fd = open("empty.txt", O_RDONLY);
    run_read_test("Empty file read", fd, buffer, sizeof(buffer), 0, 0);
    close(fd);
    unlink("empty.txt");

    // 4. Read with buffer too small
    fd = open(filename, O_RDONLY);
    char small_buf[5];
    run_read_test("Buffer too small", fd, small_buf, sizeof(small_buf), 5, 0);
    close(fd);

    // 5. Invalid file descriptor
    run_read_test("Invalid fd (-1)", -1, buffer, sizeof(buffer), -1, EBADF);

    // 6. Read from stdin (fd 0)
    printf("Please type 'test' and press enter for stdin test...\n");
    run_read_test("Read from stdin", 0, buffer, 5, 5, 0);
    buffer[5] = '\0';
    printf("You entered: %s\n", buffer);

    // 7. Zero count test
    fd = open(filename, O_RDONLY);
    run_read_test("Zero count read", fd, buffer, 0, 0, 0);
    close(fd);

    // 8. Error case (directory)
    fd = open(".", O_RDONLY);
    run_read_test("Read from directory", fd, buffer, sizeof(buffer), -1, EISDIR);
    close(fd);

    // Cleanup
    unlink(filename);
}
