//
//  main.cpp
//  assignment 3
//
//  Created by Nolan Caissie on 2017-02-28.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#include <iostream>
#include "set.h"
using namespace std;

int main(){
    //create default object then take in user values
    Set s1;
    cin >> s1 ;
    cout << s1;
    //copy constructor and print values (will be same as s1)
    Set s2(s1);
    cout << "This is s2 it is a copy of s1: " << endl;
    cout << s2;
    //make dynamically created arrays and use constructor with
    //specified values and size
    //and print values
    int *A = new int[5];
    for(int i = 0; i < 5; i++)
        A[i] = i+1;
    int *B = new int[6];
    for(int i = 0; i < 6; i++) {
        B[i] = 3-i;
    }
    Set *pset = new Set(5, A);
    Set s3  = (*pset);
    Set s4(6, B);
    cout << "This is s3: " << endl;
    cout << s3;
    cout << "This is s4: " << endl;
    cout << s4;
    
    //use overload = assignment operator to have s3 be same as s4
    cout << "s3 will now be the same as s4" << endl;
    cout << "s4 is: " << endl << s4;
    s3 = s4;
    cout << "s3 is now also: " << endl << s3 << endl;
    
    //use overloaded == to see if two sets are equal
    cout << "Performing boolean operation to see if s3 and s4 are equal: ";
    cout << endl;
    if (s3 == s4){
        cout << "Turns out.. These two sets are the same" << endl;
    } else {
        cout << "Turns out.. These two sets are different" << endl;
    }
    
    //we will now pass a value to a method to be added to a set
    cout << "We will now add value 5 into the set of s4 then print set: ";
    cout << endl;
    s4.add(5);
    cout << s4;

}
