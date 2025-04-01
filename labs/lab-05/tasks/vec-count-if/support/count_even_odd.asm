%include "printf32.asm"

%define ARRAY_SIZE 10

section .data
    dword_array dd 1392, 12544, 7991, 6992, 7202, 27187, 28789, 17897, 12988, 17992

section .text
extern printf
global main
main:
    mov ecx, ARRAY_SIZE
    xor esi, esi
    xor edi, edi
next:
    xor edx, edx
    mov eax, dword [dword_array + 4 * ecx - 4]
    mov ebx, 2
    div ebx

    test edx, edx
    jne inc_odd
    inc edi
    jmp check
inc_odd:
    inc esi
check:
    loop next

    PRINTF32 `Num odd is %u, num even is %d\n\x0`, edi, esi

    ret