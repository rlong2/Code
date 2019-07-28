# This program sorts a list of provided strings alphabetically

.data
String1:
.asciiz	"George\n"
String2:
.asciiz "Zachary\n"
String3:
.asciiz "Roberta\n"
String4:
.asciiz "Robert\n"
String5:
.asciiz "Amy\n"
nEntries:
.word 5
NameTable:
.space 20
cr:
.asciiz	"\n"
Note1:
.asciiz "Original List:\n"
Note2:
.asciiz "Sorted List:\n"

.text
jal	Initialize
addi	$v0, $0, 4	#print command
la	$a0, Note1
syscall

jal	PrintOut
addi	$v0, $0, 4	#print command
la	$a0, Note2
syscall
la	$a0, NameTable
la	$a1, nEntries
jal	Sort
jal	PrintOut
addi	$v0, $0, 10	#end the program
syscall

Initialize:
la	$t0, NameTable
la 	$t1, String1
sw	$t1, 0($t0)
la 	$t1, String2
sw	$t1, 4($t0)
la 	$t1, String3
sw	$t1, 8($t0)
la 	$t1, String4
sw	$t1, 12($t0)
la 	$t1, String5
sw	$t1, 16($t0)
jr 	$ra

PrintOut:
addi	$t0, $0, 0	#initialize counter
la	$t2, nEntries
lw	$t2, 0($t2)
la	$t1, NameTable
addi	$v0, $0, 4	#print command
Reprint:
lw	$a0, 0($t1)
syscall
addi	$t0, $t0, 1	#increment counter
addi	$t1, $t1, 4
bne	$t0, $t2, Reprint
addi	$v0, $0, 4	#print command
la	$a0, cr
syscall

jr	$ra

strcmp:
# your code here
#returns a negative number if string at $a1 is before string at $a0
#	$a0, $a1 location of strings to compare
#	$v0 compare result
jr	$ra

Sort:
# $a0 address of table to sort
# $a1 address of number of entries
# your code here
