; ft_strlen.asm
global ft_strlen

section .text
ft_strlen:
    xor eax, eax         ; Initialize length counter to 0
    mov edi, rdi         ; Copy pointer to string to rdi
strlen_loop:
    cmp byte [rdi], 0    ; Compare current byte to 0
    je strlen_done       ; If zero, jump to done
    inc rdi              ; Increment pointer
    inc eax              ; Increment counter
    jmp strlen_loop      ; Repeat loop

strlen_done:
    ret                  ; Return with length in eax