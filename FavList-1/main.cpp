#include <iostream>
#include <string>
#include <vector> 
#include <algorithm> 
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
  vector<string> favGames = {"Spore", "Animal Crossing: New Leaf"};
  string input;
  
  cout << "Oh hey! Welcome back dude.\n\n";

  do {
    cout << "So what did you wanna do?\n";
    cout << "You can add, edit, delete, or view your list of favorite games.\n";
    cout << "If you're not interested in any of that, you can quit the program.\n\n";

    getline(cin, input);

    if(input == "add") {
        cout << "What game would you like to add?\n";
        
        getline(cin, input);
        if(!input.empty()) {
            favGames.push_back(input);
        }
        cout << "Cool! " << input << " has been added to your list.\n\n";
    } 

    else if(input == "edit") {
        vector<string>::iterator iter = favGames.begin();
        cout << "What game would you like to edit?\n";
        getline(cin, input);
        iter = find(favGames.begin(), favGames.end(), input);
        if(iter != favGames.end()) {
            cout << "What would you like to change " << input << " to?\n";
            getline(cin, input);
            *iter = input;
            cout << "Here's your updated list:\n";
            sort(favGames.begin(), favGames.end());
            for(int i = 0; i < favGames.size(); i++) {
                cout << i + 1 << ". " << favGames[i] << "\n";
            }
            cout << "\n";
            continue;
        } else {
            cout << "Hm. I couldn't find that one, try searching again.\n\n";
        }
        
    } 

    else if(input == "delete") {
        cout << "What game would you like to delete?\n";
        getline(cin, input);
        for(int i = 0; i < favGames.size(); i++) {
            if(input == favGames[i]) {
                favGames.erase(favGames.begin() + i);
                cout << "Alrighty then, " << input << " has been deleted.\n\n";
                continue;
            } 
        } 
    } 
    
    else if(input == "view") {
            sort(favGames.begin(), favGames.end());
            cout << "Here are your favorite games:\n";
            for(int i = 0; i < favGames.size(); i++) {
                cout << i + 1 << ". " << favGames[i] << "\n";
            }
            cout << "\n";
    }
    
    else if(input == "quit") {
        cout << "Are you sure you wanna head out?\n";
        getline(cin, input);
        if(input == "yes") {
            cout << "Okay, if you say so.\n";
            cout << "See you later, alligator!\n\n";
            return 0;
        } else {
            continue;
        }
    } 

    else {
        cout << "That's not an option on the list, try again.\n\n";
    }
      
  } while (true);
    return 0;
}