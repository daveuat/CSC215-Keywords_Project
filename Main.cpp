#include <iostream> // declaring the main library used
#include <string> // used for variables with std::string etc.
#include <cstdlib> // header for memory management, random number generators
#include <ctime> // header with date and time macros and functions

using namespace std; // Using namespace "std" since we will use cout and endl a lot

int main() //main function
{
    int gamerounds = 1; // Integer used for counting game rounds.
	int threeroundcount = 1; // three round counter variable
	int hintused = 0; // variable for hint usage counter
    string play_again = "y"; // Variable for the user when asking if they would like to play again after the first 3 words.
	string guess; // string variable to store guess or store quit option.
	int score = 0; // variable to store users score

	// The Lines below display with the raw string for exact lines with spaces of the text.
	cout << R"(
#     #                                              #######                                   
#  #  # ###### #       ####   ####  #    # ######    #       #    # ##### #    # #####  ###### 
#  #  # #      #      #    # #    # ##  ## #         #       #    #   #   #    # #    # #      
#  #  # #####  #      #      #    # # ## # #####     #####   #    #   #   #    # #    # #####  
#  #  # #      #      #      #    # #    # #         #       #    #   #   #    # #####  #      
#  #  # #      #      #    # #    # #    # #         #       #    #   #   #    # #   #  #      
 ## ##  ###### ######  ####   ####  #    # ######    #        ####    #    ####  #    # ######                                                                                                                                                                   
)" << '\n';
	cout << R"(
   #                                      ### 
  # #    ####  ###### #    # #####  ####  ### 
 #   #  #    # #      ##   #   #   #      ### 
#     # #      #####  # #  #   #    ####   #  
####### #  ### #      #  # #   #        #     
#     # #    # #      #   ##   #   #    # ### 
#     #  ####  ###### #    #   #    ####  ### 
)" << '\n';

    do  {
    	do {
			enum fields { WORD, HINT, NUM_FIELDS }; // setting predefined constants for the variable
			const int NUM_WORDS = 25; // variable for number of words used
			const string WORDS[NUM_WORDS][NUM_FIELDS] =
			{
				{"airstrike", "Two words with no space for separation. Attack from above."},
				{"attack", "An aggressive maneuver."},
				{"authentication", "A way of identifying and verifying."},
				{"bomb", "A device that can explode."},
				{"clandestine", "Things done secretively."},
				{"classification", "The decided level on how that information should be handled."},
				{"cipher", "A cryptographic system where there is a system to transform something for concealment."},
				{"collateral", "Something pledged as security for something else."},
				{"covert", "Operations that are concealed when attempted."},
				{"defector", "A foreign national that has escaped their country who has value to us and can offer aid."},
				{"disclosure", "Authorized release of classified or sensitive information."},
				{"dissemination", "Conveying gathered intelligence to fellow CIA agents."},
				{"doubleagent", "Two words with no space for separation. A government staff member who is working for 2 organizations of 2 separate governments."},
				{"espionage", "Gathering of government intelligence of opposing countries."},
				{"integration", "A process in the production step of the intelligence cycle and selection of gathered intelligence."},
				{"overt", "Operations not concealed when attempted."},
				{"refugee", "An individual unable to return to their home country for fear of persecution."},
				{"sabotage", "Deliberate destruction for political gain."},
				{"sanitization", "Cleaning and/or scrubbing of classified information from electronic devices or in your office(s)."},
				{"sensitive", "Information that requires some protection."},
				{"signal", "Anything transmitted by any type of frequency band."},
				{"subterfuge", "CIA agents have to be good at this."},
				{"surveillance", "Observing or monitoring of places, people, or things."},
				{"validation", "Process normally associated with the collection of intelligence and approves official status."},
				{"war", "What we are fighting."},
			};

			srand(static_cast<unsigned int>(time(0))); //randomize word
			int choice = (rand() % NUM_WORDS); // variable for word
			string theWord = WORDS[choice][WORD];  // word to guess
			string theHint = WORDS[choice][HINT];  // hint for word
			string scrambled = theWord;  // jumbled version of word
			int length = scrambled.size(); //variable storing size

    		for (int i = 0; i < length; ++i) // loop to randomize words
			{
				int index1 = (rand() % length);
				int index2 = (rand() % length);
				char temp = scrambled[index1];
				scrambled[index1] = scrambled[index2];
				scrambled[index2] = temp;
			}


			cout << "Decipher the scrambled letters, type the word, and then press enter.\n";
			cout << "Enter 'hint' for a hint.\n";
			cout << "Enter 'quit' to quit the game.\n\n";
			cout << "Round: " << gamerounds << "\n\n";
			cout << "Your Score is: " << score << "\n\n";
			cout << "The scrambled word is: " << scrambled;

		    cout << "\n\nYour guess: ";
			cin >> guess;

			while ((guess != theWord) && (guess != "quit")) // loop to monitor user input for hint
			{
				if (guess == "hint") //if user types hint it will display hint
				{
					cout << theHint;
					hintused++;
				}
				else // if input is incorrect it will display this text
				{
					cout << "Sorry, that's incorrect. Please try again. ";
				}

				cout << "\n\nYour guess: ";
				cin >> guess; // store input from user
			}

			if (guess == theWord) // loop to monitor variable guess and to display information to player
			{
				cout << "\nThat's it!  You guessed it!\n";
				score++; // increase score variable
				gamerounds++; // increase rounds variable
				threeroundcount++; // increase 3 round count variable for user prompt to ask to continue or not
				system("pause"); // command to pause and add press any key to continue
				system("CLS"); // command to clear screen.
			}
			if (guess == "quit") //loop to look for quit input
			{
				threeroundcount = 4; //sets gamerounds to 4 so game ends while loop
			}

			system("CLS"); // command to clear screen.
		} while (threeroundcount != 4); //loop ends if gamerounds is equal to 4

		cout << "\nYour current score: " << score << endl;
		cout << "\nRounds played: " << gamerounds - 1 << endl; // the minus one helps it display the accurate number
		cout << "\nTimes asked for hint: " << hintused << endl;
		cout << "\nWould you like to play again? Please type Y or N and press enter. ";
		cin >> play_again; // stores input from user
		threeroundcount = 1; // sets the three round counter back to the start

	} while (play_again == "y" or play_again == "Y" or play_again == "yes" or play_again == "Yes"); //loop will run unless user types N/n/no/No

	system("CLS"); // command to clear screen.
	cout << "\nThank you for playing. Good bye! " << endl;
	cout << "\nTimes asked for hint: " << hintused << endl;
	cout << "\nYour final score: " << score << endl;

    return 0;
}