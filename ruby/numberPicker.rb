# This program asks a user to pick a random number

randomNum = (rand(10) + 1).to_i						# Generate a number 1 through 10 
userNum = 0

while userNum != randomNum
	print "Guess a number, 1 through 10: "
	userNum = gets.to_i

	if userNum == randomNum
    	puts "You guessed the right number!"
	elsif userNum < randomNum
    	puts "Guess higher"
	else
   		puts "Guess lower"
	end

end
