//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;

// O(2N)
void encode_slower(std::string& text){
	unordered_map<char,int> count;

	for (char &c : text){
		count[c]++;
	}

	for (char &c : text){
		if (count[c] == 1){
			c = '(';
		} else {
			c = ')';
		}
	}
}



// O(N)
void encode(std::string& text){
	unordered_map<char,int> lastIndex;

	for (int i = 0; i < text.size(); ++i){
		char c = text[i];
		if (lastIndex.count(c)){
			text[lastIndex[c]] = ')';
			text[i] = ')';
		} else {
			text[i] = '(';
		}
		lastIndex[c] = i;
	}
}




int main(){

	std::string text;

	text = "severe";
	encode_slower(text); // "()()()"
	cout << text << endl;

	text = "severe";
	encode(text); // "()()()"
	cout << text << endl;

	return 0;
}



