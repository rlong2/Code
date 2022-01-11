#Password Generator Project
import random
letters = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z']
numbers = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
symbols = ['!', '#', '$', '%', '&', '(', ')', '*', '+']

print("Welcome to the PyPassword Generator!")
nr_letters= int(input("How many letters would you like in your password?\n")) 
nr_symbols = int(input(f"How many symbols would you like?\n"))
nr_numbers = int(input(f"How many numbers would you like?\n"))

# generate x number of random letters, symbols, and numbers
random_letters = random.choices(letters, k = nr_letters)
random_symbols = random.choices(symbols, k = nr_symbols)
random_numbers = random.choices(numbers, k = nr_numbers)

letter_string = symbol_string = number_string = ""

# Create strings
for lett in random_letters:
    letter_string += lett
for symb in random_symbols:
    symbol_string += symb
for num in random_numbers:
    number_string += num

# Create password from letter, symbol, and number strings
password = letter_string + symbol_string + number_string
scrambled_password = ''.join(random.sample(password,len(password)))
print(scrambled_password)