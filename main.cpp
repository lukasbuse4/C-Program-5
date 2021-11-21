#include <fstream>
#include <iostream>
#include "LinkedList.h"

using namespace std;

//prototypes
ifstream& open_file();
LinkedList* read_file(ifstream&);
int recommend_user(LinkedList *network);

//global variable
int numFriends;
string fileName;

//------------
int main(int argc, char **argv) {
    fileName = argv[1];

    cout << "Welcome to the Social Network!" << endl << endl;
    LinkedList* LL = read_file(open_file());

    bool stop = false;
    while(!stop){
        recommend_user(LL);

        cout << "Do you want to continue (yes/no)? ";
        string go;
        cin >> go;
        
        if (go == "YES" || go == "YEs" || go == "YeS" || go == "yES" || go == "Yes" || go == "yEs" || go == "yeS" || go == "yes"){
            getline(cin, go);
        }
        else if(go == "N0"|| go == "No" || go == "nO" || go == "no"){
            //exit program
            stop = true;
            cout << endl << "Goodbye!" << endl;
        }
    }

    return 0;
}

//attemept to open file- error message IF file cannot be opened.  **
ifstream& open_file(){
    ifstream* File = new ifstream();
    File->open(fileName);

    //check to make sure  file is open
    if (!File->is_open()) {
        cout << " File Not Found" << endl;
    }

    return *File;
}

//file object passed by Reference &, --> dynamically create linked list(HEAP, Dynamic memory allocation_
// read in each user-- create friend object
//return pointer to linkedlist
LinkedList* read_file(ifstream& File){
    cout << "Reading in the network file..." << endl;
    cout << endl;
    string x;
    numFriends;
    getline(File, x);
    numFriends = stoi(x);

    //read from file , make fried objects,
    //set name and ID,
    LinkedList *LL = new LinkedList();
    for (int i = 0; i < numFriends; i++){
        Friends* temp = new Friends();

        temp->setID(i);

        string name;
        getline(File, name);
        temp->setName(name);

        LL->add_user(*temp);
    }

    while (!File.eof()) {
        string x;
        int u;
        int v;

        

        getline(File, x, ' ');
        if(x == "")
            break;
        u = stoi(x);
        getline(File, x);
        v = stoi(x);

        LL->add_friend(u, v);
        LL->add_friend(v, u);
    }
    cout << "Successfully read in network file!" << endl;
    cout << endl;
    return LL;
}

//accpet pointer to linedlist
//prompy user for ID  (in range of 0-N)
int recommend_user(LinkedList *network){

    cout << "Enter an integer in the range 0 to "+ to_string(numFriends-1) +": ";
    string userInput;
    int num = -1;

    do{
        getline(cin, userInput);
        try{
            num = stoi(userInput);
        } catch(...){
            cout << "Error: input must be an integer between 0 and "+ to_string(numFriends-1) << endl;
            cout << "Enter an integer in the range 0 to "+ to_string(numFriends-1) +": ";
        }
    }while(!(num >= 0 && num < numFriends));

    Friends* returned = network->get_recommendations(num);

    cout << "The suggested friend for " << userInput << " is " << returned->getID() << endl << endl;

    return returned->getID();
}







/*
/**
   * @brief
   * NOTE: You should not have to change the path to the file OR move the input
   * file. as long as your fstream object looks like below, your file will open
   * properly -> Also yes, you may hardcode the file name for this program
   */
//fstream networkFile("../small_network_data.txt");
//