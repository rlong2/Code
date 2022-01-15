#from replit import clear # HINT: You can call clear() to clear the output in the console.
import art

# Print ascii art and intoduction
#print(art.logo)
print("Welcome to the secret auction program.")

# Function to add name of bidder and bid amount to a list
def addBidToList(name, bid):
    new_bid = {}
    new_bid["name"] = name
    new_bid["bid"] = bid
    bid_list.append(new_bid)

# Function to find the highest bid from the list
def getHighestBid(bid_list):
    highest_bid = 0
    for dictionary in bid_list:
        for entry in dictionary:
            if dictionary[entry] > highest_bid:
                highest_bid = dictionary[entry]
    print(f"Highest bid is {highest_bid}")
    
# Get player names and bids
# If there are multiple bidders, clear the screen
# and reprompt for each name and bid.
bid_list = [] # An empty list of dictionaries

while True:
    name = input("What is your name?: ")
    bid = int(input("What is your bid?: $"))
    addBidToList(name, bid)

    more_bidders = input("Any other bidders? Enter yes or no. ")
    if more_bidders.lower().startswith('y'):
        # Continue loop to add bidders
        pass
    else:
        # Get highest bid and name of bidder
        getHighestBid(bid_list)
        break

#print(f"The winnder is {name} with a bid of ${bid}.")
