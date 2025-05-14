; SPDX-License-Identifier: BSD-3-Clause

%include "printf32.asm"

extern printf

section .bss:
	; the structure for a student
	struc student_t
		name:   resb	10	; char[10] - student name
		id_course:	resd	1	; integer - the id of the course where a student is assigned
		check:	resd	1	; "bool" - check if the student is assigned to any course
	endstruc

    ; the structure for a course
	struc course_t
		id:	resd	1	; id = index in courses (the list of courses)
		name_course:   resb	15	; char[10] - the name of the course
	endstruc

section .data
    unassigned:		db "Student unassigned :(", 0
	v_students_count:    dd 5
    v_courses_count:    dd 3

    students:
		istruc student_t
			at name,	db "Vlad", 0
			at id_course,		dd 0
			at check,	dd 1
		iend

		istruc student_t
			at name,	db "Andrew", 0
			at id_course,		dd 1
			at check,	dd 1
		iend

		istruc student_t
			at name,	db "Kim", 0
			at id_course,		dd 1
			at check,	dd 1
		iend

		istruc student_t
			at name,	db "George", 0
			at id_course,		dd 2
			at check,	dd 1
		iend

		istruc student_t
			at name,	db "Kate", 0
			at id_course,		dd 0
			at check,	dd 0
		iend

    courses:
		istruc course_t
			at id,	dd 0
			at name_course,	db "Assembly", 0
		iend

		istruc course_t
			at id,	dd 1
			at name_course,	db "Linear Algebra", 0
		iend

		istruc course_t
			at id,   dd 2
			at name_course,	db "Physics", 0
		iend

section .text
global main

main:
	push ebp
	mov ebp, esp
	PRINTF32 `The students list is:\n\x0`
	; TODO: Print the list of students and the courses where they are assigned
	xor ecx, ecx

final_print:
	mov ebx, students
	mov edx, ecx
	imul edx, student_t_size
	add ebx, edx
	mov eax, ebx
	add ebx, name
	PRINTF32 `%s ----\x0`, ebx

	mov ebx, eax
	add ebx, check
	mov ebx, [ebx]
	cmp ebx, 0
	jne next
	PRINTF32 ` %s\n\x0`, unassigned
	jmp end

next:
	mov ebx, eax
	add ebx, id_course
	mov ebx, [ebx]
	mov esi, courses
	imul ebx, course_t_size
	add esi, ebx
	add esi, name_course
	PRINTF32 ` %s\n\x0`, esi

end:
	inc ecx
	cmp ecx, [v_students_count]
	jl final_print

    leave
    ret
