# This program finds and replaces text
import re

namesRegex = re.compile(r'Agent \w+')
print(namesRegex.findall('Agent Alice gave secret docs to Agent Bob'))

# substitute method
print(namesRegex.sub(r'REDACTED','Agent Alice gave secret docs to Agent Bob'))

# Finds first char in Agent Foo
namesRegex = re.compile(r'Agent (\w)\w*')
# Use text from group 1 of the match, where (\w) is group 1
print(namesRegex.sub(r'Agent \1*****','Agent Alice gave secret docs to Agent Bob'))

### Verbose mode helps with readability
# Note the '''
phoneRegex = re.compile(r'''
(\d\d\d)-|      # area code w/parens and dash
(\(\d\d\d\) )|  # area code w/parens, no dash
\d\d\d|         # or area code w/no parens, no dash
\d\d\d-         # or area code w/no parens, no dash         
-               # first dash
\d\d\d          # first 3 digits
-               # second dash
\d\d\d\d        # last four digits
\sx\d{2,4}      # entension, like x1234
''', re.VERBOSE)
