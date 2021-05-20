//
//  set.cpp
//  assignment 3
//
//  Created by Nolan Caissie on 2017-02-28.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#include "set.h"
//default constructor
Set::Set(){
    capacity = 4;
    data = new int[capacity];
    size = capacity;
}
//constructor with specified size and values
Set::Set(int n, int array[]){
    if (n <= 0) {
        n = 4;
    }
    capacity = n;
    size = n;
    data = array;
}

//copy constructor
Set::Set(const Set & obj){
    capacity = obj.capacity;
    size = obj.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++){
        data[i] = obj.data[i];
    }
}

//assignment operator overload (essentially same as copy constructor)
//except this will not create a new object but rather replace an old one
Set & Set::operator=(const Set &obj){
    if (data != 0){
        delete [] data;
    }
    capacity = obj.capacity;
    size = obj.size;
    data = new int[capacity];
    for (int i = 0; i < size; i++){
        data [i] = obj.data[i];
    }
    return *this;
}

//destructor to delete all set values
Set::~Set(){
    delete [] data;
    
}

//private function to grow array in case we want to add a value
void Set::grow(){
    capacity ++;
    int *temp = new int[capacity];
    for (int i = 0; i < size; i++){
        temp[i] = data [i];
    }
    delete [] data;
    data = temp;
}

//add another value to the set object
void Set::add(int newData){
    if (size >= capacity) {
        grow();
    }
    data[size] = newData;
    size++;
}

//overloaded input operator which displays messages
//to user and takes in all info for set and stores into
//objects array
std::istream & operator >> (std::istream &in, Set &obj){
    int arrSize = 0;
    std::string restOfLine;
    std::cout << "Please enter array size.\n";
    std::cin >> arrSize;
    std::getline(std::cin, restOfLine);
    std:: cout << "Please enter in your set.\n";
    while(arrSize < obj.capacity && arrSize >= 4){ //if array isnt big enough grow it
        obj.grow();
    }
    for(int i = 0; i < arrSize; i++) {
        in >> obj.data[i];
    }
    obj.size = arrSize;
    return in;
}

//overloaded output operator
std::ostream & operator << (std::ostream &out, const Set &obj){
    out << "The following set is:" << std::endl;
    out << "{";
    for(int i = 0; i < obj.size; i++){
        out << obj.data[i];
        if (i < obj.size -1) {
        out << ", ";
        }
    }
    out << "}" << std::endl;
    return out;
}


//assuming no duplicate data
bool Set::operator == (const Set & g) const{
    if (size != g.size){
        return false;
    }
    
    bool isIn;
    for (int i = 0; i < size; i++) {
        isIn = false;
        for (int j = 0; j < size; j++) {
            if (data [i] == g.data[j]){
                isIn = true;
            }
        }
        if (!isIn){
            return false;
        }
    }
    return true;
}
