section .text
    global ft_strdup ;



ft_strdup:
    xor rax, rax ;
    mov rdi, rdi ;
strdup_loop:
    cmp byte [rdi], 0 ;
    je strdup_done ;
    


strdup_done:
    ret ;