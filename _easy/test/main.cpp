//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;





int main(){
	std::cout << "hello there" << std::endl;
	dlog("hello there");
	int arr[] = {1,2,3};
	alog(arr, 3);

	std::vector<int> v {1,2,3};
	c_log(v);
	return 0;
}



