#include <iostream> //For I/O.
#include <string>   //For strings.
#include "Quantization.cpp"
#include "Test.cpp"

using std::string;

//Declaration of functions.
string inputTxt();
void outputTxt(string);

//*******************************************************************************
/*
(1)
Description: The main function.
             The function calls to the quantization functions.
*/
int main(){

    Quantization *q = new Quantization();
    string divRes = "";
    string str  = "";

    str = inputTxt();
    cout<< "STR: "<< str<< endl;

    //Input Validation.
    Test *testString = new Test();
    if(!testString->check(str)){
        cout<< "ERROR input string from project1 invalid" <<endl;
        return 1;
    }

    //The Quantization on valid input only.
    divRes = q->divAndMatch(str);
    cout<<"The output: "<< divRes<<endl;

    outputTxt(divRes);

    q->linkedList->freeList(q->linkedList->head);
    q->freeQuant(q);
    return 0;
}
//*******************************************************************************
/*
(2)
Description: The function reads the input file from the previous project into a string.
*/
string inputTxt(){
    ifstream myReadFile;
    string str;

    //READ the file from project 1.
    myReadFile.open("binary_file.txt");
    if (myReadFile.is_open()) {
        while (!myReadFile.eof()) {
            myReadFile >> str;
        }
    }
    myReadFile.close();
    return str;
}
//*******************************************************************************
/*
(3).
Description: The function creates the input of the next project.
             The function writes the string of the AB values to the output file.
*/
void outputTxt(string str){
    std::ofstream outfile ("str_from_quant.txt");
    outfile << str << std::endl;
    outfile.close();
}
