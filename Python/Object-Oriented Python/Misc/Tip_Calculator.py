# Tip calculator
# Will build a GUI

def AddTip(price_without_tip):
    tip_amounts = [10, 15, 20]
    for tip in tip_amounts:
        new_total = price_without_tip + (price_without_tip * (tip / 100))
        formatted_total = "{:.2f}".format(new_total)
        print(f"{tip}% tip: total is ${formatted_total}")

# Main
price_without_tip = float(input("Enter your total cost: $"))
AddTip(price_without_tip)

      
