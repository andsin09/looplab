/*
Andrew Sinha
Program: Loops Lap
Date: 10/30/2024
Extra: Arrays, grouping exercises into one, freeplay, random
*/

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){

// making all variables for the program
bool play = true;
string weekdays[7] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
string quote = " ";
string quotes[7];
string choice;
int pl = 1;
int el;
int health;
int damage;
int hp = 10;
int dmg = 4;
int xp = 0;
int code;
int pass = rand() % 999 + 1;
int energy = 5;
int supplies = 0;

//while loop will come in handy later.
    while(play){
        cout << "Welcome to my survival game!" << endl;
        for(int i = 1; i <= 14; i++){
            // p1 - quotes
            cout << "It is " << weekdays[i-1] << ". So, please enter a motivational quote for today." << endl;
            getline(cin, quote);
            quotes[i-1] = quote;



            //p2 - survival
            while(energy > 0){
                cout << "For today, what would you like to do - rest (+2 energy) or explore (+1 supplies, -1 energy) or attempt to open the lockbox (-1 energy, +?)?" << endl;
                cin >> choice;

                if(choice == "rest" || choice == "Rest"){
                    energy+=2;
                    cout << "You decided to rest for the day. +2 ENERGY. Energy total: " << energy << endl;
                }

                if(choice == "explore" || choice == "Explore"){
                    cout << "You have three options: Pharmacy, Store, and Home. Where to?" << endl;
                    cin >> choice;

                    if(choice == "pharmacy" || choice == "Pharmacy"){
                        el = rand() % 3 + 1;
                        cout << "You head to the abandoned pharmacy and find a level " << el << " zombie.  Do you attack? (y/n)" << endl;
                        cin >> choice;
                        if( el == 1 ){
                            health = 5;
                            damage = 2;
                        }

                        else if( el == 2 ){
                            health = 10;
                            damage = 4;
                        }

                        else{
                            health = 15;
                            damage = 6;
                        }
                        

                        if(choice == "y"){
                            cout << "You draw your weapon. What attack will you do?\n 1. Swing (" << dmg << " damage)\n 2. Kick (" << dmg/2 << ""
                        }
                    }
                }

            }
        }

    }
}