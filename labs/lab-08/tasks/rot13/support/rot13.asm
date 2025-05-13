section .text
global rot13

rot13:
    push ebp
    mov ebp, esp
    push ebx                ; preserve ebx as required by cdecl

    ; TODO

    mov esi, [ebp + 8]
    mov ecx, [ebp + 12]

loop:
    cmp ecx, 0
    je done

    mov al, [esi]
    cmp al, 0
    je handle_null

    cmp al, 'a'
    jl check_upper
    cmp al, 'z'
    jg check_upper

    sub al, 'a'
    add al, 13
    cmp al, 26
    jl lower_store
    sub al, 26

lower_store:
    add al, 'a'
    mov [esi], al
    jmp next

check_upper:
    cmp al, 'A'
    jl next
    cmp al, 'Z'
    jg next

    sub al, 'A'
    add al, 13
    cmp al, 26
    jl upper_store
    sub al, 26

upper_store:
    add al, 'A'
    mov [esi], al

next:
    inc esi
    dec ecx
    jmp loop

handle_null:
    cmp byte [esi + 1], 0
    je done
    mov byte [esi], ' '
    inc esi
    jmp loop

done:
    pop ebx
    leave
    ret
