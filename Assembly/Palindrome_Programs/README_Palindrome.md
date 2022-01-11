This is an in-depth explanation of how Palindrome.asm works.

Palindrome.asm checks strings to see if they are palindromes.
When the program is run, boilerplate code collects strings and sends them 
to the CheckPalindrome method, which sends a 0 or 1 to $v0, 
where the boilerplate code resumes and says if the string is a palindrome or not. 

The CheckPalindrome method loads the string into the t1 and t2 registers.  
The get_length loop loads the bytes from t2 into t3, essentially counting the characters in the string.  
When there are no more bytes to count, the Compare_Chars loop looks at the string, 1 character/byte at a time.  
The characters in t1 are examined from the 1st character and advance right, 
and the characters in t2 are examined from the last character and advance left.  
On each pass of the loop, the two characters are compared.  
If the examined characters are not equal at any point, the program jumps to the False method, 
which returns $v0 set to 0.   If the compared characters are equal, 
the loop continues until the t1 counter is greater or equal to the t2 counter, 
meaning that the entire string has been examined and the string is a palindrome.  
The program then jumps to True, which returns $v0 set to 1.
