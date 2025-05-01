; =============================================
; TYPING TEST PROGRAM - ASSEMBLY LANGUAGE
; =============================================
; This program tests typing speed and accuracy by:
; 1. Displaying a random sentence to type
; 2. Timing how long it takes to type it
; 3. Calculating accuracy and words-per-minute (WPM)
;
; Registers used:
; AX - General purpose/arithmetic
; BX - Base register for memory addressing
; CX - Counter for loops
; DX - Data register for I/O
; SI - Source index
; DI - Destination index
; =============================================

.model small        ; Small memory model
.stack 100h         ; 256-byte stack

.data
    ; ========= SENTENCES DATABASE ===========
    ; 5 different sentences for typing test
    ; Each ends with CR, LF, and '$' terminator
    sentence1 db "The quick brown fox jumps over the lazy dog.",13,10,"$"
    sentence2 db "Programming requires logic, patience, and clear thinking.",13,10,"$"
    sentence3 db "Every expert was once a beginner keep on practicing.",13,10,"$"
    sentence4 db "Mastering the keyboard takes time, effort, and focus.",13,10,"$"
    sentence5 db "Typing accuracy is more important than speed at first.",13,10,"$"
    
    ; Array of pointers to each sentence
    sentences dw offset sentence1, offset sentence2, offset sentence3, offset sentence4, offset sentence5
    
    ; Lengths of each sentence (without CR/LF/$)
    sentenceLengths dw 44, 78, 65, 85, 75
    
    ; Variables to store current test sentence
    currentSentence dw ?    ; Pointer to selected sentence
    currentLength dw ?      ; Length of selected sentence
    
    ; ========== USER INTERFACE MESSAGES ==========
    prompt db 13,10,"Type the following sentence:",13,10,"$"
    resultMsg db 13,10,"Results:",13,10,"$"
    charsTypedMsg db "Characters typed: $"
    correctCharsMsg db 13,10,"Correct characters: $"
    accuracyMsg db 13,10,"Accuracy: $"
    wpmMsg db 13,10,"Typing Speed: $"
    wpmSuffix db " WPM$"
    percentMsg db "%$"
    newline db 13,10,"$"

    ; ========== TYPING TEST VARIABLES ==========
    inputBuffer db 100 dup(0)   ; Stores user's typed characters
    typedChars dw 0             ; Count of total characters typed
    correctChars dw 0           ; Count of correctly typed characters
    
    ; Timing variables (using BIOS ticks at 18.2 ticks/second)
    startTime dw ?              ; When typing started
    endTime dw ?                ; When typing finished
    secondsTaken dw ?           ; Total time taken in seconds

.code
main proc
    ; Initialize data segment
    mov ax, @data
    mov ds, ax

    ; ===== RANDOM SENTENCE SELECTION =====
    ; Uses BIOS time (in CX:DX) as simple random seed
    mov ah, 00h         ; BIOS get system time function
    int 1Ah             ; Returns ticks in CX:DX
    mov ax, dx          ; Use lower part for random number
    
    ; Calculate random index (0-4) using modulo 5
    xor dx, dx          ; Clear DX for division
    mov bx, 5           ; We have 5 sentences
    div bx              ; Divide AX by 5, remainder in DX
    mov bx, dx          ; Remainder (0-4) is our random index
    
    ; Get pointer to selected sentence
    shl bx, 1           ; Multiply index by 2 (since pointers are words)
    mov si, offset sentences
    add si, bx
    mov ax, [si]        ; Get address of selected sentence
    mov currentSentence, ax
    
    ; Get length of selected sentence
    mov si, offset sentenceLengths
    add si, bx
    mov ax, [si]
    mov currentLength, ax

    ; ===== DISPLAY TEST INSTRUCTIONS =====
    mov ah, 09h         ; DOS string output function
    lea dx, prompt      ; Show typing prompt ;load effect address
    int 21h
    mov dx, currentSentence ; Display selected sentence
    int 21h

    ; ===== RECORD START TIME =====
    ; Using BIOS timer ticks (18.2 ticks per second)
    mov ah, 00h
    int 1Ah
    mov startTime, dx

    ; ===== TYPING INPUT LOOP =====
    lea si, inputBuffer ; SI points to input buffer
    mov di, currentSentence ; DI points to correct sentence
    xor cx, cx          ; CX will count typed characters
    
read_loop:
    ; Get single character input
    mov ah, 01h         ; DOS character input function
    int 21h
    
    ; Check for Enter key (end of input)
    cmp al, 13
    je done_input
    
    ; Store character and increment counters
    mov [si], al        ; Save typed character
    inc si              ; Move buffer pointer
    inc cx              ; Increment character count
    
    ; Check if character matches original (only up to sentence length)
    cmp cx, currentLength
    ja skip_compare     ; Skip if beyond sentence length
    
    cmp al, [di]        ; Compare with correct character
    jne skip_compare    ; Skip if no match
    inc correctChars    ; Increment correct character count
    
skip_compare:
    inc di              ; Move to next character in sentence
    jmp read_loop       ; Continue typing loop

done_input:
    ; Save total characters typed
    mov typedChars, cx

    ; ===== RECORD END TIME =====
    mov ah, 00h
    int 1Ah
    mov endTime, dx

    ; ===== CALCULATE TIME TAKEN =====
    mov ax, endTime
    sub ax, startTime   ; AX = end - start ticks
    
    ; Handle midnight crossing (if end < start)
    jnc time_ok
    add ax, 18*60       ; Add ticks for 1 minute (18.2*60)
    
time_ok:
    ; Convert ticks to seconds (ticks/18)
    mov bx, 18
    xor dx, dx
    div bx
    mov secondsTaken, ax

    ; ===== DISPLAY RESULTS =====
    call DisplayResults

    ; Exit to DOS
    mov ah, 4Ch
    int 21h
main endp

; =============================================
; DISPLAY RESULTS PROCEDURE
; Shows all test results:
; - Characters typed
; - Correct characters
; - Accuracy percentage
; - Typing speed (WPM)
; =============================================
DisplayResults proc
    ; Show results header
    mov ah, 09h
    lea dx, resultMsg
    int 21h

    ; Show total characters typed
    mov ah, 09h
    lea dx, charsTypedMsg
    int 21h
    mov ax, typedChars
    call PrintNumber

    ; Show correct characters count
    mov ah, 09h
    lea dx, correctCharsMsg
    int 21h
    mov ax, correctChars
    call PrintNumber

    ; Calculate and display accuracy percentage
    call CalculateAccuracy

    ; Calculate and display words-per-minute
    call CalculateWPM
    ret
DisplayResults endp

; =============================================
; CALCULATE ACCURACY PROCEDURE
; Formula: (correctChars / typedChars) * 100
; Handles division by zero case
; =============================================
CalculateAccuracy proc
    mov ah, 09h
    lea dx, accuracyMsg
    int 21h

    mov ax, correctChars
    mov bx, typedChars
    cmp bx, 0
    je zero_accuracy    ; Avoid division by zero

    ; Calculate percentage: (correctChars * 100) / typedChars
    mov cx, 100
    mul cx              ; AX = correctChars * 100
    div bx              ; AX = AX / typedChars
    call PrintNumber
    jmp show_percent

zero_accuracy:
    mov ax, 0           ; If nothing typed, show 0%
    call PrintNumber

show_percent:
    mov ah, 09h
    lea dx, percentMsg
    int 21h
    ret
CalculateAccuracy endp

; =============================================
; CALCULATE WPM PROCEDURE
; Standard WPM formula: 
; (correctChars / 5) / (secondsTaken / 60)
; Simplified to: (correctChars * 12) / secondsTaken
; =============================================
CalculateWPM proc
    ; Show WPM label
    mov ah, 09h
    lea dx, wpmMsg
    int 21h

    ; Handle division by zero case
    mov ax, secondsTaken
    cmp ax, 0
    jne calculate_wpm
    mov ax, 1           ; Use 1 second if zero to avoid error

calculate_wpm:
    mov bx, ax          ; BX = secondsTaken
    mov ax, correctChars
    mov cx, 12          ; 60/5 = 12 (for simplified formula)
    mul cx              ; AX = correctChars * 12
    xor dx, dx
    div bx              ; AX = WPM result

    ; Display WPM value
    call PrintNumber
    mov ah, 09h
    lea dx, wpmSuffix
    int 21h
    ret
CalculateWPM endp

; =============================================
; PRINT NUMBER PROCEDURE
; Displays the unsigned word in AX as decimal
; Works by pushing digits then popping to display
; =============================================
PrintNumber proc
    push ax
    push bx
    push cx
    push dx
    xor cx, cx          ; CX will count digits
    mov bx, 10          ; Base 10 for decimal
    
next_digit:
    xor dx, dx          ; Clear upper word for division
    div bx              ; AX = AX/10, DX = remainder
    push dx             ; Save digit (0-9)
    inc cx              ; Count digits
    test ax, ax         ; Check if quotient is zero
    jnz next_digit      ; Continue if not zero

print_loop:
    pop dx              ; Get next digit
    add dl, '0'         ; Convert to ASCII
    mov ah, 02h         ; DOS character output
    int 21h
    loop print_loop     ; Repeat for all digits
    
    pop dx
    pop cx
    pop bx
    pop ax
    ret
PrintNumber endp

end main