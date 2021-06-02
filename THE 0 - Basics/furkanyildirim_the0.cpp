//
//  Created by Furkan Kerim YILDIRIM on 2.03.2021.
//  furkanyildirim 28138

#include <iostream>
#include <string>
using namespace std;

int main(){
    
    string studentName;
    int midtermGrade, finalGrade;
    int the1, the2, the3, the4, the5;
    int quiz1, quiz2, quiz3, quiz4;
    int plagCount = 0 , quizPlagCount = 0;
    double examAvarage, theAvarage, quizAvarage, quizGrade, theGrade, totalGrade;
    
    cout << "The purpose of this program is to calculate your CS201 grade." << endl;
    cout << "What is your name? ";
    cin >> studentName;
    cout << "Hello " << studentName << ", what are your midterm and final exam grades? ";
    cin >> midtermGrade >> finalGrade;
    
    if (midtermGrade == -100 || finalGrade == -100){
        cout << studentName <<", one of your midterm or final exam grade is -100, you will fail the course!" << endl;
        
    } else if (midtermGrade == -1){
        cout << studentName << ", you did not enter the midterm exam, you will fail the course!" << endl;

    } else if (finalGrade == -1){
        cout << studentName << ", you did not enter the final exam, you will fail the course!" << endl;

    } else if ((midtermGrade + finalGrade)/2 < 30){
        cout << studentName <<", your weighted exam average is less than 30, you will fail the course!" << endl;
        
    } else {
        cout << "What are the grades of your 5 take-home exams? ";
        cin >> the1 >> the2 >> the3 >> the4 >> the5;
        
        if (the1 == -100 ){ plagCount += 1; }
        if (the2 == -100 ){ plagCount += 1; }
        if (the3 == -100 ){ plagCount += 1; }
        if (the4 == -100 ){ plagCount += 1; }
        if (the5 == -100 ){ plagCount += 1; }
        
        if (plagCount < 2){
            cout << "What are the grades of your 4 quizzes? ";
            cin >> quiz1 >> quiz2 >> quiz3 >> quiz4;
            
            if (quiz1 == -100 ){ plagCount += 1; quizPlagCount += 1; }
            if (quiz2 == -100 ){ plagCount += 1; quizPlagCount += 1; }
            if (quiz3 == -100 ){ plagCount += 1; quizPlagCount += 1; }
            if (quiz4 == -100 ){ plagCount += 1; quizPlagCount += 1; }
            
            if (plagCount < 2 && quizPlagCount < 2){
                examAvarage = double(midtermGrade + finalGrade) / 2;
                theAvarage = the1 * 0.15 + the2 * 0.2 + the3 * 0.2 + the4 * 0.2 + the5 * 0.25;
                quizAvarage = double(quiz1 + quiz2 + quiz3 + quiz4) / 4;
                
                if (theAvarage / examAvarage >= 3){
                    theGrade = 0;
                } else if (theAvarage / examAvarage > 2 && theAvarage / examAvarage < 3) {
                    theGrade = theAvarage * (3- theAvarage / examAvarage);
                } else {
                    theGrade = theAvarage;
                }
                
                if (quizAvarage / examAvarage >= 3){
                    quizGrade = 0;
                    
                } else if (quizAvarage / examAvarage > 2 && quizAvarage / examAvarage < 3) {
                    quizGrade = quizAvarage * (3- quizAvarage / examAvarage);
                    
                } else {
                    quizGrade = quizAvarage;
                }
                
                totalGrade = examAvarage * 0.6 + theGrade * 0.2 + quizGrade * 0.2;
                
                cout << studentName << ", your weighted exam average is: " << examAvarage << endl;
                cout << studentName << ", your THE average is: " << theAvarage << " and you will get " << theGrade << " of it." << endl;
                cout << studentName << ", your quiz average is: " << quizAvarage << " and you will get " << quizGrade << " of it." << endl;
                cout << studentName << ", your grade for CS201 is: " << totalGrade << endl;
                
            } else if  (quizPlagCount >= 2){
                cout << studentName << ", at least two of your quiz grades are -100, you will fail the course!" << endl;
            } else {
                cout << studentName << ", one of your THE and one of your quiz grades is -100, you will fail the course!" << endl;
            }
            
        } else {
            cout << studentName << ", at least two of your THE grades are -100, you will fail the course!" << endl;
        }
    }
    return 0;
}
