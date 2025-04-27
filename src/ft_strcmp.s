section .text
global ft_strcmp

ft_strcmp:
    ; Entry point of the function
    jmp compare_loop

compare_loop:
    mov al, byte [rdi]  ; Load byte from first string
    mov bl, byte [rsi]  ; Load byte from second string

    cmp al, bl          ; Compare bytes
    jne not_equal       ; Jump if bytes are not equal

    cmp al, 0           ; Check if end of first string
    je strcmp_done      ; Jump if end of string

    inc rdi             ; Increment pointer to first string
    inc rsi             ; Increment pointer to second string

    jmp compare_loop    ; Repeat loop

not_equal:
    movzx rax, al       ; Move byte from first string to rax with zero-extension
    movzx rbx, bl       ; Move byte from second string to rbx with zero-extension
    sub rax, rbx        ; Subtract second byte from first byte
    ret                 ; Return the difference

strcmp_done:
    xor rax, rax        ; Set rax to 0 (strings are equal)
    ret                 ; Return 0
