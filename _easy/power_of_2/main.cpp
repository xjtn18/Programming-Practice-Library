//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/28/21
//  File type: C++ source file
//  Description: Check if a given number is a power of 2.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


#define say cout <<
#define shut << endl



// 10000000000000000000000000000000  <- highest power of 2 contained in an 32-bit int

/*
 * 2 = 10
 * 2 - 1 = 1
 * 4 = 100
 * 4 - 3 = 1
 * 8 = 1000
 * 
 *
 *
 *
 *
*/



/*
 * 0100 = 1011
 *
 *
 */


bool isPowerOfTwo(int n){
	if (n < 1) return false;
	return (n & n-1) == 0;
}



int main(){
	
	//for (int i = 0; i < 20; ++i){ say isPowerOfTwo(i) shut; }

	int a = 14;
	int a_minus_1 = a-1;
	cout << ((a & a_minus_1) == 0) << endl;
	
	


	say std::bitset<8>(a) shut;
	say std::bitset<8>(~a) shut;


	return 0;
}



