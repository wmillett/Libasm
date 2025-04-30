section .text
global ft_strdup
extern malloc
extern ft_strlen
extern __errno_location

ft_strdup:
    ; Check for NULL input first
    test rdi, rdi
    jz handle_null

    ; Save the original string pointer
    push rdi

    ; Call ft_strlen to get the length
    call ft_strlen

    ; Restore original string pointer to rsi
    pop rsi

    ; Calculate length + 1 for null terminator
    lea rdi, [rax + 1]

    ; Save the length and original pointer
    push rsi
    push rdi

    ; Allocate memory
    call malloc wrt ..plt
    test rax, rax
    jz malloc_failed

    ; Set up for string copy
    mov rdi, rax        ; destination
    pop rcx             ; length + 1
    pop rsi             ; source

    ; Copy the string
    rep movsb

    ; Return the new string
    ret

handle_null:
    ; Return NULL for NULL input
    xor rax, rax
    ret

malloc_failed:
    ; Set errno to ENOMEM (12)
    mov rdi, 12
    call __errno_location wrt ..plt
    mov [rax], rdi

    ; Return NULL
    xor rax, rax
    ret