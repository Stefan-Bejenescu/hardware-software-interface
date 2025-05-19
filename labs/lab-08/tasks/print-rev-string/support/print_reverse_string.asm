section .data
    store_string times 64 db 0

section .text
extern printf
extern puts
global print_reverse_string

reverse_string:
    push ebp
    mov ebp, esp
    push ebx

    mov eax, [ebp + 8]
    mov ecx, [ebp + 12]
    mov edx, [ebp + 16]

    test ecx, ecx
    jz done_reversing

    add eax, ecx
    dec eax

reverse_loop:
    mov bl, [eax]
    mov [edx], bl
    dec eax
    inc edx
    loop reverse_loop

done_reversing:
    mov byte [edx], 0

    pop ebx
    leave
    ret

print_reverse_string:
    push ebp
    mov ebp, esp
    push ebx

    mov eax, [ebp + 8]
    mov ecx, [ebp + 12]

    push store_string
    push ecx
    push eax
    call reverse_string
    add esp, 12

    push store_string
    call puts
    add esp, 4

    pop ebx
    leave
    ret