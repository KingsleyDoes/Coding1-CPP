#include "functions.h"
using namespace std;

int main() {
  cout << "Hello! Welcome back to your favorite shows list.\n";

  do {
    cout << "\nYou can either Add, Edit, Remove, or View your list.\n";
    cout << "If none of that interests you, you may Quit the program.\n\n";

    vector<string> favShows;

    Load(favShows);
    
    string input;
    getline(cin, input);

    if(input == "Add" || input == "add") {
      Add(favShows);
      continue;
    }

    else if(input == "Edit" || input == "edit") {
      Edit(favShows);
      continue;
    }

    else if(input == "Remove" || input == "remove") {
      Remove(favShows);
      continue;
    }
      
    else if(input == "View" || input == "view") {
      View(favShows);
      continue;
    }

    else if(input == "Quit" || input == "quit") {
      Quit(favShows);
      cout << "\nSee you next time!\n";
      break;
    }

    else {
        cout << "\nThat's not an option on the list, try again.\n\n";
    }
    
  } while (true);

  return 0;
}