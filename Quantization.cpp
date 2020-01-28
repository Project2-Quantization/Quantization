#include <iostream>
#include <string>
#include <fstream>
#include "List.cpp"


using namespace std;
using std::string;

string divAndMatch(string);
string div(string);
void match(string);
string ascii(string);

class Quantization{
    public:
        //Properties.
        List * linkedList;
        string asciiCounter;
        int lastBitsIndex;
        int currentIndex;       //The current location in the input string.
    Quantization(){
        linkedList = new List();//create new list calling the List ctr.
        asciiCounter = "a";     //The beginning of the alphabetic matching value.
        currentIndex = 0;       //The beginning of the input str.
        lastBitsIndex = 0;      //For the extreme case.
    }
    //*******************************************************************************
    /*
    (1).
    Description: The function calculates the next available alphabetical value.
    */
    string ascii(string prev){
        string temp;
        int val, add;

        for(int i=0; static_cast<int>(prev.length())>i; i++)
        {
            prev[i] = toupper(prev[i]);
        }
        add = 1;
        for(int i=prev.length()-1; i>=0; i--)
        {
            val = (int)(prev[i])+add;
            if (val> (int)('Z'))
            {
                prev[i] = 'A';
                if (i == 0)
                {
                    prev = 'A' + prev;
                }
            }
            else
            {
                prev[i] = val;
                break;
            }
        }
        //Back to lower case character.
        for(int i=0; static_cast<int>(prev.length())>i; i++)
        {
            prev[i] = tolower(prev[i]);
        }
        return prev;
    }
    //*******************************************************************************
    /*
    (2).
    Description: The function cuts the binary-encoded string into sub-strings.
                 Each time the string is splitted, go over the linked list to see if such a binary sub string has already appeared.
                 if yes, move to a larger sub string.
    */
    string div(string str){
        int i;
        string subString = "";

        //The loop runs over the input string.
        for(i = 1; unsigned(i) <= unsigned(str.length() - currentIndex); i++){

           subString = str.substr (currentIndex, i);    //Cuts the string from curr, i  characters.

           //When the sub string is not exist in the list.
           if(!linkedList->searchElement(subString)){
                currentIndex += i;      //Increment.
                return subString;       //Return it in order to add a new node to the list.
           }
        }
        //Process end, out of the string range.
        if(unsigned(currentIndex) == unsigned(str.length()))
            return "end";
        /*
        Extreme case.
        The last bits exist in the linked list.
        In the caller function(divAndMatch) we will treat every single character until the end.
        */
        return "exist";
    }
    //*******************************************************************************
    /*
    (3).
    Description: The function recieves a binary substring from the input string.
                 Then the function inserts a new node to the list with a matching to the ascii counter.
    */
    void match(string binary) {
        linkedList->insert(asciiCounter, binary);
        //increase the ascii counter to the next round.
        asciiCounter = ascii(asciiCounter);
    }
    //*******************************************************************************
    /*
    (4).
    Description: The function calls the div function.
                 Then the function calls the match function with the output of div function.
    */
    //*******************************************************************************
    string divAndMatch(string str){
        string outputStr = "";
        string resDiv = "";

        while(true)
        {
            resDiv = div(str);
            //The process is done, when the last bits do not exist in the list.
            if(resDiv == "end")
                return outputStr;

            //The extreme case, When the last bits do exist in the list.
            //Treat every single character until the end.
            if(resDiv == "exist")
            {
                for( ; unsigned(currentIndex)<unsigned(str.length()); currentIndex++){
                    outputStr += linkedList->searchStr(string(1, str.at(currentIndex) ));
                    //convert the input to string.
                }
                return outputStr;
            }

            //Add to the list.
            match(resDiv);
            //concatenate.
            outputStr += linkedList->searchStr(resDiv);

            linkedList->printList(linkedList->head);

        }
        return outputStr;
    }
    
    
    //*******************************************************************************
    /*
    (5).
    Description: The function deletes the allocation of Quantization.
    */
    //*******************************************************************************
    
    void freeQuant(Quantization * q)
    {
        delete(q);
    }
};
