//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/23/21
//  File type: C++ source file
//  Description: Given a list of coin denominations and a list describing how many of each coin you have, return all possible sums of those coins.
//////////////////////////////////////////////////////


#include <mystd.h>


struct Wrong { };

template <typename T>
inline void Assert(T result, T ans){
	static unsigned int number = 1;
	try {
		if ( !(result == ans) ){
			throw Wrong();
		}
		std::cout << "Assertion " << number << ": PASSED" << std::endl;

	} catch (Wrong e){
		std::cout << "Assertion " << number << ": FAILED  --  Expected ";
		dlog(ans, false);
		std::cout << ", got ";
		dlog(result);
	}
	number++;
}




int possibleSums(std::vector<int> coins, std::vector<int> quantity){
	int sums = 0;	


	return sums;
}



int main(){
	std::vector<int> coins, quantity;
	coins 		= {10, 50, 100};
	quantity 	= { 1,  2,   1};
	
	Assert( possibleSums(coins, quantity), 9 );
	Assert( possibleSums(coins, quantity), 0 );
	Assert( possibleSums(coins, quantity), 5 );
	Assert( possibleSums(coins, quantity), 0 );
	Assert( possibleSums(coins, quantity), 0 );
	Assert( possibleSums(coins, quantity), 0 );

	return 0;
}



