#include <iostream>
using namespace std;




bool isLongPressedName(string name, string typed){
	int i = 0, j = 0;
	int istart, jstart;
	while (j < typed.size()){
		if (name[i] != typed[j]) return false;

		istart = i;
		while (i < name.size() && name[i] == name[istart]) ++i;

		jstart = j;
		while (j < typed.size() && typed[j] == typed[jstart]) ++j;

		if (j - jstart < i - istart){
			return false;
		}
	}
	return i == name.size();
}



int main(){

	assert(isLongPressedName("alex", "aalexx") == true);
	assert(isLongPressedName("patty", "ppaty") == false);
	assert(isLongPressedName("xnhtq", "xhhttqq") == false);
	assert(isLongPressedName("alexd", "ale") == false);
	assert(isLongPressedName("pyplrz", "ppyypllr") == false);


	return 0;
}
