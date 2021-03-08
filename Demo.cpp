/**
 * Demo program for snowman exercise.
 * 
 * Author: Erel Segal-Halevi
 * Since : 2021-02
 */

#include "snowman.hpp"
#include <iostream>
#include <stdexcept>
using namespace std;


int main() {
	cout << ariel::snowman(41114411) << endl;   /* Should print:
_===_
(.,.)
( : )
( : )
	*/
	cout << ariel::snowman(43232124) << endl;   /* Should print:
   _
  /_\
\(o_O)
 (] [)>
 (   )
	*/
	try {
		cout << ariel::snowman(45) << endl;   // Exception - not a valid code
	} catch (exception& ex) {
	 	cout << "   caught exception: " << ex.what() << endl;  // should print "Invalid code '5'"
	}
}
