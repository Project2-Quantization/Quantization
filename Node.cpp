#include <iostream> //For I/O.

using namespace std;

/*
Represents a binary sub-string matching to a specific alphabetical value + points to the next node.
*/
class Node{
    private:
        string alphabetic;
        string binary;
        Node * next;

    public:

 /*     void setAlphabetic(string alphabetic) { this->alphabetic = alphabetic; }
        void setBinary(string binary) { this->binary = binary; }*/
        //Ctr.
        Node(string alphabetic, string binary)
        {
            this->alphabetic = alphabetic;
            this->binary = binary;
            this->next = NULL;

            //cout<< this->alphabetic << this->binary << this->next;
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




