//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



// Have 2 indices pointing to the end of each version string.
// Scan up the string until you either reach the end or you reach a '.'
// Keep track of the respective numbers between each correlating '.' and compare them.
// If you break the main loop and one of the version string still has more to go,
// than that one is the larger one if it contains a character greater than '0'.
//
//
// TC
// Linear in the size of the smaller string.
//
// SC
// We will be allocating string space to hold the largest number in between periods.
// 
//
// Notes:
// This solution could avoid doing string concatenation by using std::string.substr() and using
// 2 indices for each version string to keep track of the substring parameters.
//



int compare_versions(string v1, string v2){
	int i = 0, j = 0;
	string a = "", b = "";
	int numa, numb;

	while (i < v1.size() || j < v2.size()){
		while (i < v1.size() && v1[i] != '.') a += v1[i++];
		while (j < v2.size() && v2[j] != '.') b += v2[j++];
		numa = (a == "") ? 0 : stoi(a);
		numb = (b == "") ? 0 : stoi(b);
		if (numa > numb) return 1;
		else if (numa < numb) return -1;
		a.clear(); b.clear();
		i++; j++;
	}

	return 0;
}



int main(){
	assert(compare_versions("1.003.2", "1.3.02") == 0);
	assert(compare_versions("1.003.2", "5.1.3.02") == -1);
	assert(compare_versions("1.003.2", "01.3.21") == -1);
	assert(compare_versions("1.2", "01.3.21") == -1);
	assert(compare_versions("1", "12") == -1);
	assert(compare_versions("001.3", "1.2") == 1);
	assert(compare_versions("1.9.0", "1.9") == 0);
	assert(compare_versions("1.9.1", "1.8") == 1);
	assert(compare_versions("1", "1.8") == -1);
	assert(compare_versions("1.0.0.0.01", "1.0.0") == 1);

	return 0;
}



