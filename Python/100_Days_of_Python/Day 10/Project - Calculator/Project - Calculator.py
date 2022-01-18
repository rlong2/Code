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
 "-": subtract
 "*": multiply
 "/": divide
}