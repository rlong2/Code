# This program finds phone numbers in a text string

import re

message = 'Call me at 333-532-4594 tomorrow or at 332-553-2242'

# passing a raw string with r ignores \, etc
# 3 digits, -, 3 digits, -, 4 digits
# This is grouped with () and can be called with foo.group(n)
phoneNumRegex = re.compile(r'(\d\d\d)-(\d\d\d-\d\d\d\d)')

# matched object. search or findall methods are nice
# mo = phoneNumRegex.findall(message)
mo = phoneNumRegex.search(message)


# get actual text
print(mo)

# print only the area code using groups () () ()
print(mo.group(1))
print(mo.group(2))


#####################

batRegex = re.compile(r'Bat(man|person|mobile|copter|bat)')
mo = batRegex.search('Batmobile lost a wheel')
print(mo)

############

# Match a certian number of repetitions
# '?' appears 1 or 0 times
batRegex = re.compile(r'Bat(wo)?man')
mo = batRegex.search('The adventures of Batwoman')
print(mo)
mo = batRegex.search('The adventures of Batman')
print(mo)
mo = batRegex.search('The adventures of Batwowoman')
print(mo)

############
# phone numbers: we can make area code optional: 443-8273 or 303-443-8273
phoneRegex = re.compile(r'(\d\d\d-)?\d\d\d-\d\d\d\d')
mo = phoneRegex.search('my num is 883-8837 or 303-883-8762, cool')
print(mo)

########
# Match exactly {n} times or sliced {n,n}, {:n}, {n:}
haRegex = re.compile(r'(Ha){3}')
mo = haRegex.search('HaHaHa')
print(mo)
mo = haRegex.search('HaHa')
print(mo)

## Match 3-5 digits
# Python does greedy match, finds longest possible string
digitRegex = re.compile(r'(\d){3,5}')
print(digitRegex.search('1234567890'))
#<re.Match object; span=(0, 5), match='12345'>

# ? prompts for nongreedy match
digitRegex = re.compile(r'(\d){3,5}?')
print(digitRegex.search('1234567890'))
#<re.Match object; span=(0, 3), match='123'>

