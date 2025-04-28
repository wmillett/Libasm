section .text
    global ft_strcpy

ft_strcpy:
    push ebp ; saves pointer to return from function
    mov ebp, esp ; stack ptr copied to base ptr