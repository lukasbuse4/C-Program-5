//
// Created by lukas buse MAC on 4/20/21.
//

#ifndef PROGRAM5_LINKEDLIST_H
#define PROGRAM5_LINKEDLIST_H
#include "Friends.h"
#include <string>
using namespace std;

class LinkedList {

public:
//constructor
    LinkedList();

//getters and setters
//member functions
    void add_user(Friends);

    void add_friend(int u, int v);

    void display_network();

    Friends* get_recommendations(int);



private:
//member attributes
    Friends* head;
    Friends* tail;
    int length;

};
#endif //PROGRAM4_BIDDER_H
