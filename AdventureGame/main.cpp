#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
  srand(time(NULL));
  int gold = 0;
  int hp = 10; 
  int attack = 0;
  int block = 0;
  int turns = 0;

  cout << "Welcome player!\n Are you ready to begin your adventure? (y/n)\n\n";
  char answerYN = 'y';
  cin >> answerYN;

  if(answerYN == 'y') {
        cout << "\nGreat! Let's keep going.\n";
    } else if(answerYN == 'n') {
        cout << "\nThanks for playing! See you soon.\n";

        return 0;
    } 

  cout << "Let's start out adventure!\n\n";

  cout << "You have " << gold << " gold.\n";
  cout << "Your health is " << hp << ".\n\n";

  while (hp > 0) {
      attack = 0;
      block = 0;
      turns = 4;
        
      cout << "A fearsome monster appears!\n";
      cout << "You swing your blade as the monster readies to attack.\n\n";
      while (turns > 0) {
        attack = rand() % 4 + 1;
        block = rand() % 5;
        turns -= 1;
        
        if(block >= attack) {
          cout << "You blocked the beast's attack!\n";
        } else {
          cout << "The beast hit you!\n";
          hp -= attack;
          cout << "You now have " << hp << " health.\n";
        }

        if(hp <= 0) {
          cout << "You have died. Try again later.\n";
          return 0;
        }
        
      }
      gold += rand() % 10 + 1;
    
      cout << "You have defeated the monster!\n";
      cout << "\nYou now have " << gold << " gold.\n\n";

      if(hp < 5 || gold >= 5){
        cout << "You're in pretty rough shape, would you like to see the Doctor?\n\n";
        
        cin >> answerYN;

        if(answerYN == 'y') {
          hp = 10;
          gold -= 5;
          
          cout << "\nThe Doctor has brought you back to full health!\n";
          cout << "You're ready to get back on the road.\n\n";
        } else {
          cout << "\nAlright, if you say so.\n\n";
        }
      } else if(hp < 5 || gold < 5) {
        cout << "You're in pretty rough shape, would you like to see the Doctor?\n\n";
        
        cin >> answerYN;

        if(answerYN == 'y') {
          cout << "\nThat's too bad, looks like you don't have the necessary gold... awkward.\n\n";
        } else {
          cout << "\nAlright, if you say so.\n\n";
        }
      }
    
      cout << "Continue adventuring? (y/n)\n\n";
    
      cin >> answerYN;

      if(answerYN == 'y') {
            cout << "\nGreat! Let's keep going.\n";
        } else if(answerYN == 'n') {
              cout << "\nThanks for playing! See you soon.\n";

              return 0;
        } 
      
    
  } 
  
  
} 