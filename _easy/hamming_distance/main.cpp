//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



int hammingDistance(int x, int y){
	int count = 0;
	int x_or = x ^ y;
	while (x_or > 0){
		count += x_or & 1;
		x_or >>= 1;
	}
	return count;
}


int main(){
	hammingDistance(4, 1);
	return 0;
}



