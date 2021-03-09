#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <exception>

#include "snowman.hpp"
using namespace std;

namespace ariel
{
    // array of hats 
    const char * hats [4] = {" _===_ ","  ___  \n ..... ","   _   \n  /_\\  ","  ___  \n (_*_) "};
    // array of noeses and mouth 
    const char * noses [4]= {",",".","_"," "};
    // array for left eye 
    const char * lefteye[4] = {".","o","O","-"};
    // array for right eye 
    const char * righteye[4] = {".","o","O","-"};
    // aray for left eye 
    const char *leftarm [4]= {"<","\\","/"," "};
    // array for right arm 
    const char * rightarm [4]= {">","/","\\"," "};
    // array for torsos 
    const char * torsos [4]= {" : ","] [","> <","   "};
    // array for bases 
    const char * bases [4]= {" : ","\" \"","___","   "};
    /**
     * The snowman function takes an int with length of 8 digits,
     * and every digit must be between 1 to 4. If this two conditions
     * aren't met the function throws an invalid argument exception.
    */
    string snowman(int num)
    {
        string res; // resulting string 
        int numbers [8]; // a list to take all the numbers
        memset(numbers,0,sizeof(int)*8); // erase the array from junk data
        int temp = num; // set a temperay variable so we wouldn't lose original num 
        int count = 0; // set count to 0
        int current = 0; // current digit to add to array
        // run as long as temp is not 0 means we still have digits.
        // count <=7 since we cannot pass 8 digits 
        while(temp!=0&& count<=7) 
        {
            current = temp%10; // take the last digit
            if (current>4 || current == 0) // check if it is between 1 and 4 
            { // if not throw exception 
                string res = "Invalid code '";
                res+= std::to_string(num);
                res+="'";
                throw invalid_argument(res); // throwing here exception 
            }
            numbers[7-count] = current; // place the digit in the right place in the array 
            temp /= 10; // go to the next digit 
            count++; // increment the count 
        }
        // if the count of digits is not excatly 8 
        // that is maintained by the count wich is not 8 
        // or by the temp which might not be 0.
        if (count != 8 || temp!=0)
        { // throw an exception if so 
            string res = "Invalid code '";
            res+= std::to_string(num);
            res+="'";
            throw invalid_argument(res);
        }
        // create strings for the head the middle part 
        // and the bottom part of the snowman.
        string head,middle,bottom;
        // build the head part 
        head += hats[numbers[0]-1]; // put the hat of the snowman 
        head = head + "\n"; 
        // if the left hand is up like this '\'
        if(numbers[4] == 2)
        {
            head += "\\"; // add the upper hand next to the head 
        }
        else // other wise put a space there 
        {
            head += " ";
        }
        // build the rest of the head left eye nose and right eye 
        head = head + "(" + lefteye[numbers[2]-1] + noses[numbers[1]-1] + righteye[numbers[3]-1] + ")";
        // if the right hand is also up like this '/'
        if(numbers[5] == 2)
        {
            head += "/"; // add it 
        }
        else
        {
            head += " "; // otherwise add space 
        }
        head += "\n"; // finish head 
        //build the torso
        if(numbers[4] != 2) // if the left hand is not up like this '\'
        {
            middle += leftarm[numbers[4]-1]; //add it 
        }
        else
        {
            middle += " "; // otherwise add space
        }
        // build the rest of the torso 
        middle = middle +"("+ torsos[numbers[6]-1] +")";
        // if the right hand is not up like this '/'
        if(numbers[5] != 2)
        {
            middle += rightarm[numbers[5]-1]; // add it 
        }
        else
        {
            middle += " "; // other wise add a space 
        }
        middle += "\n"; // finish middle part 
        // build the bottom according to the easy template 
        bottom = bottom + " (" + bases[numbers[7]-1] +") " ;
        // concatnate all of the pieces together and set the result to res 
        res = head + middle + bottom;
        // return the result to the user 
        return res;
    }
}



