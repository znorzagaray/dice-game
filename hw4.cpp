// Name:Zachariel Norzagaray
// date:October 21 2022
// program name:hw4.cpp
//program description:a program that works as the game IEC dice game


#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;
int p1Score=0, p2Score=0;

//this function make it be able to display the dice depending on what the randomizer gave for the number as it uses a parameter in order to display the face of the dice
void displayDice(int number){
    if(number==1){
      cout<< "- - - - -" <<endl;
      cout<< "|       |" <<endl;
      cout<< "|   *   |" <<endl;
      cout<< "|       |" <<endl;
      cout<< "- - - - -" <<endl;
    }
    if(number==2){
      cout<< "- - - - -" <<endl;
      cout<< "| *     |" <<endl;
      cout<< "|       |"<<endl;
      cout<< "|     * |" <<endl;
      cout<< "- - - - -" <<endl;
    }
    if(number==3){
      cout<< "- - - - -" <<endl;
      cout<< "|     * |" <<endl;
      cout<< "|   *   |" <<endl;
      cout<< "| *     |" <<endl;
      cout<< "- - - - -" <<endl;
    }
    if(number==4){
      cout<< "- - - - -" <<endl;
      cout<< "| *   * |" <<endl;
      cout<< "|       |" <<endl;
      cout<< "| *   * |" <<endl;
      cout<< "- - - - -" <<endl;
    }
    if(number==5){
      cout<< "- - - - -" <<endl;
      cout<< "| *   * |" <<endl;
      cout<< "|   *   |" <<endl;
      cout<< "| *   * |" <<endl;
      cout<< "- - - - -" <<endl;
    }
    if(number==6){
      cout<< "- - - - -" <<endl;
      cout<< "| *   * |" <<endl;
      cout<< "| *   * |" <<endl;
      cout<< "| *   * |" <<endl;
      cout<< "- - - - -" <<endl;
    }
}
int main()
{
//variables are declared
  srand(time(0));
  int dice1, dice2, dice3, answer, answer2, answer3;

//for loop is used for the number of rounds, it is set to 6 due there being 3 rounds and 2 turns per player
for(int x=1;x<=6;x++){
    //randomizes the dice for the beginning of each turn
    dice1 = rand() % 6 + 1 ;
    dice2 = rand() % 6 + 1 ;
    dice3 = rand() % 6 + 1 ;
    displayDice(dice1);
    displayDice(dice2);
    displayDice(dice3);
    
    cout << "would you like to reroll? (1-yes or 2-no)" << endl;
    cin >> answer ;
    //this if statement make it to be able to reroll if the user chooses too, and its able to change the face of the dice depending on whichc one the user wants to change
    if( answer == 1){
      cout << "would you like to reroll all or one? (1-all,2-one)" << endl;
      cin >> answer2;
      if(answer2 == 1){
        dice1 = rand() % 6 + 1 ;
        dice2 = rand() % 6 + 1 ;
        dice3 = rand() % 6 + 1 ;
      }else{
        cout << "which one would you like to reroll 1, 2 or 3? " << endl;
      cin >> answer3;
      }
      if(answer3 == 1){
        dice1 = rand() % 6 + 1 ;     
        displayDice(dice1);
        displayDice(dice2);
        displayDice(dice3);
      }else if(answer3 == 2){
        dice2 = rand() % 6 + 1 ;     
        displayDice(dice1);
        displayDice(dice2);
        displayDice(dice3);
      }else{
        dice3 = rand() % 6 + 1 ;     
        displayDice(dice1);
        displayDice(dice2);
        displayDice(dice3);
      }
    }else{
      cout<< "next turn" << endl;
    }
  //this is for the scoring if the for loop is an uneven number then it was player's 1 turn, if it was an even number then it was player's 2 turn, then the scores are changed by depending on what the dice faces were
  if(x%2!=0){
    if(dice1==dice3 && dice2==dice1 && dice2==dice3){
      p1Score = p1Score + 20 + dice2;
    }
    else if(dice1==dice3){
      p1Score = p1Score + 10 + dice1;
    } 
    else if(dice2 == dice3){
      p1Score = p1Score + 10 + dice2;
    }
    else if(dice1==dice2){
      p1Score = p1Score + 10 + dice1;
    }
    else{
      if(dice1>dice2 && dice1>dice3){
        p1Score+=dice1;
      }else if(dice2>dice1 && dice2>dice3){
        p1Score+=dice2;
      }else{
        p1Score+=dice3;
      }
    }
    cout << "Player 1 Score : " << p1Score << endl;
    cout << "turn for the other player 2" << endl; 
  }else{
    if(dice1==dice3 && dice2==dice1 && dice2==dice3){
      p2Score = p2Score + 20 + dice2;
    }
    else if(dice1==dice3){
      p2Score = p2Score + 10 + dice1;
    } 
    else if(dice2 == dice3){
      p2Score = p2Score + 10 + dice2;
    }
    else if(dice1==dice2){
      p2Score = p2Score + 10 + dice1;
    }
    else{
      if(dice1>dice2 && dice1>dice3){
        p2Score+=dice1;
      }else if(dice2>dice1 && dice2>dice3){
        p2Score+=dice2;
      }else{
        p2Score+=dice3;
      }
    }
    cout << "Player 2 Score : " << p2Score << endl;
    cout << "turn for the other player 1" << endl; 
  }
}
//calculates the winner or if there was a tie
if(p1Score>p2Score){
  cout << "Winner is Player 1! " << endl;
}
else if(p2Score>p1Score){
  cout << "Winner is Player 2! " << endl;
}
else{ 
  cout << "Tie game!" << endl;
}

cout << "Total score for Player 1 : " << p1Score << endl;
cout << "Total score for Player 2 : " << p2Score << endl;
return 0;
}