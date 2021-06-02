//
//  Created by Furkan Kerim YILDIRIM on 31.03.2021.
//  furkanyildirim 28138

#include <iostream>
#include <string>
#include "strutils.h"
using namespace std;

bool wordChecker(string word);
string getSecretWord(string playerOne, string playerTwo);
void getGuessWord(string secretWord, string & checkedCharacters, int & remainingRight);
void getGuessLetter(string secretWord, string & checkedCharacters, string & enteredCharacters, int & remainingRight);
void setShownSecretWord(string secretWord, string checkedCharacters, string & shownSecretWord);

int main(){
    string playerOne, playerTwo, option, secretWord, shownSecretWord = "", checkedCharacters = "", enteredCharacters = "";
    int remainigRight = 6;
    
    cout << "Welcome to the HANGMAN GAME" << endl;
    cout << "---------------------------" << endl;
    
    cout << "Player one, please enter your name: ";
    cin >> playerOne;
    
    cout << "Player two, please enter your name: ";
    cin >> playerTwo;
    
    cout << "OK "<< playerOne << " and " << playerTwo << ". Let's start the game!" << endl;
    
    secretWord = getSecretWord(playerOne, playerTwo);
    cout << playerTwo << ", you have 1 free guess, after that you will lose limbs!" << endl;
    
    while (remainigRight > 0) {
        setShownSecretWord(secretWord, checkedCharacters, shownSecretWord);
        cout << "The word is: " << shownSecretWord << endl;
        if (shownSecretWord.find("-") != string::npos){
            cout << playerTwo <<", do you want to guess the word(1) or guess a letter(2)? ";
            cin >> option;
            
            if (option == "1"){
                getGuessWord(secretWord, checkedCharacters, remainigRight);
            } else if (option == "2"){
                getGuessLetter(secretWord, checkedCharacters, enteredCharacters, remainigRight);
            } else {
                cout << "Invalid option!" << endl;
            }
        } else {
            cout << "Congratulations " << playerTwo << ", you won!" << endl;
            cout << playerTwo << " won the game!";
            break;
        }
        if (remainigRight == 0) {
            cout << playerTwo << " lost the game :(";
            break;
        }
    }
    return 0;
}

string getSecretWord(string playerOne, string playerTwo){
    string secretWord;
    while (true){
        cout << playerOne << ", please input the word you want " << playerTwo << " to guess: ";
        cin >> secretWord;
        ToLower(secretWord);
        
        if (wordChecker(secretWord)){
            return secretWord;
        } else {
            cout << "Invalid word! Try again." << endl;
        }
    }
}

void getGuessWord(string secretWord, string & checkedCharacters, int & remainingRight){
    string input;
    cout << "Your guess: ";
    cin >> input;
    ToLower(input);

    if (wordChecker(input)){
        if (secretWord == input) {
            checkedCharacters = "";
            for(int i = 0; i < secretWord.length(); i++){
                if(checkedCharacters.find(secretWord.at(i)) == string::npos){
                    checkedCharacters += secretWord.at(i);
                }
            }
        } else {
            remainingRight --;
            if (remainingRight == 5){
                cout << "You have no free guess left." << endl;
            } else if (remainingRight == 4 || remainingRight == 3){
                cout << "You have lost a leg!" << endl;
            } else if (remainingRight == 2 || remainingRight == 1){
                cout << "You have lost an arm!" << endl;
            } else {
                cout << "You have lost a head! GAME OVER!" << endl;
            }
        }
    } else {
        cout << "Invalid entry! Try again." << endl;
    }
}

void getGuessLetter(string secretWord, string & checkedCharacters, string & enteredCharacters, int & remainingRight){
    string input;
    cout << "Your guess: ";
    cin >> input;
    ToLower(input);
    
    if(input.length() == 1 && wordChecker(input)){
        if (secretWord.find(input) != string::npos && enteredCharacters.find(input) == string::npos) {
            checkedCharacters += input;
        } else if (enteredCharacters.find(input) != string::npos && enteredCharacters.find(input) >= 0){
            cout << "Guess entered before! Try again." << endl;
        } else {
            remainingRight --;
            if (remainingRight == 5){
                cout << "You have no free guess left." << endl;
            }
            else if (remainingRight == 4 || remainingRight == 3){
                cout << "You have lost a leg!" << endl;
            } else if (remainingRight == 2 || remainingRight == 1){
                cout << "You have lost an arm!" << endl;
            } else {
                cout << "You have lost a head! GAME OVER!" << endl;
            }
        }
        enteredCharacters += input;
    } else {
        cout << "Invalid entry! Try again." << endl;
    }
}

void setShownSecretWord(string secretWord, string checkedCharacters, string & shownSecretWord){
    shownSecretWord = "";
    for (int i = 0; i < secretWord.length(); i++){
        if (checkedCharacters.find(secretWord.at(i)) != string::npos){
            shownSecretWord += secretWord.at(i);
        } else{
            shownSecretWord += "-";
        }
    }
}

bool wordChecker(string word){
    for (int i = 0; i < word.length(); i++){
        if(char(word.at(i)) < 'a' || char(word.at(i)) > 'z'){
            return false;
        }
    }
    return true;
}


