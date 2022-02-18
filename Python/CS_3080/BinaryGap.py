'''
A binary gap within a positive integer N is any maximal sequence of consecutive zeros
that is surrounded by ones at both ends in the binary representation of N.
For example, number 9 has binary representation 1001 and contains a binary gap of length 2.
The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3.
The number 20 has binary representation 10100 and contains one binary gap of length 1.
The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

    def solution(N)

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.
'''


def solution(N):
    # Convert the decimal to a binary string
    num_string = "{0:b}".format(int(N)) 

    counting = False
    gap = 0
    max_gap = 0
    
    # Loop through chars
    # Example string: 111001000011010
    for char in num_string:
        # If char is 1 and haven't started couting, start the count
        if char == '1' and counting == False:
            counting = True

        # If char is 0 and counting, add to count
        if char == '0' and counting == True:
            gap += 1

        # If counting and reach a 1, the gap is finished.
        if char == '1' and counting == True:
            # Compare the gap count to the maximum gap count, get the max gap
            max_gap = max(max_gap, gap)
            # Reset gap back to 0 to start again
            gap = 0
    print(f"{N} converted to binary {num_string} has a max gap of {max_gap}")    
    return max_gap

solution(29210)
solution(1078)
solution(5033)
solution(4)

