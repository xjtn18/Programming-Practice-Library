//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/17/21
//  File type: C++ source file
//  Description: Given a 32 bit unsigned int, count the number of bits it has with value 1.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



int hammingWeight(uint32_t n){
	int count = 0;
	uint32_t one = 1;
	do {
		count += n & one;
	} while ((n = n >> 1));
	return count;
}




int main(){
	dlog( hammingWeight(0b00000000000000000000000000001101) );
	dlog( hammingWeight(0b00000000000000000000000000000000) );
	dlog( hammingWeight(0b11111111111111111111111111111101) );
	return 0;
}



