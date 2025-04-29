section .text
    global ft_strcpy
    extern __errno_location

ft_strcpy:
    ; Parameters:
    ; rdi: destination buffer
    ; rsi: source string
    mov rdx, rdi                ; Save the original destination pointer

copy_loop:
    mov al, byte [rsi]          ; Load byte from source
    mov byte [rdi], al          ; Store byte to destination
    inc rsi                     ; Increment source pointer
    inc rdi                     ; Increment destination pointer
    test al, al                 ; Check if byte is zero (end of string)
    jnz copy_loop               ; If not zero, repeat

    mov rax, rdx                ; Return the original destination pointer
    ret

handle_error:
    ; Set errno to EFAULT (14) for bad address
    mov rdi, 14
    call __errno_location wrt ..plt
    mov [rax], rdi
    mov rax, -1                 ; Return -1 to indicate error
    ret
