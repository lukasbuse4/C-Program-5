//
// Created by lukas buse MAC on 4/20/21.
//

#include "Friends.h"
using namespace std;
#include<iostream>

Friends::Friends(){}
Friends::Friends(string constructName, int constructID) {
    name = constructName;
    ID = constructID;
}
string Friends::getName() {
    return name;
}
//setName
void Friends::setName(string constructName) {
    name = constructName;
}
//getID
int Friends:: getID(){
    return ID;
}
void Friends:: setID(int constructID){
    ID = constructID;
}
void Friends::addFriendsToNet(int friendID) {
    myFriends.push_back(friendID);

    //Friend* friendA =new Friend()
    //friendA->myFriends.push_back(4)
    //friendA.addFriendsToNet(4)
}
bool Friends:: findFriend(int friendID){
    for(int i=0; i < myFriends.size(); i++){
        if(myFriends.at(i)== friendID){
            return true;
        }
    }
    return false;
}
void Friends:: displayVector(){
    cout << "[ " ;
    for(int i=0; i<myFriends.size(); i++){
        cout<< myFriends.at(i) << " ";
    }
    cout<< "]";
}
vector <int> Friends:: getFriends(){
    return myFriends;
}


