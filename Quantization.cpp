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
        List *linkedList;
        string asciiCounter;
        int lastBitsIndex;//The current location in the input string.
        int currentIndex;
    Quantization(){
        linkedList = new List();//create new list by constructor of class List
        asciiCounter = "a";
        currentIndex = 0;
        //For the extreme case.
        lastBitsIndex = 0;
    }

/*
description:
1. when recieves from div function a regular binary string to add, we will use the match function.
   and concatenate to the output alpha-betic string.
2. when "end" string is recieved, we will concatenate the shortest matching.
3. when "....
*/
    string divAndMatch(string str){
      //str - the input string.
      string outputStr = "";
      string resDiv = div(str);
      cout<< "ResDiv: "<<resDiv<<endl;
      while( unsigned( resDiv.compare("end") ) != unsigned(0) && unsigned(currentIndex) != unsigned(str.length()-1))
      {
            cout<<"bghjfhjh"<<endl;
            //Add to the list
            match(resDiv);
            //concatenate
            outputStr += linkedList->searchStr(resDiv);

            linkedList->printList(linkedList->head);
            resDiv = div(str);
      }
      //Treat every single character until the end.
      if(resDiv.compare("end") == unsigned(0) ){
        cout<<"END!!!!!"<<endl;
        for( ; unsigned(currentIndex)<unsigned(str.length()); currentIndex++){
            outputStr += linkedList->searchStr(string(1, str.at(currentIndex) ));
            //convert the input to string.
        }
      }
      else if( unsigned(currentIndex) == unsigned(str.length()-1) )
            cout<<"CASE2!!!!!"<<endl;

      std::ofstream outfile ("str_from_quant.txt");
      outfile << outputStr << std::endl;
      outfile.close();
      return outputStr;
  }

//substring that does not exist in the linked list.
     string div(string str){
        int i;
        string subString = "";
        //extreme case 1- when holding on the last index.
        if(unsigned(currentIndex) == unsigned(str.length()-1)){
            if(!linkedList->searchElement(string(1, str.at(currentIndex))))
                //Add a new Node to the list
                return string(1, str.at(currentIndex));
            //when the last index exist in the list.
            return "sssss";
        }
        for(i = 1; unsigned(i) <= unsigned(str.length() - currentIndex); i++){
            cout<< "i   "<< i<<endl;
           subString = str.substr (currentIndex, i);

           cout<< "THE SUB: " << subString<<endl;
           //The sub string is not exist in the list, return it in order to add it to the list.
           if(!linkedList->searchElement(subString)){
                currentIndex += i;
                return subString;
           }

        }
        //Extreme case 2 - when reach the end.
        return "end";//in the caller function we will treat every single chat until the end.
        }
/*
description:
the function recieves a binary substring from the input string and inserts a new node to
the list with a matching to the ascii counter.
*/
    void match(string binary) {
    linkedList->insert(asciiCounter, binary);
    //increase the ascii counter to the next round.
    asciiCounter = ascii(asciiCounter);

    /*
     if(!linkedList.search(subString)){//regular case
        asciiCounter = ascii(asciiCounter);//check with hadasa
     }
     else{ //end of file case, need to match existing alphabet values from list, to the substring
       asciiCounter = linkedList.getAscii(subString);//get the alphabet value of given binary string from the list
     }
     linkedList.addNode(asciiCounter, binary)//check name and order of function
*/
    }

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
        //return back to lower case character.
        for(int i=0; static_cast<int>(prev.length())>i; i++)
        {
            prev[i] = tolower(prev[i]);
        }
        return prev;
    }

};

/*int main() {
    Quantization *q = new Quantization();
    string divRes = "";

    ifstream myReadFile;
    string str;

    //READ the file from project 1.
    myReadFile.open("text.txt");
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> str;
        }
    }
    myReadFile.close();
    cout<< "STR: "<< str<< endl;

    cout<<"The output: "<< q->divAndMatch(str)<<endl;

    q->linkedList->freeList(q->linkedList->head);
    return 0;
}*/





