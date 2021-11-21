//
// Created by lukas buse MAC on 4/20/21.
//
#include "LinkedList.h"
#include<iostream>
using namespace std;

LinkedList::LinkedList() {
    head = NULL;
    tail = NULL;
}
//function- used to add user to linked list
void LinkedList::add_user(Friends addUser){
    Friends *temp = new Friends;
    temp->setName(addUser.getName());
    temp->setID(addUser.getID());
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        tail = temp;
    }

    else{
        tail->next = temp;
        tail = temp;
    }
}
// function - add friend ID(v) to friends vector of Friend Object w/ID(U)
void LinkedList::add_friend(int u, int v) { //U friend tryin gto find. v added on
    Friends *temp;
    temp = head;
    while(temp != NULL){
        if(temp->getID()==u){
            temp->addFriendsToNet(v);
            break;
        }
        else
            temp = temp->next;
    }
}
//Function displays network
void LinkedList :: display_network() {
    //do i do a displayFunction() or main function add displayFunction?
    Friends *temp;
    temp = head;
    while (temp != NULL) {
        cout << temp->getID() << " (" << temp->getName() << "): ";
        temp->displayVector();
        cout << endl;
    }
}

// accpets users ID and determine recommendation for that friend. - return friend Object
//recommendation based on most # friends.
Friends* LinkedList::get_recommendations(int userID) {
    //pseudo for algo
    //first accept userid
    //traverse linkedlist to find friend object matching id
    Friends *temp;
    temp = head;
    while(temp != NULL){
        if(temp->getID()==userID){
            break;
        }
        else
            temp = temp->next;
    }

    Friends *maxFriend = NULL;
    int maxIterator = -1;

    Friends *temp2;
    temp2 = head;
    while(temp2 != NULL){
        int tempIterator= 0;

        if(temp2->getID() == userID) {
            temp2 = temp2->next;
            continue;
        }

        for(int i=0; i < temp-> getFriends().size(); i++){
            for(int z=0; z< temp2-> getFriends().size(); z++){
                if(temp->getFriends().at(i) == temp2-> getFriends().at(z)){
                    tempIterator++;
                }
            }
        }

        if(tempIterator >= maxIterator){
            maxIterator = tempIterator;
            maxFriend = temp2;
        }

        temp2 = temp2->next;
    }

    return maxFriend;
}


    //create temp Friend var
    //use vector to make comparison to other friends vectors

    //traverse linkedlist
    //if userID matches temp Friend id, skip
    //compare userID vector to other nodes vectors
    //create max iterator to hold max
    //create temp iterator that keeps track of common friends
    //compare to max iterator and replace with bigger number
    //use another temporary friend variable to keep track of friend with most common
