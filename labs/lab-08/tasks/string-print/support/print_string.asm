section .text

extern puts
global print_string

print_string:
    push ebp
    mov ebp, esp
    push ebx                ; preserve ebx as required by cdecl

    ; TODO: print the string

    mov eax, [ebp + 8]

    push eax
    call puts
    add esp, 4

    pop ebx
    leave
    ret
