from replit import clear # HINT: You can call clear() to clear the output in the console.
import art

# Print ascii art and intoduction
print(art.logo)
print("Welcome to the secret auction program.")

# Main
# Get player names and bids.
bid_list = {} # An empty dictionary to hold bids

while True:
    name = input("What is your name?: ")
    bid = int(input("What is your bid?: $"))
    bid_list.update({name: bid})

    more_bidders = input("Any other bidders? Enter yes or no. ")
    if more_bidders.lower().startswith('y'):
        # Continue loop to add bidders, clearing the screen each time.
        clear()
    else:
        # Auction over, find the bidder with the highest bid
        highest_bid = 0
        highest_bidder = "default"
        for entry in bid_list:
            print(entry, bid_list[entry])
            if bid_list[entry] > highest_bid:
                highest_bid = bid_list[entry]
                highest_bidder = entry
        break

print(f"The winnder is {highest_bidder} with a bid of ${highest_bid}.")
