# This program is identical to Palndrome.asm except theere is 
# an additional method CheckString which analyzes provided strings
# to see if a specific pattern is matched.

.data

printedMessage: .asciiz "The length of the string: "

#acceptable strings

String0:
.asciiz "a"
String1:
.asciiz "abba"
String2:
.asciiz "baab"
String3:
.asciiz "aabbbaaaabbbaa"

#unacceptable strings
String4:
.asciiz "aba"
String5:
.asciiz "babab"
String6:
.asciiz "aabbbaab"

Is:
.asciiz	" is acceptable.\r\n"
IsNot:
.asciiz	" is not acceptable.\r\n"


.text
la	$a0, String0
jal	CheckString
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String1
jal	CheckString
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String2
jal	CheckString
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String3
jal	CheckString
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String4
jal	CheckString
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String5
jal	CheckString
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String6
jal	CheckString
addi	$a1, $v0, 0
jal	WriteResult


addi	$v0, $0, 10
syscall

WriteResult:
addi	$sp, $sp, -8
sw	$a0, 0($sp)
sw	$v0, 4($sp)
addi	$v0, $0, 4
syscall
beq	$a1, $0, PrintNot
la	$a0, Is
syscall
j	WriteDone
PrintNot:
la	$a0, IsNot
syscall
WriteDone:
lw	$v0, 4($sp)
lw	$a0, 0($sp)
addi	$sp, $sp, 8

jr	$ra


#######################
# CheckString Method # ($t8 is a counter, $t9 checks for null terminator, $a1 walks through string)
######################
CheckString:
la $a1, ($a0) # load string into a1 so CheckPalindrome a0 register is not affected
la $t7, ($a1) # load string into t7

li $t8, 0 # initialize the count to zero

loop:
lb $t9, 0($a1) # load the next character into t9
add $a3, $t8, $zero # place t8 value in a3 so it is transferred to even_or_odd when beqz
beqz $t9, even_or_odd # check for the null character
addi $a1, $a1, 1 # increment the string pointer
addi $t8, $t8, 1 # increment the count
j loop # return to the top of the loop

even_or_odd:  # examines value in a3
beq $a3, 1, True
addi $t5, $zero, 2 # Get ready to divide by 2
div $a3, $t5       # divide the value by 2
mfhi $t5          # Save the remainder (if any)
beq $t5, $zero, CheckPalindrome # if the remainder is 0, the value is even!
j False
#j odd # else, jump to odd

#odd:
#j False



##########################
# CheckPalindrome Method # 
##########################
# $a0  string address
# $v0  result (1 = is a palindrome, 0 is not)

CheckPalindrome:
la $t1, ($a0)  # load string into t1
la $t2, ($a0)  # load identical string into t2

get_length:
lb $t3, ($t2) # Load bytes from t2 into fresh register t3
beqz $t3, end_of_string # if there are no more bytes, it's the end of the string
add $t2, $t2, 1 # advance t2 'pointer'
j get_length

end_of_string:
sub $t2, $t2, 1 # get t2 back to normal

Compare_Chars:
bge $t1, $t2, True # If t1 >= t2, then the entire string has been checked! Palindrome found :)
lb $t3, ($t1)
lb $t4, ($t2)
bne $t3, $t4, False # Compare 'pointers', if t3 != t4 then string is NOT a palindrome
                    # else...
add $t1, $t1, 1 # advance left 'pointer'
sub $t2, $t2, 1 # decrement right 'pointer'
j Compare_Chars

True:
addi $v0, $0, 1 # Put 1 into $v0.  1 = palindrome
jr $ra          # return the result

False:
addi $v0, $0, 0 # Put 0 into $v0.  0 = NOT palindrome
jr $ra          # return the result

