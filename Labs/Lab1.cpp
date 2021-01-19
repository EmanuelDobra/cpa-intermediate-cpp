#include <iostream>
#include <ctime>
using namespace std;

/**
 * Due Jan20 2021. 
*/

/***************************************************************************
Emanuel Dobra   
Lab 1
***************************************************************************/

//template for lab on dowhile and switch 
int main()
{
    /*
     * Example #1: do while loop
     * TO-DO: Follow the steps in this example and write the appropriate code
    */
    srand((unsigned)time(0));
    int number, guess;
    char again;
    do {
        cout << "\nPlay the guessing game\n";

        number = rand() % 10 + 1; 
        cout << "I'm thinking of a number from 1 to 10. ";
        //repeatedly ask for guesses
        cout << "Try to guess it: ";
        cin >> guess;
        while (guess < 1 || guess > 10 || cin.fail()) {
            cin.clear();
            cin.ignore(80,'\n');
            cout << "number must be 1-10 reenter: ";
            cin >> guess;
        }  //validate guess 1-10

        if (number < guess) //check the guess
            cout << "Too high! ";
        else if (number >guess)
            cout << "Too low! ";
        else
            cout << "Correct! ";
        
        cout << "The number was: " << number << endl;

        //step2b: ask the user if he/she wants to play again
        // store the reply in "again"
        // validate again (allow y or n), use tolower
        cout << "Do you want to play again? ";
        cin >> again; 
        while ((tolower(again) != 'y' && tolower(again) != 'n') || cin.fail()) {
            cin.clear();
            cin.ignore(80,'\n');
            cout << "Invalid input, enter y or n: ";
            cin >> again;
        } 
    } while (tolower(again) == 'y');
    cout << "\nGame Terminated\n";

    /*
     * Example #2: Switch - what is printed if code is 458?
     * TO-DO: Once you've verified how the switch currently works, fix it so it works how you would expect
    */
    int code;
    cout << "\nWhat is your program code? ";
    cin >> code;
    while (code < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(80, '\n');
        cout << "code cannot be negative - re enter";
        cin >> code;
    }

    cout << "\nYou are majoring in ";
    switch (code) //Note: can switch on int or char or double (not string)
    { //switch tests for equality only
        //can have 16,384 cases
        case 457:
            cout << "CPA";
            break;
        case 458:
            cout << "CN&TS";
            break;
        default: //default is optional
            cout << "unknown program entered";
    }
    cout << endl;

    /*
     * Example #3: of switch, what is printed if F is entered?
     * TO-DO: Follow the steps in this example and write the appropriate code
    */
    char gender;
    cout << "enter F/M ";
    cin >> gender;
    while (gender != 'F' && gender != 'f' && gender != 'M' && gender != 'm')
    {
        cout << "answer must be m or F - re enter ";
        cin >> gender;
    }

    cout << "\nGender entered: ";
    switch (tolower(gender))
    {
        // Step 1: Allow both uppercase and lowercase to be entered
        case 'f':
            cout << "female";
            break;
            // Step 2: Move this outside of the switch
        case 'm':
            cout << "male";
            break;
    }
    cout << "endl";

    /*
     * Example #4: Rewrite nested if as a switch statement
     * TO-DO: Convert the if statement below to use a switch
    */
    double gpa;
    char grade;
    cout << "\n\nWhat is your letter grade? ";
    cin >> grade;

    while (grade != 'A' && grade != 'B' && grade != 'C' && grade != 'D' && grade != 'F')
    {
        cout << "answer must be A,B,C,D or F - reenter ";
        cin >> grade;
        grade = toupper(grade);
    }

    switch(grade) {
        case 'A':
            gpa = 4.0;
            break;
        case 'B':
            gpa = 3.0;
            break;
        case 'C':
            gpa = 2.0;
            break;
        default:
            gpa = 1.0;
    }
    
    cout << "\nYour gpa is " << gpa << endl;
    cout << "\nEnd of examples " << endl;

    system("pause");
}