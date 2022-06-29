
#include <cstdlib>
#include <cstring>
#include <conio.h>
#include<iostream>

using namespace std;

const int MAXLENGTH = 80;
const int MAX_TRIES = 5;
const int MAXROW = 7;

int letterFill(char, char[], char[]);
void initUnknown(char[], char[]);

int main()
{
	char unknown[MAXLENGTH];
	char letter;
	int num_of_wrong_guesses = 0;
	int i;
	char word[MAXLENGTH];
	char words[][MAXLENGTH] =
	{
		"india",
		"canada",
		"america",
		"malaysia",
		"philippines",
		"australia",
		"japan",
		"ethiopia",
		"thailand",
		"indonesia"
	};

	//choose and copy a word from array of words randomly
	int n = rand()%10;
	strcpy_s(word, words[n]);

	// Initialize the secret word with the * character.
	initUnknown(word, unknown);

	// welcome the user
	cout << "\n\n                       ...Welcome to Hangman Game...";
	cout << "\n\n\n\n\n Rules: ";
	cout << "\n\n You have to guess a country name.";
	cout << "\n\n Each letter is represented by a star.";
	cout << "\n\n You have to type only one letter in one try";
	cout << "\n\n You have " << MAX_TRIES << " tries to try and guess the word.";
	cout << "\n\n If you guessed the wrong letter then you will loose one try. ";
	cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	cout << "\n\n Press 1 to start the game : ";
	cin >> i;

	if (i == 1)
	{
		// Loop until the guesses are used up
		while (num_of_wrong_guesses < MAX_TRIES)
		{
			cout << "\n\n" << unknown;
			cout << "\n\nGuess a letter: ";
			cin >> letter;
			// Fill secret word with letter if the guess is correct,
			// otherwise increment the number of wrong guesses.
			if (letterFill(letter, word, unknown) == -1)
			{
				cout << "\nYou have already guessed this letter.";
			}
			else if (letterFill(letter, word, unknown) == 0)
			{
				cout << endl << "Whoops! That letter isn't in there!" << endl;
				num_of_wrong_guesses++;
				if (num_of_wrong_guesses == MAX_TRIES)
				{
					cout << "\nSorry, you lose...you've been hanged." << endl;
					cout << "The word was : " << word << endl;
				}
				else     // Tell user how many guesses has left.
					cout << "You have " << MAX_TRIES - num_of_wrong_guesses << " guesses left." << endl;
			}
			else
			{
				cout << endl << "You found a letter! Isn't that exciting!\n" << endl;
				if (strcmp(word, unknown) == 0)  	// Check if they guessed the word.
				{
					cout << word << endl;
					cout << "Yeah! You got it!\n\n\n";
					break;
				}
				else   // Tell user how many guesses has left.
					cout << "You have " << MAX_TRIES - num_of_wrong_guesses << " guesses left." << endl;
			}
		}
	}
	
	return 0;
}

/* Take a one character guess and the secret word, and fill in the
 unfinished guessword. Returns number of characters matched.
 Also, returns zero if the character is already guessed. */

int letterFill(char guess, char secretword[], char guessword[])
{
	int i;
	int matches = 0;
	for (i = 0; secretword[i] != '\0'; i++)
	{

		// Did we already match this letter in a previous guess?
		if (guess == guessword[i])
		{
			matches=-1;
			return matches;
		}

		// Is the guess in the secret word?
		if (guess == secretword[i])
		{
			guessword[i] = guess;
			matches++;
		}
	}
	return matches;
}


// Initialize the unknown word

void initUnknown(char word[], char unknown[])
{
	int i;
	int length = strlen(word);
	for (i = 0; i < length; i++)
		unknown[i] = '*';
	unknown[i] = '\0';
}
