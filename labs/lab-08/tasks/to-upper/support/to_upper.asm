section .text

global to_upper

to_upper:
    push ebp
    mov ebp, esp
    push ebx                ; preserve ebx as required by cdecl

    ; TODO
    mov esi, [ebp + 8]

check_lower:
    mov al, [esi]
    cmp al, 'a'
    jl next
    cmp al, 'z'
    jg next

convert_byte:
    sub al, 0x20
    mov [esi], al

next:
    inc esi
    cmp byte [esi], 0
    je done
    jmp check_lower

done:
    pop ebx
    leave
    ret
