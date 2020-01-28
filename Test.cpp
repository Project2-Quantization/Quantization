#include <iostream>
#define MAX_LENGTH 1500
#define MIN_LENGTH 250

using namespace std;
using std::string;

 bool check(string input);
 bool checkSize(string inputText);
 bool checkChars(string inputText);

class Test{

public:

/*description:
the function recieves a input string
and check if input text size match matrix size - between 250 to 1500 bits
*/
 bool checkSize(string inputText){
        if(inputText.length() > MAX_LENGTH || inputText.length() < MIN_LENGTH)
            return false;
        return true;
}

/*description:
the function recieves a input string.
and check if chars of the input text contain only - 0 or 1
*/
bool checkChars(string inputText){

    for(int i = 0; i < inputText.length(); i++){
        if(inputText.at(i) != '0' && inputText.at(i) != '1'){
            return false;
        }
    }
    return true;
}

/*description:
1.the function recieves a input string
2. check if size of input is right
3. check if chars of input contain only chars 0 or 1
*/
bool check(string input){
    if(!checkSize(input))
        return false;
    if(!checkChars(input))
        return false;
    return true;
}

};
