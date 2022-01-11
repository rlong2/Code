import art

alphabet = ['a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z']

def caesar(start_text, shift_amount, cipher_direction):
  end_text = ""
  if cipher_direction == "decode":
    shift_amount *= -1
  for char in start_text:
    if char in alphabet:
        position = alphabet.index(char)
        new_position = position + shift_amount
        end_text += alphabet[new_position]
    # Keep the number/symbol/space when the text is encoded/decoded
    else:
        end_text += char
    
  print(f"Here's the {cipher_direction}d result: {end_text}")

# Import and print the logo from art.py when the program starts.
print(art.logo)

play_again = True
while play_again:
    direction = input("Type 'encode' to encrypt, type 'decode' to decrypt:\n")
    text = input("Type your message:\n").lower()
    shift = int(input("Type the shift number:\n"))
    # The program continues to work even if the user enters a shift number greater than 26. 
    if shift > (len(alphabet) / 2):
        shift = int(shift % (len(alphabet) / 2))

    caesar(start_text=text, shift_amount=shift, cipher_direction=direction)
    play_again_choice = input("Type 'yes' if you want to go again. Otherwise type 'no':\n").lower()
    if play_again_choice.startswith('y'):
        play_again = True
    else:
        print("Thanks for using the program!")
        play_again = False