section .text
    global ft_strdup
    extern malloc
    extern ft_strlen

ft_strdup:
    ; Save the original string pointer
    mov rsi, rdi

    ; Call ft_strlen to get the length of the string
    call ft_strlen

    ; Save the length in rcx and add 1 for the null terminator
    mov rcx, rax
    inc rcx

    ; Allocate memory for the new string
    mov rdi, rcx
    call malloc
    test rax, rax
    jz malloc_failed

    ; Copy the original string to the new memory
    mov rdi, rax
    mov rsi, [rsp + 8]
    mov rcx, [rsp]
    rep movsb

    ; Return the pointer to the new string
    ret

malloc_failed:
    ; If malloc fails, return NULL
    xor rax, rax
    ret
