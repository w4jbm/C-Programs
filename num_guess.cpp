/* num_guess - Guess a random number...
 *
 * Build by:
 *   $ g++ -o num_guess num_guess.cpp
*/

#include <iostream>
// #include <cstdlib>
// #include <ctime>

using namespace std;

int main()
{

    srand (time(NULL));
    int number = rand() % 100+1;
    int guess = 0;
    int count = 0;

//  cout << number << endl; // Just for testing purposes...
 
    do {
      cout << "Guess a number between 1 and 100: ";
      
      count++;
      
      cin >> guess;

      /* The following catches input that is not an integer by looking
         for a failure of cin, then clearing the error, and then jumping
         (over 256 characters) to the next "newline". */
         
      if (!cin) {
          cout << "Please pick an integer!" << endl;
          cin.clear();
          cin.ignore(256, '\n');
          continue; // Go back and ask for another guess...
          }

      if ( guess > number)
          { cout << "Too high.\n" << endl; }
      else if ( guess < number )
          { cout << "Too low.\n" << endl; }
      else
          { cout << "That's right! It only took you " << count << " guesses!" << endl;
          exit(0); }
    } while ( number != guess );
    
return 0;
}
