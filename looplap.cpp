/*
Andrew Sinha
Program: Loops Lap
Date: 10/30/2024
Extra: Arrays, grouping exercises into one, freeplay, random
*/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <array>
using namespace std;

int main(){

// making all variables for the program
bool play = true;
bool ed = false;
string weekdays[7] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
string quote = " ";
string quotes[7];
string choice;
string empty = " ";
int pl = 1;
int el;
int health;
int damage;
int hp = 15;
int dmg = 4;
int xp = 0;
int code;
int energy = 5;
int supplies = 0;
int choiice;
int coda = rand() % 999;

//while loop will come in handy later.
    while(play){
        cout << "Welcome to my survival game!" << endl;


            //p2 - survival
            while(energy > 0){
                
                for(int i = 1; i <= 56; i++){
                // p1 - quotes
                cout << "It is " << weekdays[i-1] << ". So, please enter a motivational quote for today." << endl;
                getline(cin, quote);
                quotes[i-1] = quote;


                cout << "For today, what would you like to do - rest (+2 energy) or explore (+1 supplies, -1 energy) or attempt to open the lockbox (-1 energy, +?)?" << endl;
                cin >> choice;

                if(choice == "rest" || choice == "Rest"){
                    energy+=2;
                    hp = 20;
                    cout << "You decided to rest for the day. +2 ENERGY. Energy total: " << energy << endl;
                }

                if(choice == "explore" || choice == "Explore"){
                    cout << "You have three options: Pharmacy, Store, and Home. Where to?" << endl;
                    cin >> choice;

                    if(choice == "pharmacy" || choice == "Pharmacy"){

                        el = rand() % 3 + 1;
                        cout << "You head to the abandoned pharmacy and find a level " << el << " zombie." << endl;
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


                            while(!ed){
                                cout << "You draw your weapon. What attack will you do?\n 1. Swing (" << dmg << " damage)\n 2. Kick (" << dmg/2 << " damage)" << endl;
                                cin >> choiice;
                            
                                if(choiice == 1){
                                    cout << "You swing and it connects. Minus " << dmg << " enemy health." << endl;
                                    health = health - dmg;
                                }

                                if(choiice == 2){
                                    cout << "You kick the zombie and deal " << dmg/2 << " damage to the enemy health." << endl;
                                    health = health - (dmg/2);
                                }

                                cout << "Enemy turn. They hit you, dealing " << damage << " damage." << endl;
                                hp = hp - damage;


                                cout << "Enemy health: " << health << endl;

                                
                                if(hp <= 0){
                                    cout << "You have died. GAME OVER." << endl;
                                    return 0;
                                }

                                if(health <= 0){
                                    cout << "The enemy has died, allowing you to explore." << endl;
                                    hp * 1.5;
                                    dmg * 1.5;
                                    el+=1;
                                    ed = true;
                                }
                            }

                            cout << "You find some suppliess in the pharmacy. Congrats!" << endl;
                            supplies += 2;
                            energy -= 1;
                    }
                
                    if(choice == "store" || choice == "Store"){
                        cout << "You explore the store, finding some supplies. Congrats!" << endl;
                        energy -= 1;
                        supplies += 2;
                    }
                
                    if(choice == "home" || choice == "Home"){
                        cout << "You explore the old home, and find a few supplies here and there. Congrats!" << endl;
                        energy -= 1;
                        supplies += 5;
                    }

                }
                
                //p3: lockbox.
                if(choice == "lockbox" || choice == "Lockbox"){
                    while(true){
                        cout << "You have decided to try to open the lockbox. Guess the three-digit code: " << endl;
                        cin >> choiice;
                        if(choiice == coda){
                            cout << "You opened the lockbox! You have gained 2 supplies!" << endl;
                            supplies += 2;
                            break;
                        }
                        
                        if(choiice == 0){
                            cout << "you have decided to leave." << endl;
                            break;
                        }
                    }
                    
                }

                else{
                    cout << "Invalid. Day Wasted." << endl;
                }

                getline(cin, empty);
                
                if(supplies == 10){
                    for(int i = 0; i < sizeof(quotes)/sizeof(quotes[0]); i++ ){
                        cout << quotes[i] << endl;
                    }
                    cout << "Congrats! You survived! Would you like to keep playing?" << endl;
                    cin >> choice;
                
                    if(choice == "y" || choice == "Y"){
                        cout << "Okay!" << endl;
                    }
                
                    else{
                        play == false;
                    }
                }    
                
                if(energy == 0){
                    cout << "You have not survived. The end." << endl;
                    break;
                }
                
            }
            
        }

    }
}
