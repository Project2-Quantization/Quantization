#include <iostream> //For I/O.

using namespace std;

/*
Description:
The class Represents a binary sub-string matching to a specific alphabetical value + points to the next node.
*/
class Node{
    private:
        string alphabetic;
        string binary;
        Node * next;

    public:
        //Ctr.
        Node(string alphabetic, string binary)
        {
            this->alphabetic = alphabetic;
            this->binary = binary;
            this->next = NULL;
        }
        //Getters.
        string getAlphabetic() { return alphabetic; }
        string getBinary() { return binary; }
        Node* getNext(){ return this->next;}
        //Setters.
        void setNext(Node* node)
        {
            this->next = node;
        }

};


