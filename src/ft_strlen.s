section .text
global ft_strlen  ; Ensure this is exported

ft_strlen:
    xor rax, rax           ; Initialize length counter to 0
    mov rdi, rdi           ; Set pointer to rdi (assuming rdi has the string address)
strlen_loop:
    cmp byte [rdi], 0      ; Compare current byte to 0
    je strlen_done         ; If zero, jump to done
    inc rdi                ; Increment pointer
    inc rax                ; Increment counter
    jmp strlen_loop        ; Repeat loop
strlen_done:
    ret                    ; Return with length in rax
