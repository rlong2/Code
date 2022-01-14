from replit import clear # HINT: You can call clear() to clear the output in the console.
import art

# Print ascii art and intoduction
print(art.logo)
print("Welcome to the secret auction program.")

# TODO: Function to get highest bid


# Get player names and bids
# If there are multiple bidders, clear the screen
# and reprompt for each name and bid.
while True:
    name = input("What is your name?: ")
    bid = input("What is your bid?: $")
    more_bidders = input("Any other bidders? Enter yes or no. ")
    if more_bidders.lower().startswith('y'):
        clear()
    else:
        break

print(f"The winnder is {name} with a bid of ${bid}.")

# The winnder is <name> with a bid of $bid