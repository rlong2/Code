A = [2,8,5,3,9,4]
for i in range(len(A)):
    pointer = A[i]
    left = A[i-1]
    print(f"Array: {A}")
    while i > 0 and left > pointer:
        print(f" Swapping {pointer} & {left}")
        A[i], A[i-1] = left, pointer
        pointer, left = A[i-1], A[i-2]
        i -= 1
    else: print(f" Done")
else: print(f"Results: {A}")
