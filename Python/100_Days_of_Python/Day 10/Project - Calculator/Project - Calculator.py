# Create a basic calculator

# Add
def add(n1, n2):
    return n1 + n2

# Subtract
def subtract(n1, n2):
    return n1 - n2

# Multiply
def multiply(n1, n2):
    return n1 * n2

# Divide
def divide(n1, n2):
    return n1 / n2

# Main
# Create a dictionary wirh the operations
operations = {
 "+": add,
 "-": subtract,
 "*": multiply,
 "/": divide
}

# Prompt the user for input
num1 = int(input("What's the first number?: "))
for symbol in operations:
    print(symbol)
operation_symbol = input("Pick an operation from the line above: ")
num2 = int(input("What's the second number?: "))

calculation_function = operations[operation_symbol]

# Call the appropriate function and store it (For example, add(3, 4), multiply(6, 7))
answer = calculation_function(num1, num2)   

print(f"{num1} {operation_symbol} {num2} = {answer}")
