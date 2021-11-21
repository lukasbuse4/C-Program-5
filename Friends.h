//
// Created by lukas buse MAC on 4/20/21.
//

#ifndef PROGRAM5_FRIENDS_H
#define PROGRAM5_FRIENDS_H

#include <string>
#include <vector>
using namespace std;

class Friends{

public:
//constructor
    Friends();
    Friends(string, int);
    Friends* next;

//getters and setters
//member functions
    string getName();
    int getID();
    void setName(string);
    void setID(int);
    void addFriendsToNet(int);
    bool findFriend(int);
    void displayVector();
    vector <int> getFriends();

private:

    string name;
    int ID;
    vector <int> myFriends;

};

#endif //PROGRAM5_FRIENDS_H
