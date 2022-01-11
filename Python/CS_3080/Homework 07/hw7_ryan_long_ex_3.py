'''
Homework 7, Exercise 3
I'm Feeling lucky Google
Ryan Long
11/28/2020

This program reads command line arguments and opens multiple results in tabs.

Results on my machine:
.\hw7_ryan_long_ex_3.py foo bar zar
Opening the first 3 results for 'foo bar zar'.....
Opening https://stackoverflow.com/questions/57547912/what-is-let-foobar-zar-in-rust<rest of URL trimmed>
Opening https://en.wikipedia.org/wiki/Metasyntactic_variable<rest of URL trimmed>
Opening https://en.wikipedia.org/wiki/Foobar<rest of URL trimmed>
'''

import requests, sys, webbrowser, bs4

num_tabs = 3                                    # Number of tabs to open
search_term = sys.argv[1:]                      # Search term arguments supplied
seperator = " "                                 # For neatly outputting search term
parse_string = "div#main > div > div > div > a" # String that parses valid URL content to append

# If no arguments are supplied, show the user an example
if len(search_term) == 0:
    print("Please supply a search term like so:"
          + "\npython3 hw7_ryan_long_ex_3.py foobar\n")
    sys.exit()

# Use the beautiful soup and webbrowser modules to construct valid URLs
else:
    res = requests.get("https://google.com/search?q=" + " ".join(search_term))
    res.raise_for_status()
                
    soup = bs4.BeautifulSoup(res.text, "html.parser")

    html_output = soup.select(parse_string)

    print("Opening the first " + str(num_tabs) + " results for '" + seperator.join(search_term) + "'.....\n")
    for i in range(num_tabs):
        link = html_output[i].get("href")
        
        print("Opening " + link[7:])                # Remove 'invalid' prepended chars to print an authentic URL (as a user would type it)
        webbrowser.open("http://google.com" + link) # Navigate to the URL through Google
        print("")
