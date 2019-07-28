########
# DATA #
########
.data

myString0: .asciiz "finally working"
myString1: .asciiz "racecar radar racecar"

String0: .asciiz ""
String1: .asciiz "a"
String2: .asciiz "b"
String3: .asciiz "aba"
String4: .asciiz "abba"
String5: .asciiz "baab"
String6: .asciiz "ababa"
String7: .asciiz "aabba"
String8: .asciiz "abbab"

Is: .asciiz	" is a palindrome.\r\n"
IsNot: .asciiz	" is not a palindrome.\r\n"


########
# TEXT #
########
.text

la	$a0, String0
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String1
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String2
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String3
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String4
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String5
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String6
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String7
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, String8
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

# Custom string check
la	$a0, myString0
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

la	$a0, myString1
jal	CheckPalindrome
addi	$a1, $v0, 0
jal	WriteResult

# Kill main
addi	$v0, $0, 10
syscall     


######################
# WriteResult Method #
######################
WriteResult:
addi	$sp, $sp, -8
sw	$a0, 0($sp)
sw	$v0, 4($sp)
addi	$v0, $0, 4
syscall
beq	$a1, $0, PrintNot # if $a1 holds 0, print NOT
la	$a0, Is           # else, print IS
syscall 
j	WriteDone

###################
# PrintNot Method #
###################
PrintNot:
la	$a0, IsNot
syscall

####################
# WriteDone Method #
####################
WriteDone:
lw	$v0, 4($sp)
lw	$a0, 0($sp)
addi	$sp, $sp, 8

jr	$ra


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
