//
//  Created by Furkan Kerim YILDIRIM on 15.03.2021.
//  furkanyildirim 28138

#include <iostream>
#include <string>
using namespace std;

void getInput(string exercise, int & min, int & reps, double & liftedWeight){
    
    cout << exercise;
    if (exercise != "Weight Lifting: ") {
        cin >> min >> reps;
    } else {
        cin >> min >> reps >> liftedWeight;
    }
}

bool inputCheck(int reps, int weight, int minute, double liftedWeight ){
    if (weight < 30){
        cout << "Weight out of range!" << endl;
        return false;
    } else if (liftedWeight <= 0 || liftedWeight > 35){
        cout << "Lifted weight out of range!" << endl;
        return false;
    } else if (reps < 0 || reps > 50){
        cout << "Reps out of range!" << endl;
        return false;
    } else if (minute < 0 || minute > 2000){
        cout << "Minute out of range!" << endl;
        return false;
    } else {
        return true;
    }
}

void calculateMET(int reps,string exercise, double & MET){
    if(exercise == "Lunges"){
        if(reps < 15){
            MET = 3;
        } else if(reps >= 15 && reps < 30){
            MET = 6.5;
        } else {
            MET = 10.5;
        }
    } else if (exercise == "Push-ups"){
        if(reps < 15){
            MET = 3;
        } else {
            MET = 7.5;
        }
    } else {
        if(reps < 25){
            MET = 5;
        } else {
            MET = 9;
        }
    }
};

void calculateWeightLiftMET(int reps, double liftedWeight, double & MET ){
    if(liftedWeight < 5){
        if(reps < 20){
            MET = 3;
        } else if (reps >= 20 && reps < 40){
            MET = 5.5;
        } else{
            MET = 10;
        }
    } else if (liftedWeight >= 5 && liftedWeight < 15){
        if(reps < 20){
            MET = 4;
        } else if (reps >= 20 && reps < 40){
            MET = 7.5;
        } else{
            MET = 12;
        }
    } else {
        if(reps < 20){
            MET = 5;
        } else if (reps >= 20 && reps < 40){
            MET = 9;
        } else{
            MET = 13.5;
        }
    }
}

void displayResults(double difference, double total, int weight, double lungeMET, double pushupMET, double pullupMET, double weightliftMET, double lungeCalorie, double pushupCalorie, double pullupCalorie, double weightliftCalorie){
    
    cout << "From lunges, you burned " << lungeCalorie << " calories." << endl;
    cout << "From push ups, you burned " << pushupCalorie << " calories." << endl;
    cout << "From pull ups, you burned " << pullupCalorie << " calories." << endl;
    cout << "From weight lifting, you burned " <<weightliftCalorie << " calories." << endl;
    cout << "You burned " << total << " calories." << endl;
    cout << endl;
    
    if(difference > 0){
        cout << "You did not reach your goal by " << difference << " calories." << endl;
        cout << "You need to do lunges " << difference * 200 / (lungeMET * 3.5 * weight) << " minutes more to reach your goal or," << endl;
        cout << "You need to do push ups " << difference * 200 / (pushupMET * 3.5 * weight) << " minutes more to reach your goal or," << endl;
        cout << "You need to do pull ups " << difference * 200 / (pullupMET * 3.5 * weight) << " minutes more to reach your goal or," << endl;
        cout << "You need to do weight lifting " << difference * 200 / (weightliftMET * 3.5 * weight) << " minutes more to reach your goal." << endl;
    } else if(difference < 0 ){
        cout << "You have surpassed your goal! You can eat something worth " << -difference << " calories :)" << endl;
    } else {
        cout << "Congratulations! You have reached your goal!" << endl;
    }
}

void computeResults(int weight, int goal, int repsLung, int repsPushUp, int repsPullUp, int repsWeightLift, int minLunge, int minPushUp, int minPullUp, int minWeightLift, int liftedWeight){
    
    double lungeMET, pushupMET, pullupMET, weightliftMET;
    double lungeCalorie, pushupCalorie, pullupCalorie, weightliftCalorie;
    double total, difference;
    
    calculateMET(repsLung, "Lunges", lungeMET);
    calculateMET(repsPushUp, "Push-ups", pushupMET);
    calculateMET(repsPullUp, "Pull-ups", pullupMET);
    calculateWeightLiftMET(repsWeightLift, liftedWeight, weightliftMET);
    
    lungeCalorie = minLunge * (lungeMET * 3.5 * weight) / 200;
    pushupCalorie = minPushUp * (pushupMET * 3.5 * weight) / 200;
    pullupCalorie = minPullUp * (pullupMET * 3.5 * weight) / 200;
    weightliftCalorie = minWeightLift * (weightliftMET * 3.5 * weight) / 200;
    
    total = lungeCalorie + pushupCalorie + pullupCalorie + weightliftCalorie;
    difference = goal - total;
    
    displayResults(difference, total, weight, lungeMET, pushupMET, pullupMET, weightliftMET, lungeCalorie, pushupCalorie, pullupCalorie, weightliftCalorie);
};

int main(){
    
    string name, errorMessage;
    int weight,goal;
    int repsLunge,repsPushUp,repsPullUp,repsWeightLift;
    int minLunge,minPushUp,minPullUp,minWeightLift;
    double liftedWeight;
    bool checker = true;
    
    cout << "Please enter your name: ";
    cin >> name;
    
    cout << "Welcome " << name << ", please enter your weight(kg): ";
    cin >> weight;
    
    cout << name << ", please enter minutes and repetitions in a week for the activities below." << endl;
    
    getInput("Lunges: ", minLunge, repsLunge, liftedWeight);
    getInput("Push Ups: ", minPushUp, repsPushUp, liftedWeight);
    getInput("Pull Ups: ", minPullUp, repsPullUp, liftedWeight);
    
    cout << name << ", please enter minutes, repetitions and lifted weight in a week for the activities below." << endl;
    getInput("Weight Lifting: ", minWeightLift, repsWeightLift, liftedWeight);
    
    cout << name <<", please enter your weekly calorie burn goal: ";
    cin >> goal;
    
    if(checker) checker = inputCheck(repsLunge, weight, minLunge, 1);
    if(checker) checker = inputCheck(repsPushUp, weight, minPushUp, 1);
    if(checker) checker = inputCheck(repsPullUp, weight, minPullUp, 1);
    if(checker) checker = inputCheck(repsWeightLift, weight, minWeightLift, liftedWeight);
    
    if(checker) computeResults(weight, goal, repsLunge, repsPushUp, repsPullUp, repsWeightLift, minLunge, minPushUp, minPullUp, minWeightLift,liftedWeight);
    
    return 0;
}






