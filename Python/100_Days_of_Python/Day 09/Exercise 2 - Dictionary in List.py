'''
You are going to write a program that adds to a travel_log. 
You can see a travel_log which is a List that contains 2 Dictionaries.

Write a function that will work with the following line of code on line 21 
to add the entry for Russia to the travel_log.
'''

travel_log = [
{
  "country": "France",
  "visits": 12,
  "cities": ["Paris", "Lille", "Dijon"]
},
{
  "country": "Germany",
  "visits": 5,
  "cities": ["Berlin", "Hamburg", "Stuttgart"]
},
]
#🚨 Do NOT change the code above

#TODO: Write the function that will allow new countries
#to be added to the travel_log. 👇
def add_new_country(country, visits, cities):
    #travel_log.append(country, visits, cities)
    #travel_log.append(country)

#🚨 Do not change the code below
add_new_country("Russia", 2, ["Moscow", "Saint Petersburg"])
print(travel_log)