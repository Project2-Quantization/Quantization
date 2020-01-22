#include <iostream> //For I/O.
#include <string>   //For strings.
#include "Quantization.cpp"
using std::string;

//Declaration of functions.
string ascii(string prev);

int main(){
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
}

string ascii(string prev)
{
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


