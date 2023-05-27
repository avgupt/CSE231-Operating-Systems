global checkGreater

section .text

_start:
    mov rdi, 1
    mov rsi, 2
    call checkGreater
    mov rax, 60
    mov rdi, 0
    syscall

checkGreater:
    cmp rdi, rsi
    jg greater
    jle notGreater
    ret

greater:
    mov rax, 1
    mov rdi, 1
    mov rsi, GREATER
    mov rdx, len1   
    syscall
    ret

notGreater:
    mov rax, 1
    mov rdi, 1
    mov rsi, NOT_GREATER
    mov rdx, len2
    syscall
    ret



section .rodata
GREATER: db "1", 10
len1: equ $ - GREATER
NOT_GREATER: db "0", 10 
len2: equ $ - NOT_GREATER   
