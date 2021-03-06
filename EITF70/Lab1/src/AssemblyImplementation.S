/*.global readSwitches_writeLed_Assembly
.text
.ent readSwitches_writeLed_Assembly

readSwitches_writeLed_Assembly:
	lwi r11,r0, 0x40020000
	swi r11,r0, 0x40010000
	rtsd r15,8
	nop
.end readSwitches_writeLed_Assembly
*/

.global function
.text
.ent function
function:
			addi r1,r1,-4
			swi r15,r1,0
			lwi r5,r0, 0x40020000
			brlid r15, number_of_ones
			nop
			add r5,r3,r0
			brlid r15,translateN
			nop
			swi r3,r0,0x40010000
			lwi r15,r1,0
			addi r1,r1,4
			rtsd r15, 8
			nop
.end function


.global number_of_ones
.text
.ent number_of_ones
number_of_ones:
			add r3,r0,r0
while: 		beqid r5, result
			nop
			andi r4,r5,1
			add r3,r3,r4
			sra r5,r5
			brid while
			nop
result: 	rtsd r15, 8
			nop
.end number_of_ones

.global translateN
.text
.ent translateN
translateN:
			addi r3,r0,1
again: 		beqid r5, done
			nop
			addi r5,r5,-1
			add r3,r3,r3
			brid again
			nop
done: 		addi r3,r3,-1
			rtsd r15, 8
			nop
.end translateN


.global process_switches
.text
.ent process_switches
process_switches:
			addi r1,r1,-4
			sw r15,r1,r0
			lwi r6,r0, 0x40020000
			add r5,r0,r0
			addi r7,r0,8
			addi r10,r0,1
shift:	 	beqi r7, arg_ready
			nop
			andi r9, r6,1
			add r5,r5,r5
			add r5,r5,r9
			sra r6,r6
			rsub r7,r10,r7
			brid shift
			nop
arg_ready: 	brlid r15, number_of_ones
			nop
			add r7,r3,r0
			add r5,r6,r0
			brlid r15, first_position_of_one
			nop
			add r6,r3,r0
			add r5,r7,r0
			brlid r15, display_value_at_index
			nop
			lw r15,r1,r0
			addi r1,r1,4
			rtsd r15, 8
			nop
.end process_switches

.global first_position_of_one
.text
.ent first_position_of_one
first_position_of_one:
			add r3,r0,r0
			beqi r5, found
			nop
next: 		andi r4,r5,1
			bneid r4, found
			nop
			addi r3,r3,1
			sra r5,r5
			brid next
			nop
found: 		rtsd r15,8
			nop
.end first_position_of_one

.global display_value_at_index
.text
.ent display_value_at_index
display_value_at_index:
			add r7,r5,r5
			add r7,r7,r7
			add r8,r6,r6
			add r8,r8,r8
			addi r9,r0,7
			addi r10,r0,0x44A00000
			addi r11,r0,1
reset_display: add r12, r9,r9
			add r12,r12,r12
			sw r0,r10,r12
			rsub r9,r11,r9
			bgeid r9, reset_display
			nop
			lwi r9,r7,display_codes
			sw r9, r10, r8
			rtsd r15, 8
			nop
.end display_value_at_index

.global switches_battle
.text
.ent switches_battle
switches_battle:
			lwi r6,r0,0x40020000
			add r5,r0,r0
			addi r7,r0,8
			andi r5,r6,0xFF
shiftright: beqid r7, compared
			nop
			sra r6,r6
			addi r7,r7,-1
			brid shiftright
			nop
compared:	cmp r18,r5,r6
			bgei r18, leftwon
			swi r0,r0,0x40010000
			bri finish
leftwon:	addi r11,r0,0xffff
			swi r11,r0,0x40010000
finish:		rtsd r15,8
			nop
.end switches_battle


.global switches_matcher
.text
.ent switches_matcher
switches_matcher:
			addi r1,r1,-32
			sw r15,r1,r0
			lwi r6,r0, 0x40020000
			add r5,r0,r0
			add r8,r0,r0
			addi r7,r0,8
			addi r10,r0,1
			andi r9,r6,0xFF
			add r5,r5,r9
right:		beqid r7, compare
			nop
			sra r6,r6
			rsub r7,r10,r7
			brid right
			nop
compare:	xor r8,r5,r6
			xori r8,r8,255
initshift:	addi r7,r0,8
			add r9,r0,r0
secshift:	beqi r7, finished
			andi r5,r8,1
			add r6,r0,r9
			swi r5,r1,4
			swi	r6,r1,8
			swi	r7,r1,12
			swi r8,r1,16
			swi r9,r1,20
			brlid r15, display_value_at_index_two
			nop
			addi r10,r0,1
			lwi r5,r1,4
			lwi r6,r1,8
			lwi r7,r1,12
			lwi r8,r1,16
			lwi r9,r1,20
			sra r8,r8
			addi r7,r7,-1
			add r9,r9,r10
			brid secshift
			nop
finished:	lw r15,r1,r0
			addi r1,r1,32
			rtsd r15,8
			nop
.end switches_matcher

.global display_value_at_index_two
.text
.ent display_value_at_index_two
display_value_at_index_two:
			add r7,r5,r5
			add r7,r7,r7
			add r8,r6,r6
			add r8,r8,r8
			addi r10,r0,0x44A00000
			lwi r9,r7,display_codes
			sw r9, r10, r8
			rtsd r15, 8
			nop
.end display_value_at_index_two

.global count_switches
.text
.ent count_switches
count_switches:
			addi r1,r1,-8
			swi r15,r1,0
			lwi r5,r0, 0x40020000
			brlid r15, number_of_ones
			nop
			add r5,r3,r0
			addi r3,r0,10
			cmp r18,r3,r5
			bgeid r18, greater
			nop
			add r6,r0,r0
			brlid r15, display_value_at_index
			nop
			brid doner
			nop
greater:	addi r5,r5,-10
			swi r5,r1,4
			addi r5,r0,1
			addi r6,r0,1
			brlid r15, display_value_at_index_two
			nop
			lwi r5,r1,4
			add r6,r0,r0
			brlid r15, display_value_at_index_two
			nop
doner:		lwi r15,r1,0
			addi r1,r1,8
			rtsd r15, 8
			nop
.end count_switches

