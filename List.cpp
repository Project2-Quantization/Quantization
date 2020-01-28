#include "Node.cpp"
#include <string>

void insert(string, string);

 class List{
    public:
        Node *head;
        Node *current;

        //constructor
        List()
        {
            head =NULL;
            current=NULL;
        }
    //*******************************************************************************
    /*
    (1).
    Description: The function creates a new Node.
                 Then the function inserts this new node to the end of the list.
    */
    void insert(string alpha, string bin)                                    //insert function, data is stored in add from function body
    {
        Node* newNode = new Node(alpha, bin);                                       //definition of add node, make new node and make node* point to it
        //when empty list.
        if (head != NULL)                                               //if head is pointing to object then we have list
        {
            current = head;                                             //make current pointer point to head
            while (current->getNext() != NULL)                               //check to see if end at list, is it the last node?
            {
                current = current->getNext();                                //advances current pointer to end of list
            }
            //Insert to the end.
            current->setNext(newNode);                                    //adds new node next to value already stored
        }
        else
        {
            head = newNode;                                             //if we don't have element in list
        }
    }
    //*******************************************************************************
    /*
    (2).
    Description: The function checks if an element exists in the linked list,
                 starting from the head of the list.
    */
    bool searchElement( string str)
    {
        Node* current = head; // Initialize current
        while (current != NULL)
        {
            if ( (current->getBinary()).compare(str) ==0)
                return true;
            current = current->getNext();
        }

        return false;
    }
    //*******************************************************************************
    /*
    (3).
    Description: The function checks weather a binary string is existing in a linked list.
    */
    string searchStr(string element)
    {
        Node* current = head; // Initialize current
        while (current != NULL)
        {
            if (current->getBinary() == element)
                return current->getAlphabetic();
            current = current->getNext();
        }
        return "-1";//element not exist
    }
    //*******************************************************************************
    /*
    (4).
    Description: This function prints contents of a linked list,
                 starting from the given node
    */
    void printList(Node* n)
    {
        cout << "The List:\n";
        while (n != NULL) {
            cout << "Alpha: " << n->getAlphabetic() << ", Binary: " << n->getBinary() << "--->";
            n = n->getNext();
        }
        cout<< endl;
    }
    //*******************************************************************************
    /*
    (5).
    Description: The function release the dynamic allocations of the project.
    */
    void freeList(Node* head) {
       Node* temp = NULL;
        while (head != nullptr)
        {
            temp = head;
            head = head->getNext();
            delete(temp);
        }
    }
};


