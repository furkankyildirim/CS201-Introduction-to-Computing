//
//  Created by Furkan Kerim YILDIRIM on 3.05.2021.
//  furkanyildirim 28138

//  Question: Write a function that takes a integers as its parameter and returns
//  the smallest sum of all posible pairs of its elements.

//  For example, suppose your input vector is:
//  numbers = [4,9,10,2,7]

//  Your function should return value 6, because 4+2 is
//  the smallest summation of all possible pairs
//  {4+9, 4+10, 4+2, 4+7, 9+10, 9+2, 9+7, 10+2, 10+7, 2+7}

//  You can assume that the input vector size is greater than zero and
//  the vector contains only positive integers, and that you do not to
//  need to implement the main function.


#include <iostream>
#include <vector>
using namespace std;

int smallestSum(vector <int> numbers){
    int smallestNumber = INT_MAX;
    for (int i = 0; i < numbers.size()-1; i++){
        for(int j = i+1; j < numbers.size(); j++){
            if (numbers[i] + numbers[j] < smallestNumber){
                smallestNumber = numbers[i] + numbers[j];
            }
        }
    }
    return smallestNumber;
}


// For testing,
int main() {
    
    vector <int> numbers = {4,9,10,2,7};
    cout << smallestSum(numbers) << endl;
    return 0;
}
