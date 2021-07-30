#include "lcddraw.h"	
#include "switches.h"
#include "lcdutils.h"
#include "stateMachines.h"
#include "buzzer.h"

	.arch msp430g2553
	.p2align 1,0
	.text
	.global state_advance
	.extern move_shape_Left
	.extern move_shape_Right
	.extern clearScreen
	
	.data
	.global state
	.global stopCPU
	
state:
	.word 0
	
stopCPU:
	.word 0

jt:
	.word case_1
	.word case_2
	.word case_3
	.word case_4
	.word end

state_advance:
	mov &state, r12		;MOVES STATE INTO REGISTER 12
	add r12, r12		;DOUBLE FOR WORDS IN SEQUENCE
	mov jt(r12), r0		;INDEXES JT TABLE IN REGISTER 0
case_1:
	mov #0, &stopCPU        ;MOVES SHAPE LEFT
	mov #6, r12
	call #move_shape_Left
	jmp end
case_2:
	mov #0, &stopCPU	;MOVES SHAPE RIGHT
	mov #6, r12
	call #move_shape_Right
	jmp end
case_3:
	mov #0, &stopCPU	;CLEARS SCREEN TO GREEN
	mov 0xff00, r12
	call #clearScreen
	jmp end
case_4:
	mov #1, &stopCPU	;STOPS CPU TURNS SCREEN RED
	mov 0x001f, r12
	call #clearScreen
	jmp end
end:
	pop r0
