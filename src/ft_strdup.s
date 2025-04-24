section .text
global ft_strdup
extern malloc
extern ft_strlen
extern __errno_location

ft_strdup:
    ; Save the original string pointer in rsi
    mov rsi, rdi

    ; Call ft_strlen to get the length of the string
    call ft_strlen

    ; Save the length in rcx and add 1 for the null terminator
    mov rcx, rax
    inc rcx

    ; Allocate memory for the new string
    mov rdi, rcx
    call malloc wrt ..plt  ; Use PLT for position-independent code
    test rax, rax
    jz malloc_failed

    ; Save the original string pointer and length
    push rsi
    push rcx

    ; Copy the original string to the new memory
    mov rdi, rax        ; destination
    pop rcx             ; length
    pop rsi             ; source
    rep movsb

    ; Return the pointer to the new string
    ret

malloc_failed:
    ; If malloc fails, set errno to ENOMEM
    mov rdi, 12  ; ENOMEM error code
    call __errno_location wrt ..plt
    mov [rax], rdi

    ; Return NULL to indicate failure
    xor rax, rax
    ret
