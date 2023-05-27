global long_add
section .text

long_add:
    add eax, esi
    add eax, edx
    add eax, ecx
    ret
