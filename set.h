//
//  set.h
//  assignment 3
//
//  Created by Nolan Caissie on 2017-02-28.
//  Copyright © 2017 Nolan Caissie. All rights reserved.
//

#ifndef set_h
#define set_h
#include <iostream>
#include <string>
//set class
class Set {
public:
    Set();
    Set(int, int []);
    Set(const Set &);
    ~Set();
    Set & operator = (const Set &);
    //Set operator + (Set); <-- no time for this
    bool operator == (const Set &) const;
    //bool hasMember(int); <-- no time for this
    void add(int);
    friend std::istream & operator >> (std::istream &, Set &);
    friend std::ostream & operator << (std::ostream &, const Set &);
private:
    void grow();
    int *data;
    int capacity;
    int size;
};

#endif /* set_h */
