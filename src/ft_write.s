section .text
global ft_write  ; Ensure this is exported
extern __errno_location  ; External symbol to get the address of errno

ft_write:
    ; Parameters:
    ; rdi: file descriptor
    ; rsi: buffer
    ; rdx: count

    mov rax, 1          ; syscall number for sys_write
    syscall             ; invoke the syscall

    ; Check if the syscall failed
    test rax, rax
    js handle_error     ; if the sign bit is set, jump to handle_error

    ; Syscall succeeded, return the result
    ret

handle_error:
    ; Syscall failed, set errno
    neg rax             ; negate rax to get the positive error code
    mov rdi, rax        ; move the error code to rdi
    call __errno_location wrt ..plt  ; get the address of errno
    mov [rax], rdi      ; set errno to the error code

    ; Return -1 to indicate failure
    mov rax, -1
    ret
