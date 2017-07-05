#include <iostream>
#include <windows.h> // Used to add color to the text and for the sleep function.
#include <ctime> // Used for the Guess the Number game.
#include <chrono> // Used for the time challenge timer.
using namespace std;

// Global variables
int choice;
int guess;
int cont;
int cust = 0;
int MaxAttempts;
int counter;

// function prototypes
void title(); // I made the logo
void menu(); // and menu as separate functions
int Guess_the_Number();// I used function prototypes to prevent clutter
int ten();          // when reading the source code.
int hund();
int thous();
int custom();
int hang_man();
void hanged();
int hang_ten();
int hang_hund();
int hang_thous();
int time_challenge();
int time_ten();
int time_hund();
int time_thous();
int Random();

int main()
{

    const int guess = 1, // The number of the game that you want to play.
              hang = 2,
              time = 3,
              random_game = 4, // Picks a random game out of the three.
              quit = 5;
         char response; // This is a separate variable for when the user wants to choose Yes ('Y'/'y') to leave
                    // or No ('N'/'n') to stay.

    do //Keeps menu on the screen when the user makes a choice.
    {
        title(); // calls the function for the title.
        menu(); // calls the function for the menu.
        cin >> choice;

        switch (choice)
        {
            case guess:
                cout << "\n\t\t\t\t\t You've chosen the Guess the Number Game"; // Standard guess the number game.
                Sleep(1000); // Pauses for 1 second.
                system("cls");
                Guess_the_Number(); // calls the games function
                break;

            case hang:
                cout << "\n\t\t\t\t\t You've chosen Hangman"; // A hangman version of the guess the number game.
                Sleep(1000); // Pauses for 1 second.
                system("cls");
                hang_man(); // calls the games function.
                break;

            case time:
                cout << "\n\t\t\t\t\t You've chosen Time Challenge"; // A timed hangman game.
                Sleep(1000); // Pauses for 1 second.
                system("cls");
                time_challenge(); // calls the games function
                break;

            case random_game:
                cout << "\n\t\t\t\t\t We've chosen ..."; // Selects a random game out of the top 3.
                Sleep(1000); // Pauses for dramatic effect.
                Random(); // Calls the function to pick random game.
                break;

            case quit:
                cout << "\a\t\t\t\t\t Are you sure? [y/n]: "; // Asks the user if they really want to quit.
                cin >> response;
                if(response == 'Y' | response == 'y'){ // The user can input either Y or y to exit.
                    cout << "\n\t\t\t\t\t Goodbye!";
                    return 0;
                }
                else if(response == 'N' | response == 'n'){ // The user can input either N or n to stay.
                    system("cls");
                    cout << "\n\t\t\t\t\t You're back!";
                    main();
                }
                else{
                    cout << "\n\a\t\t\t\t\t You have to choose 'Y' for yes or 'N' for no!"; // Tells the user that their input is invalid.
                    main();
                }
                break;

            default:
                if(choice != (choice >= 1 || choice <= 5)){

                    cout << "\n\a\t\t\t\t\t That isn't an option. You must choose" // Tells the user that their input is invalid.
                        << " a number between 1 to 5";
                    Sleep(2000); // Pauses so that the user can view the message.
                    system("cls"); // Clears the screen after 2 seconds to prevent clutter.
                }
        }
    }while (choice != 5); // Exits the loop when choice equals 5.
    return 0; // Exits program if choice equals 5.
}

void title() // The function for the title
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_INTENSITY); // Adds color to the text
    cout << "\n\t\t\t\t\t=================================\n" // This is the Guess-Mania Logo
         << "\t\t\t\t\t                                   \n"
         << "\t\t\t\t\t     Welcome to Guess-Mania            \n"
         << "\t\t\t\t\t         				          \n"
         << "\t\t\t\t\t=================================\n";
}
void menu()
{
    cout << "\n\t\t\t\t\t [1] Guess the Number\n"    // A standard guess the number game.
         << "\n\t\t\t\t\t [2] Hangman\n"        	// A Hangman spin on the guess the number game.
         << "\n\t\t\t\t\t [3] Time Challenge\n"		// A time challenge mode.
         << "\n\t\t\t\t\t [4] Random Game \n"       // Random chooses between the first 3 choices.
         << "\n\t\t\t\t\t [5] Quit\n"                //Exit the program.
         << "\n\t\t\t\t\t-------------------------------"
         << "\n\t\t\t\t\t What do you want to play?: ";
}
int Guess_the_Number()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN|FOREGROUND_INTENSITY); // Adds color to the text.
    srand(time(NULL)); // seeds the random number.
    const int tn = 1; // Variables for the difficulty levels.
    const int hd = 2;
    const int td = 3;
    const int cust_num = 4;


  do{

    cout << "\n\t\t\t\t\t=================================\n" // This is the Guess the Number Logo.
         << "\t\t\t\t\t                                   \n"
         << "\t\t\t\t\t   Guess the Number		     \n"
         << "\t\t\t\t\t                    \n"
         << "\t\t\t\t\t=================================\n";
	cout << "\n\t\t\t\t\t[1] Start\n";
	cout << "\n\t\t\t\t\t[0] Exit \n";
	cout << "\n\t\t\t\t\t----------------------------\n";
	cout << "\n\t\t\t\t\t Enter 1 to start or 0 to exit: ";
    cin >> cont;

    if(cont == 1){ // Starts the game.
        system("cls");
    }
    else if(cont == 0){ // Returns the user to the main menu.
        system("cls");
        main();
        return 0;
    }
    else{
        cout << "\aThat isn't an option"; // If the user inputs something other than
        Sleep(2000);                        // 1 or 0.
        system("cls");
    }

  } while(cont != 1); // Once the user starts the game, it will exit the loop.

    cout << "\n\t\t\t\t\t=================================\n" // This is the Guess the Number Logo
         << "\t\t\t\t\t                                   \n"
         << "\t\t\t\t\t   Guess the Number		     \n"
         << "\t\t\t\t\t                    \n"
         << "\t\t\t\t\t=================================\n";
    cout << "\n\t\t\t\t\t Difficulty Levels\n";   // Levels of difficulty for the user.
    cout << "\n\t\t\t\t\t------------------\n";
    cout << "\n\t\t\t\t\t[1] 1-10 (Easy)\n";
    cout << "\n\t\t\t\t\t[2] 1-100 (Medium)\n";
    cout << "\n\t\t\t\t\t[3] 1-1000 (Hard)\n";
    cout << "\n\t\t\t\t\t[4] Custom Game\n";     // The user can choose to input their own number.
    cout << "\n\t\t\t\t\t-------------------------------------------------------";
	cout << "\n\t\t\t\t\tChoose a difficulty level or choose your own number: ";
    cin >> choice;

    switch(choice)
    {
        case tn: // #s 1-10
            system("cls"); // Clears the screen.
            ten(); // Calls the function.
            break;

        case hd: // #s 1-100
            system("cls"); // Clears the screen.
            hund(); // Calls the function.
            break;

        case td: // #s 1-1000
            system("cls"); // Clears the screen.
            thous(); // Calls the function.
            break;

        case cust_num: // Users own number.
            system("cls"); // Clears the screen.
            custom(); // Calls the function.
            break;

        default:
          while(choice != 1 || choice != 2 || choice != 3 || choice != 4){ // Loop continues while choice doesn't equal 1, 2, 3, or 4.
            cout << "\aYou have to choose an option from the list from 1 to 4\n";
            cout << "\nChoose a difficulty level or choose your own number: ";
            cin >> choice;
          }
    }
    return 0;
}

int ten()
{
    int n = rand() % 10 + 1; // Gets random number from 1 to 10.
    counter = 0; // Sets the counter to 0.
    do
    {
    	cout << "The random number is between 1 and 10\n"; // Informs the user where the random number is located
        cout << "Type a guess between 1 and 10\n"; // and where what type of number their guess should be.
        cout << "\nCounter: " << counter << "\n"; // Places the counter on the screen.
        cout << "Your guess: ";
        cin >> guess;
        system("cls"); // clears the screen every time the user guesses wrong.


        if(guess == n) // Runs if the user's guess is correct.
        {
            cout << "\nCorrect! The number was " << n << "\n"
                << "and it took you " << counter << " attempts\n"; // Tells the user how many tries it took them to guess correctly.
           do{
            cout << "Press any [1] to play again or [0] to exit: "; // Runs this line until cont = 1 or 0.
            cin >> cont;

            if(cont == 1)
            {
                system("cls"); // Clears the screen, then relaunches the function so the user can play again.
                ten();
            }
            else if(cont == 0)
            {
                cout << "\nGoodbye! Returning to the main menu!\n"; // Says goodbye then waits 2 seconds before clearing the screen
                Sleep(2000);                                        // and returning to the main menu in the main function.
                system("cls");
                Guess_the_Number();
            }
            else{
                cout << "\aThats not an option"; // Runs if the input is not valid
                Sleep(500); // Waits half a second before clearing the screen.
                system("cls");
            }
         }while(cont != 1 || cont != 0); // Runs this loop until cont = 1 or cont = 0.
        }

        else if (guess > n){
            cout << "That's too high\n"; // Runs if the user's guess is greater than the random number.
            counter++; // Increments the counter if the user guesses incorrectly.
        }
        else{
            cout << "That's too low\n"; // Runs if the user's guess is less than the random number.
            counter++; // Increments the counter if the user guesses incorrectly.
        }
    }while(guess != n); // Runs until the guess equals the random number.
}

int hund()
{
    int d = rand() % 100 + 1; // Gets random number from 1 to 100.
    counter = 0; // Sets the counter to 0.
    do
    {
    	cout << "The random number is between 1 and 100\n"; // Informs the user where the random number is
        cout << "Type a guess between 1 and 100\n"; // and hints at where to find the random number.
        cout << "\nCounter: " << counter << "\n"; // Prints the counter onto the screen.
        cout << "Your guess: ";
        cin >> guess;
        system("cls"); // Clears the screen if the user answers incorrectly.


        if(guess == d)
        {
            cout << "\nCorrect! The number was " << d << "\n" // Tells the user what the random number was.
                << "and it took you " << counter << " attempts\n"; // Tells the user how many attempts they made before guessing correctly.
           do{
            cout << "Press any [1] to play again or [0] to exit: "; // Stays on screen until the the user inputs a value into cont.
            cin >> cont;

            if(cont == 1)
            {
                system("cls"); // If the user chooses to play again, the function hund() will run again.
                hund();
            }
            else if(cont == 0)
            {
                cout << "\nGoodbye! Returning to the main menu!\n";
                Sleep(2000); // Pauses the screen for 2 seconds.
                system("cls"); // Clears the screen.
                Guess_the_Number(); // Returns the user to the main menu.
            }
            else{
                cout << "\aThats not an option"; // Informs the user that their input is invalid.
                Sleep(500); // Pauses for half a second.
                system("cls"); // Clears the screen.
            }
          }while(cont != 1 || cont != 0); // The loop continues until cont equals 1 or 0.
        }

        else if (guess > d){
            cout << "That's too high\n"; // Tells the user that their guess was greater than the random number.
            counter++; // Increments counter by one.
        }
        else{
            cout << "That's too low\n"; // Tells the user that their guess was less than the random number.
            counter++; // Increments counter by one.
        }
   }while(guess != d); // The loop continues as long as the user's guess isn't the same as the random number.
}

int thous()
{
    int s = rand() % 1000 + 1; // Gets random number from 1 to 1000.
    counter = 0; // Sets the counter to 0.
    do
    {
    	cout << "The random number is between 1 and 1000\n"; // Tells the user where the random number is
        cout << "Type a guess between 1 and 1000\n";// and where the users guess should be.
        cout << "\nCounter: " << counter << "\n"; // Prints the counter to the screen.
        cout << "Your guess: ";
        cin >> guess;
        system("cls"); // Clears the screen if the user's guess is wrong.


    if(guess == s)
    {
        cout << "\nCorrect! The number was " << s << "\n" // If the user's guess is correct this will print the random number.
             << "and it took you " << counter << " attempts\n"; // Prints the amount of attempts the user has made to guess the right answer.
       do{
        cout << "Press any [1] to play again or [0] to exit: "; // Prints this line and keeps it on the screen until the user inputs 1 or 0.
        cin >> cont;

        if(cont == 1) // When cont equals 1,the screen will clear and will relaunch the thous() function.
        {
            system("cls");
            thous();
        }
        else if(cont == 0)
        {
            cout << "\nGoodbye! Returning to the main menu!\n"; // This will print, then wait two seconds before clearing the screen and returning
            Sleep(2000);                                        // to the main menu.
            system("cls");
            Guess_the_Number();
        }
         else{
            cout << "\aThats not an option"; // Informs the user that their input is invalid.
            Sleep(500);                         // Pauses for half a second before clearing the screen.
            system("cls");
         }
        }while(cont != 1 || cont != 0); // The loop continues until cont equals 1 or 0.
    }

    else if (guess > s){
        cout << "That's too high\n"; // Informs the user that their guess is greater than the random number.
        counter++; // Increments the counter by 1;
    }
    else{
        cout << "That's too low\n"; // Informs the user that their guess is less than the random number.
        counter++; // Increments the counter by 1.
    }
  }while (guess != s); // The loop continues as long as the user's guess doesn't equal the random number.
}

int custom()
{
    counter = 0; // Sets the counter to 0.
	cout << "Enter your custom number: ";
    cin >> cust;   // The user inputs their own number.
    system("cls"); // Clears the screen in order to hide their input
    Sleep(500); // and waits half a second before continuing.

    if(cust >= 0 && cust <= 10){
        cout << "The custom number is between 1 and 10\n"; // Prints if cust is greater than or equal to 0 and less than or equal to 10.
    }
    else if(cust >= 0 && cust <= 100){
        cout << "The custom number is between 1 and 100\n"; // Prints if cust is greater than or equal to 0 and less than or equal to 100.
    }
    else if(cust >= 0 && cust <= 1000){
        cout << "The custom number is between 1 and 1000\n"; // Prints if cust is greater than or equal to 0 and less than or equal to 1000.
    }
    else if(cust < 0){
        cout << "\aThats too low, it has to be a positive number\n"; // Prevents the user from inputing a number less than 0.
        custom();   // Returns the user to the beginning of the function in order to put in their new input.
    }
    else{
        cout << "\aThe custom number has to be lower or equal to 1000\n"; // Prevents the user from inputing a number greater than 1000.
        custom(); // Returns the user to the beginning of the function in order to put in their new input.
    }

    do{
       cout << "\nCounter: " << counter << "\n"; // Prints out the counter onto the screen.
       cout << "Your guess: ";
       cin >> guess;
       system("cls"); // Clears the screen if the user's guess is wrong.

        if(guess == cust)
        {
            cout << "\nCorrect! The number was " << cust << "\n" // Prints out the correct number once the user guesses correctly.
                << "and it took you " << counter << " attempts\n"; // Prints out the amount of attempts it took the user to guesses correctly.
           do{
            cout << "Press any [1] to play again or [0] to exit: "; // Prints onto the screen until cont equals 1 or 0.
            cin >> cont;


            if(cont == 1)
            {
                system("cls"); // When cont equals 1, the screen is cleared and the custom() function is relaunched.
                custom();
            }
            else if(cont == 0)
            {
                cout << "\nGoodbye! Returning to the main menu!\n"; // Prints onto the screen when cont equals 0
                Sleep(2000);                                        // and waits 2 seconds before clearing the screen
                system("cls");                                      // and returning to the main menu.
                Guess_the_Number();
            }
            else
            {
                cout << "\aThats not an option"; // Informs the user that their input is invalid before waiting half a second and clearing the screen.
                Sleep(500);
                system("cls");
            }
         }while(cont != 1 || cont != 0); // Loop continues until cont equals 1 or 0.
        }

        else if (guess > cust)
        {
            cout << "That's too high\n"; // If the user's guess is greater than the random number, this will print out.
            counter++; // If the user guesses incorrectly, the counter will increment by 1.
        }
        else{
            cout << "That's too low\n"; // If the user's guess is less than the random number, this will print out.
            counter++; // If the user guesses incorrectly, the counter will increment by 1;
        }
    }while(guess != cust); // The loop continues until the user's guess equals the user's custom number.
}

int hang_man()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_BLUE|FOREGROUND_RED|FOREGROUND_INTENSITY); // Adds color to the text.
	const int hang_tn = 1; // The choices for difficulty.
	const int hang_hd = 2;
	const int hang_td = 3;

	do{

    	cout << "\n\t\t\t\t\t=================================\n" // This is the hangman logo
         << "\t\t\t\t\t                                   \n"
         << "\t\t\t\t\t         Hangman Mode		     \n"
         << "\t\t\t\t\t                    \n"
         << "\t\t\t\t\t=================================\n";
        cout << "\t\t\t\t\t +---+\n";
        cout << "\t\t\t\t\t |   |\n" ;
        cout << "\t\t\t\t\t |  	    O - (Become my SAVIOR or my EXECUTIONER!)\n";
        cout << "\t\t\t\t\t |  	   /|\\ \n";
        cout << "\t\t\t\t\t |  	   / \\ \n";
        cout << "\t\t\t\t\t-+-\n";
		cout << "\n\t\t\t\t\t[1] Start\n";
		cout << "\n\t\t\t\t\t[0] Exit \n";
		cout << "\n\t\t\t\t\t----------------------------\n";
		cout << "\n\t\t\t\t\t Enter 1 to start or 0 to exit: ";
    	cin >> cont;

		if(cont == 1){ // Starts the game.
			system("cls");
		}
		else if(cont == 0){
			system("cls");
			main(); // Returns the user to the main menu.
		}
		else{
			cout << "\a That isn't an option\n"; // If the user inputs something other than
			Sleep(1000);						// 1 or 0.
			system("cls");
		}
	} while(cont != 1); // Once the user starts the game, it will exit the loop.

    cout << "\n\t\t\t\t\t=================================\n" // This is the hangman logo
         << "\t\t\t\t\t                                   \n"
         << "\t\t\t\t\t        Hangman Mode		     \n"
         << "\t\t\t\t\t                    \n"
         << "\t\t\t\t\t=================================\n";
    cout << "\n\t\t\t\t\t Difficulty Levels\n";   // Levels of difficulty for the user.
    cout << "\t\t\t\t\t------------------\n";
    cout << "\t\t\t\t\t [1] 1-10 (Easy)\n";
    cout << "\t\t\t\t\t [2] 1-100 (Medium)\n";
    cout << "\t\t\t\t\t [3] 1-1000 (Hard)\n";
    cout << "\t\t\t\t\t ------------------------------\n";
    cout << "\t\t\t\t\t Choose a difficulty level: ";
    cin >> choice;

    switch(choice)
    {
        case hang_tn: // #s 1-10
            system("cls"); // Clears the screen.
            hang_ten(); // Calls the function.
            break;

        case hang_hd: // #s 1-100
            system("cls"); // Clears the screen.
            hang_hund(); // Calls the function.
            break;

        case hang_td: // #s 1-1000
            system("cls"); // Clears the screen.
            hang_thous(); // Calls the function.
            break;

        default:
          while(choice != 1 || choice != 2 || choice != 3){ // Loop continues while choice doesn't equal 1, 2, 3.
            cout << "\a You have to choose an option from the list from 1 to 3\n";
            cout << "\n Choose a difficulty level or choose your own number: ";
            cin >> choice;
          }
    }

    return 0;
}

int hang_ten()
{
	int n = rand() % 10 + 1; // Gets random number from 1 to 10.
    ::MaxAttempts = 6; // Calls the global variable and sets value of 6 to it.
    counter = 0;
    do
    {
    	cout << " The random number is between 1 and 10\n"; // Informs the user where the random number is located
        cout << " Type a guess between 1 and 10\n"; // and where what type of number their guess should be.
        cout << "\n You have " << (::MaxAttempts) << " attempts left";
        cout << "\n Your guess: ";
        cin >> guess;
        system("cls"); // clears the screen every time the user guesses wrong.


        if(guess == n) // Runs if the user's guess is correct.
        {
            cout << "\n Correct! The number was " << n;
            cout << " and it took you " << counter << " attempts\n"; // Tells the user how many tries it took them to guess correctly.
            cout << "\n You've saved him!\n";
			cout << "  O/ - (Thanks, you really saved my neck!)\n";
			cout << " /|									\n";
			cout << " / \\									\n";
        }
        else if (guess > n){
            cout << " That's too high\n"; // Runs if the user's guess is greater than the random number.
            ::MaxAttempts--; // Decrements MaxAttempts if the user guesses incorrectly
            counter++;      // Increments the counter if the user guesses incorrectly.
            hanged(); // Calls the hanged function to print out the hangman.
        }
        else{
            cout << " That's too low\n"; // Runs if the user's guess is less than the random number.
            ::MaxAttempts--; // Decrements MaxAttempts if the user guesses incorrectly
            counter++;      // Increments the counter if the user guesses incorrectly.
            hanged(); // Calls the hanged function to print out the hangman.
        }
    }while(guess != n && ::MaxAttempts != 0); // Runs until the guess equals the random number.

    do{
    	cout << " Press any [1] to play again or [0] to exit: "; // Runs this line until cont = 1 or 0.
        cin >> cont;

	    if(cont == 1)
        {
            system("cls"); // Clears the screen, then relaunches the function so the user can play again.
            hang_ten();
        }
        else if(cont == 0)
        {
            cout << "\n Goodbye! Returning to the main menu!\n"; // Says goodbye then waits 2 seconds before clearing the screen
            Sleep(2000);                                        // and returning to the main menu in the main function.
            system("cls");
            hang_man(); // Returns the player to the hangman main menu.
        }
        else{
            cout << "\a Thats not an option"; // Runs if the input is not valid
            Sleep(500); // Waits half a second before clearing the screen.
            system("cls");
        }
    }while(cont != 1 || cont != 0); // Runs this loop until cont = 1 or cont = 0.
}

int hang_hund()
{
	int d = rand() % 100 + 1; // Gets random number from 1 to 100.
    ::MaxAttempts = 6; // Max attemtpts that the user can make.
    counter = 0; // Sets the counter to 0.

	do{
    	cout << " The random number is between 1 and 100\n"; // Informs the user where the random number is located
        cout << " Type a guess between 1 and 100\n"; // and where what type of number their guess should be.
        cout << "\n You have " << (::MaxAttempts) << " attempts left";
        cout << "\n Your guess: ";
        cin >> guess;
        system("cls"); // clears the screen every time the user guesses wrong.


        if(guess == d) // Runs if the user's guess is correct.
        {
            cout << "\n Correct! The number was " << d;
            cout << " and it took you " << counter << " attempts\n"; // Tells the user how many tries it took them to guess correctly.
            cout << "\n You've saved him!\n";
			cout << "  O/ - (Thanks, you really saved my neck!)\n";
			cout << " /|									\n";
			cout << " / \\									\n";
        }

        else if (guess > d){
            cout << " That's too high\n"; // Runs if the user's guess is greater than the random number.
            ::MaxAttempts--; // Decrements MaxAttempts if the user guesses incorrectly
            counter++;      // Increments the counter if the user guesses incorrectly.
            hanged(); // Calls the hanged function and prints out the hangman.
        }
        else{
            cout << " That's too low\n"; // Runs if the user's guess is less than the random number.
            ::MaxAttempts--; // Decrements MaxAttempts if the user guesses incorrectly
            counter++;      // Increments the counter if the user guesses incorrectly.
            hanged(); // Calls the hanged function and prints out the hangman.
        }
    }while(guess != d && ::MaxAttempts != 0); // Runs until the guess equals the random number.

    do{
    	cout << " Press any [1] to play again or [0] to exit: "; // Runs this line until cont = 1 or 0.
        cin >> cont;

	    if(cont == 1)
        {
            system("cls"); // Clears the screen, then relaunches the function so the user can play again.
            hang_hund(); // Restarts the game.
        }
        else if(cont == 0)
        {
            cout << "\n Goodbye! Returning to the main menu!\n"; // Says goodbye then waits 2 seconds before clearing the screen
            Sleep(2000); // Waits 2 seconds                      // and returning to the main menu in the main function.
            system("cls");
            hang_man(); // Returns the player to the hangman main menu.
        }
        else{
            cout << "\a Thats not an option"; // Runs if the input is not valid
            Sleep(500); // Waits half a second before clearing the screen.
            system("cls");
        }
    }while(cont != 1 || cont != 0); // Runs this loop until cont = 1 or cont = 0.
}

int hang_thous()
{
	int s = rand() % 1000 + 1; // Gets random number from 1 to 1000.
    ::MaxAttempts = 6; // Max attempts that the user can make.
    counter = 0; // Sets the counter to 0.

	do{
    	cout << " The random number is between 1 and 1000\n"; // Informs the user where the random number is located
        cout << " Type a guess between 1 and 1000\n"; // and where what type of number their guess should be.
        cout << "\n You have " << (::MaxAttempts) << " attempts left";
        cout << "\n Your guess: ";
        cin >> guess;
        system("cls"); // clears the screen every time the user guesses wrong.


        if(guess == s) // Runs if the user's guess is correct.
        {
            cout << "\n Correct! The number was " << s;
            cout << " and it took you " << counter << " attempts\n"; // Tells the user how many tries it took them to guess correctly.
            cout << "\n You've saved him!\n";
			cout << "  O/ - (Thanks, you really saved my neck!)\n";
			cout << " /|									\n";
			cout << " / \\									\n";
        }

        else if (guess > s){
            cout << " That's too high\n"; // Runs if the user's guess is greater than the random number.
            ::MaxAttempts--; // Decrements MaxAttempts if the user guesses incorrectly
            counter++;      // Increments the counter if the user guesses incorrectly.
            hanged(); // Calls the hanged function and prints out the hangman.
        }
        else{
            cout << " That's too low\n"; // Runs if the user's guess is less than the random number.
            ::MaxAttempts--; // Decrements MaxAttempts if the user guesses incorrectly
            counter++;      // Increments the counter if the user guesses incorrectly.
            hanged(); // Calls the hanged function and prints out the hangman.
        }
    }while(guess != s && ::MaxAttempts != 0); // Runs until the guess equals the random number.

    do{
    	cout << " Press any [1] to play again or [0] to exit: "; // Runs this line until cont = 1 or 0.
        cin >> cont;

	    if(cont == 1)
        {
            system("cls"); // Clears the screen, then relaunches the function so the user can play again.
            hang_thous(); // Restarts the game.
        }
        else if(cont == 0)
        {
            cout << "\n Goodbye! Returning to the main menu!\n"; // Says goodbye then waits 2 seconds before clearing the screen
            Sleep(2000);                                        // and returning to the main menu in the main function.
            system("cls");
            hang_man(); // Returns the player to the hangman main menu.
        }
        else{
            cout << "\a Thats not an option"; // Runs if the input is not valid
            Sleep(500); // Waits half a second before clearing the screen.
            system("cls");
        }
    }while(cont != 1 || cont != 0); // Runs this loop until cont = 1 or cont = 0.
}
void hanged() // Prints out the hangman when the user guesses incorrectly.
{
    if(::MaxAttempts == 5){
        cout << " +---+\n";
		cout << " |   |\n";
		cout << " |   O\n";
		cout << " | \n";
		cout << " | \n";
		cout << "-+-\n";
	}
	else if(::MaxAttempts == 4){
		cout << " +---+\n";
		cout << " |   |\n";
		cout << " |   O\n";
		cout << " |   |\n";
		cout << " |  \n";
		cout << "-+-\n";
	}
	else if(::MaxAttempts == 3){
        cout << " +---+\n";
		cout << " |   |\n";
		cout << " |   O\n";
		cout << " |  /|\n";
		cout << " | \n";
		cout << "-+-\n";
	}
	else if(::MaxAttempts == 2){
		cout << " +---+\n";
		cout << " |   |\n";
		cout << " |   O\n";
		cout << " |  /|\\ \n";
		cout << " | \n";
		cout << "-+-\n";
	}
	else if(::MaxAttempts == 1){
		cout << " +---+\n";
		cout << " |   |\n";
		cout << " |   O\n";
		cout << " |  /|\\ \n";
		cout << " |  /\n";
		cout << "-+-\n";
	}
	else if(::MaxAttempts == 0){
		cout <<"\n You've been hung! \n";
		cout << " +---+\n";
		cout << " |   |\n";
		cout << " |   O\n";
		cout << " |  /|\\\n";
		cout << " |  / \\\n";
		cout << "-+-\n";
	}
}
int time_challenge()
{
	const int time_tn = 1; // Choices for difficulty and time.
	const int time_hd = 2;
	const int time_td = 3;
	srand(time(NULL)); // Makes sure that the random number is always different.
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN|FOREGROUND_RED|FOREGROUND_INTENSITY); // Adds color to the text.
	do{
	 cout << "\n\t\t\t\t\t=================================\n" // This is the Time Challenge Logo
         << "\t\t\t\t\t                                   \n"
         << "\t\t\t\t\t   Time Challenge Mode		     \n"
         << "\t\t\t\t\t                    \n"
         << "\t\t\t\t\t=================================\n";

		cout << "\n\t\t\t\t\t[1] Start\n";
		cout << "\n\t\t\t\t\t[0] Exit \n";
		cout << "\n\t\t\t\t\t----------------------------\n";
		cout << "\n\t\t\t\t\t Enter 1 to start or 0 to exit: ";
		cin >> cont;

		if(cont == 1){ // Starts the game.
			system("cls");
		}
		else if(cont == 0){ // returns the user to the main menu.
			system("cls");
            main();
		}
		else{
			cout << "\aThat isn't an option"; // If the user inputs something other than
			Sleep(2000); // Waits 2 seconds   // 1 or 0.
			system("cls");
		}
	}while(cont != 1); // Loops until cont = 1.

	cout << "\n\t\t\t\t\t=================================\n" // This is the Time Challenge Logo.
         << "\t\t\t\t\t                                   \n"
         << "\t\t\t\t\t   Time Challenge Mode		     \n"
         << "\t\t\t\t\t                    \n"
         << "\t\t\t\t\t=================================\n"
		 << "\n\t\t\t\t\t  Difficulty Levels\n"             // Prints out the difficulty levels.
		 << "\t\t\t\t\t-------------------------------\n"
	     << "\t\t\t\t\t [1] 1-10 (Easy (10 seconds))\n"
	     << "\t\t\t\t\t [2] 1-100 (Medium (15 seconds))\n"
	     << "\t\t\t\t\t [3] 1-1000 (Hard (20 seconds))\n"
	     << "\t\t\t\t\t-------------------------------\n"
	     << "\t\t\t\t\t Choose a difficulty level: ";
	     cin >> choice;

	     switch(choice)
	     {
	     	case time_tn:
	     		system("cls"); // Clears the screen.
	     		time_ten(); // Starts the Easy mode.
	     		break;

	     	case time_hd:
	     		system("cls");
	     		time_hund(); // Starts the Medium mode.
	     		break;

	     	case time_td:
	     		system("cls");
	     		time_thous(); // Starts the Hard mode.
	     		break;

			default:
          		while(choice != 1 || choice != 2 || choice != 3){ // Loop continues while choice doesn't equal 1, 2, or 3.
            		cout << "\a You have to choose an option from the list from 1 to 3\n";
            		cout << "\n Choose a difficulty level: ";
            		cin >> choice;
				}
    	}

    return 0;
}

int time_ten()
{	
    int n = rand() % 10 + 1; // Gets random number from 1 to 10.
    counter = 0; // Makes sure that the counter starts at zero and returns to zero when the user plays again.
    cout << "\n You have 10 seconds to guess the correct number!\n";
    cout << " The random number is between 1 and 10\n"; // Informs the user where the random number is located.
	system("pause"); // Pauses the program until the user presses a key.
	system("cls"); // Clears the message above before the game starts.
	std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now() + std::chrono::seconds(10); // Sets the timer.

	do{
    	cout << "\n You have 10 seconds to guess the correct number!\n";
    	cout << " The random number is between 1 and 10\n"; // Informs the user where the random number is located.
    	cout << " Type a guess between 1 and 10\n"; // and where what type of number their guess should be.
    	cout << "\n Counter: " << ::counter << "\n"; // Places the counter on the screen.
    	cout << " Your guess: ";
    	cin >> guess;
    	system("cls"); // clears the screen every time the user guesses wrong.
    
   		if(guess == n){
       		cout << "\n Correct! The number was " << n << "\n"
            << " and it took you " << counter << " attempts!\n"; // Prints the attempts it took to guess correctly.
       		do{
            	cout << " Press any [1] to play again or [0] to exit: ";
            	cin >> cont;

            	if(cont == 1)
            	{
                	system("cls");
                	time_ten(); // Calls the game's function and restarts the game.
            	}
            	else if(cont == 0)
            	{
                	cout << "\n Goodbye! Returning to the main menu!\n";
                	Sleep(2000); // Waits 2 seconds.
                	system("cls");
                	time_challenge(); // Calls the game's main game function and returns the user to the main menu.
            	}
            	else{
                	cout <<"\a That's not an option";
                	Sleep(500); // Waits half a second.
                	system("cls");
            	}
        	}while(cont != 1 || cont != 0); // Runs until the user decides to play again or return to the game's main menu.
    	}
    	else if(std::chrono::steady_clock::now() > tend){ // If the timer goes past 10 seconds.
        	cout << "\a Times up! Try again\n";
        	
        	do{
            	cout << " Press any [1] to play again or [0] to exit: ";
            	cin >> cont;
            	
            	if(cont == 1)
            	{
                	system("cls");
                	time_ten(); // Calls the game's function and restarts the game.
            	}
            	else if(cont == 0)
            	{
                	cout << "\n Goodbye! Returning to the main menu!\n";
                	Sleep(2000); // Waits 2 seconds.
                	system("cls");
                	time_challenge(); // Calls the game's main game function and returns the user to the main menu.
            	}
            	else{
                	cout <<"\a That's not an option"; // Tells the user that this isn't an option.
                	Sleep(500); // Waits half a second.
                	system("cls");
            	}
        	}while(cont != 1 || cont != 0); // Loops until cont = 1 or 0.
    	}
    	else if (guess > n) {
        	cout << " That's too high\n";
        	counter++; // Increments the counter if the user guesses incorrectly.
    	}
   	 	else{
        	cout << " That's too low\n";
        	counter++; // Increments the counter if the user guesses incorrectly.
    	}
   }while(guess != n); // Loops until the user guesses correctly.
	return 0;
}

int time_hund()
{
    int d = rand() % 100 + 1; // Gets random number from 1 to 100.
   
    counter = 0; // Resets the counter to zero.
		
    cout << "\n You have 15 seconds to guess the correct number!\n";
    cout << " The random number is between 1 and 100\n"; // Informs the user where the random number is located.
	system("pause"); // Pauses the program until the user presses a key.
	system("cls"); // Clears the message.
	std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now() + std::chrono::seconds(15); // Sets the timer.
	
	do{
    	cout << "\n You have 15 seconds to guess the correct number!\n";
    	cout << " The random number is between 1 and 100\n"; // Informs the user where the random number is located.
    	cout << " Type a guess between 1 and 100\n"; // and where what type of number their guess should be.
    	cout << "\n Counter: " << ::counter << "\n"; // Places the counter on the screen.
    	cout << " Your guess: ";
    	cin >> guess;
    	system("cls"); // clears the screen every time the user guesses wrong.
    
   		if(guess == d){
       
       		cout << "\n Correct! The number was " << d << "\n"
            << "and it took you " << counter << " attempts!\n";
       		do{
            	cout << " Press any [1] to play again or [0] to exit: ";
            	cin >> cont;

            	if(cont == 1)
            	{
                	system("cls");
                	time_hund(); // Calls the game's function and restarts. 
            	}
            	else if(cont == 0)
            	{
                	cout << "\n Goodbye! Returning to the main menu!\n";
                	Sleep(2000); // Waits 2 seconds.
                	system("cls");
                	time_challenge(); // Brings the user back to the game's main menu.
            	}
            	else{
                	cout <<"\a That's not an option";
                	Sleep(500); // Waits half a second.
                	system("cls");
            	}
        	}while(cont != 1 || cont != 0); // Loops until cont = 1 or 0.
    	}
    	else if(std::chrono::steady_clock::now() > tend){ // If the timer goes past 15 seconds.
        	cout << "\a Times up! Try again\n";
        	do{
            	cout << " Press any [1] to play again or [0] to exit: ";
            	cin >> cont;
            	
            	if(cont == 1)
            	{
                	system("cls");
                	time_hund(); // Calls the game's function and restarts.
            	}
            	else if(cont == 0)
            	{
                	cout << "\n Goodbye! Returning to the main menu!\n";
                	Sleep(2000); // Waits 2 seconds.
                	system("cls");
                	time_challenge(); // Brings the user back to the game's main menu.
            	}
            	else{
                	cout <<"\a That's not an option"; // Tells the user that this isn't an option.
                	Sleep(500); // Waits half a second.
                	system("cls");
            	}
        	}while(cont != 1 || cont != 0); // Loops until cont = 1 or 0.
    	}
    	else if (guess > d) {
        	cout << " That's too high\n";
        	counter++; // Increments counter when the user guesses incorrectly.
    	}
   	 	else{
        	cout << " That's too low\n";
        	counter++; // Increments counter when the user guesses incorrectly.
    	}
   }while(guess != d); // Loops until the user guesses correctly.
	return 0;
}

int time_thous()
{
    int s = rand() % 1000 + 1; // Gets random number from 1 to 1000.
    counter = 0; // Sets counter to 0.
		
    cout << "\n You have 20 seconds to guess the correct number!\n";
    cout << " The random number is between 1 and 1000\n"; // Informs the user where the random number is located.
	system("pause"); // Pauses the program until the user presses a key.
	system("cls"); // Clears the message.
	std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now() + std::chrono::seconds(20); // Sets the timer.

	do{
    	cout << "\n You have 20 seconds to guess the correct number!\n";
    	cout << " The random number is between 1 and 1000\n"; // Informs the user where the random number is located.
    	cout << " Type a guess between 1 and 1000\n"; // and where what type of number their guess should be.
    	cout << "\n Counter: " << ::counter << "\n"; // Places the counter on the screen.
    	cout << " Your guess: ";
    	cin >> guess;
    	system("cls"); // clears the screen every time the user guesses wrong.
    
   		if(guess == s){
       
       		cout << "\n Correct! The number was " << s << "\n"
            << "and it took you " << counter << " attempts!\n";
       		do{
            	cout << " Press any [1] to play again or [0] to exit: ";
            	cin >> cont;

            	if(cont == 1)
            	{
                	system("cls");
                	time_thous(); // Calls the game's function and restarts the game.
            	}
            	else if(cont == 0)
            	{
                	cout << "\n Goodbye! Returning to the main menu!\n";
                	Sleep(2000); // Waits 2 seconds.
                	system("cls");
                	time_challenge(); // Calls the game's main function and returns the user to the main menu.
            	}
            	else{
                	cout <<"\a That's not an option";
                	Sleep(500); // Waits half a second.
                	system("cls");
            	}
        	}while(cont != 1 || cont != 0); // Loops until cont = 1 or 0.
    	}
    	else if(std::chrono::steady_clock::now() > tend){ // If the timer goes past 20 seconds.
        	cout << "\a Times up! Try again\n";
        	do{
            	cout << " Press any [1] to play again or [0] to exit: ";
            	cin >> cont;
            	
            	if(cont == 1)
            	{
                	system("cls");
                	time_thous(); // Calls the game's function and restarts the game.
            	}
            	else if(cont == 0)
            	{
                	cout << "\n Goodbye! Returning to the main menu!\n";
                	Sleep(2000); // Waits 2 seconds.
                	system("cls");
                	time_challenge(); // Calls the game's main function and returns the user to the main menu.
            	}
            	else{
                	cout <<"\a That's not an option"; // Tells the user that this isn't an option.
                	Sleep(500); // Waits half a second.
                	system("cls");
            	}
        	}while(cont != 1 || cont != 0); // Loops until cont = 1 or 0.
    	}
    	else if (guess > s) {
        	cout << " That's too high\n";
        	counter++; // Increments counter when the user guesses incorrectly.
    	}
   	 	else{
        	cout << " That's too low\n";
        	counter++; // Increments counter when the user guesses incorrectly.
    	}
   }while(guess != s); // Loops until the user guesses correctly.
	return 0;
}

int Random()
{
    choice = (rand() % 3) + 1; // Picks a random number between 1 and 3

    if(choice == 1) // Runs if the random number equals 1.
    {
        cout << " Guess the Number!\n\n";
        Sleep(2000); // Waits 2 seconds before clearing the screen
        system("cls");
        Guess_the_Number(); // Starts Guess the Number
    }
    else if(choice == 2) // Runs if the random number equals 2.
    {
        cout << " Hangman!\n\n";
        Sleep(2000); // Waits 2 seconds before clearing the screen.
        system("cls");
        hang_man(); // Starts the Hangman game.
    }
    else
    {
        cout << " Time Challenge!\n\n";
        Sleep(2000); // Waits 2 seconds before clearing the screen.
        system("cls");
        time_challenge(); // Starts the Time challenge.
    }
}
