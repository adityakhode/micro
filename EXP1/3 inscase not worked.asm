ORG 0000H

MOV DPTR, #0020H   ; Set DPTR to the base address of the string
MOV R0, #50H       ; Set R0 to the length of the string
MOV R1, #06H       ; Set R1 to the midpoint of the string
CLR A              ; Clear accumulator

; Find the length of the string
L1:
    CLR A
    MOVC A, @A+DPTR
    INC DPTR
    INC R1
    DJNZ R0, L1

    ; Move DPTR back to the start of the string
    MOV DPTR, #0020H

    ; Reverse the string using a stack
    L2:
        CLR A
        MOVC A, @A+DPTR
        PUSH ACC
        INC DPTR
        DEC R1
        DJNZ R0, L2

        ; Move DPTR back to the start of the string
        MOV DPTR, #0020H

        L3:
            POP ACC
            MOV @DPTR, A
            INC DPTR
            DEC R1
            DJNZ R0, L3

ORG 0020H
DB 'MODERN'
END
