# My first ruby program
# 
# 1. Print "Hello World"
# 2. Find the index of "Ruby" in string "Hello, Ruby,"
# 3. Print your name 10 times
# 4. Print string "This is sentence #1" where 1 changes from 1 to 10

puts "Hello World!"

myString = "Hello, Ruby,"
puts myString[7] + myString[8] + myString[9] + myString[10]

puts myString.index('Ruby')

i = 0
while i < 10 
  puts 'Ryan'
  i = i + 1
end

i = 1
while i <= 10
  puts "This is sentence number " + i.to_s
  i = i + 1
end
