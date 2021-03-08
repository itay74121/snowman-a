#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <exception>

#include "snowman.hpp"
using namespace std;

namespace ariel
{
    // here goes all the functions and stuff
    const char * hats [4] = {" _===_ ","  ___  \n ..... ","   _   \n  /_\\  ","  ___  \n (_*_) "};
    const char * noses [4]= {",",".","_"," "};
    const char * lefteye[4] = {".","o","O","-"};
    const char * righteye[4] = {".","o","O","-"};
    const char *leftarm [4]= {"<","\\","/"," "};
    const char * rightarm [4]= {">","/","\\"," "};
    const char * torsos [4]= {" : ","] [","> <","   "};
    const char * bases [4]= {" : ","\" \"","___","   "};

    // struct newexception : exception
    // {
    //     int code;
    //      const char * what () const throw ()
    //     {
    //         char buf[20];
    //         memset(buf,0,20);
    //         char * ret =(char*) calloc(50,sizeof(char));
    //         strcpy(ret,"Invalid code '");
    //         sprintf(buf,"%d",code);
    //         sprintf(ret+14,"%d",code);
    //         strcpy(ret+14+strlen(buf),"'");
    //         return ret;
    //     }
    // };
    // class except: public exception
    // {
    //     public:
    //     int code;
    //     except(int code)
    //     {
    //         this->code = code;
    //     }
    //     virtual const char* what()   
    //     {
    //         string res = "Invalid code '";
    //         res += code;
    //         res += "'";
    //         return res.c_str();
    //     }

    // };

    string snowman(int num)
    {
        string res;
        int numbers [8];
        memset(numbers,0,sizeof(int)*8);
        int temp = num;
        int count = 0;
        int current = 0;
        while(temp!=0&& count<=7)
        {
            current = temp%10;
            if (current>4 || current == 0)
            {
                string res = "Invalid code '";
                res+= std::to_string(num);
                res+="'";
                throw invalid_argument(res);
            }
            numbers[7-count] = current;
            temp /= 10;
            count++;
        }
        if (count != 8 || temp!=0)
        {
            string res = "Invalid code '";
            res+= std::to_string(num);
            res+="'";
            throw invalid_argument(res);
        }
        // otherwie continue;
        //printf("the number is: %d\n",numbers[0]);
        string head,middle,bottom;
        head += hats[numbers[0]-1];
        head = head + "\n";
        if(numbers[4] == 2)
        {
            head += "\\";
        }
        else
        {
            head += " ";
        }
        head = head + "(" + lefteye[numbers[2]-1] + noses[numbers[1]-1] + righteye[numbers[3]-1] + ")";
        if(numbers[5] == 2)
        {
            head += "/";
        }
        else
        {
            head += " ";
        }
        head += "\n";
        if(numbers[4] != 2)
        {
            middle += leftarm[numbers[4]-1];
        }
        else
        {
            middle += " ";
        }
        middle = middle +"("+ torsos[numbers[6]-1] +")";
        if(numbers[5] != 2)
        {
            middle += rightarm[numbers[5]-1];
        }
        else
        {
            middle += " ";
        }
        middle += "\n";
        bottom = bottom + " (" + bases[numbers[7]-1] +") " ;
        res = head + middle + bottom;
        return res;
    }
}



