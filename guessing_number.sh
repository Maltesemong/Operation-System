#!/bin/bash
NUMBER="$(($RANDOM% 100+1))"
echo "Random number guessing game!" \
				"What do you think the number is?" \
				"(Guess from 1~100)"
while : 
do
		read INPUT_NUMBER
		if [ $INPUT_NUMBER -lt "$NUMBER" ]; then
					echo "smaller"
		elif [ $INPUT_NUMBER -gt "$NUMBER" ]; then
					echo "greater"
		elif [ $INPUT_NUMBER -eq "$NUMBER" ]; then
					echo "You guessed correct!"
					break
		else
					echo "You entered something wrong."
		fi
done

echo
echo "This is the end of the game!" \
				"Good bye!"
