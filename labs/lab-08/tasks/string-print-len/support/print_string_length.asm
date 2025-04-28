section .data
    print_format db "String length is %d", 10, 0

section .text

extern printf
global print_string_length

print_string_length:
    push ebp
    mov ebp, esp
    push ebx                ; preserve ebx as required by cdecl

    ; TODO: print the string length

    mov ecx, [ebp + 8]

    push ecx
    push print_format
    call printf
    add esp, 8

    pop ebx
    leave
    ret
