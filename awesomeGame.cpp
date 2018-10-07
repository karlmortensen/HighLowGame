#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int getRandomNumber()
{
	return (rand() % 100) + 1; 					// Returns a random integer between 1 and 100, inclusive.
}

// If we are supposed to be honest, return true, otherwise false
bool shouldBeHonest()
{
	int result = rand() %8;
	// printf("result is %d\n", result);
	return result; 							// Returns true or false
}

int main()
{
	string name; 						 		// Will store the person's name
	string response; 							// Will store the person's response
	int guess = -1; 							// Will store the person's integer version of their response
	int numberOfGuesses = 0; 					// Shows how many guesses they made
	int lies = 0;
	int mindChanges = 0;
	srand((unsigned)time(0)); 					// Start up the randomizer
	int targetNumber = getRandomNumber();		// Pick a random number

	// Get their name, and remember it.
	printf("Hello there. Please enter your name: ");
	getline(cin, name);
	printf("Alright %s, let's get ready to play.\n", name.c_str());
	

	// The main game starts here!
	while (guess != 0 && guess != targetNumber)
	{
		printf("Guess a number between 1 and 100, or enter 0 to exit: ");
		getline(cin, response);
		guess  = stoi(response);
		printf("You guessed %d\n", guess);	
		++numberOfGuesses;

		bool beHonest = shouldBeHonest();
		if (beHonest == false)
		{
			++lies;
		}
 
		if (guess != targetNumber || beHonest == false)
		{

			if (beHonest == true) // Computer must be honest
			{
				if (guess < targetNumber)
				{
					printf("Higher...\n");
				}
				else
				{
					printf("Lower...\n");
				}

			}

			else // Computer can lie, and cheat.
			{
				if (getRandomNumber() <= 10)  // Give it a 5% chance
				{
					// We're sick of this number.... pick a new one and don't tell the player! HA ha ha!
					targetNumber = getRandomNumber();
					++mindChanges;
					printf("Nope. And I'm not going to tell you what direction to go.\n");
				}
				else
				{
					if (guess > targetNumber)
					{
						printf("Higher...\n");
					}
					else
					{
						printf("Lower...\n");
					}
				}					
			}
		}

	}

	printf("My random number was %d and I lied to you %d times, and changed my mind about the number %d times. ", targetNumber, lies, mindChanges);
	
	if (guess != 0)
	{
		printf("You guessed it in %d guesses!\n", numberOfGuesses);
	}
	else 
	{
		printf("You guessed %d times, but then gave up.\n", numberOfGuesses);	
	}

	printf("Goodbye %s\n\n", name.c_str());
	return 0;
}

