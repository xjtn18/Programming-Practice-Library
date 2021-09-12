//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 9/6/21
//  File type: C++ source file
//  Description: Given a string of words, return a string with the words in reverse order.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



string reverseWords(string s) {
	string res = "";
	int front = s.length() - 1;
	int back;

	while (front >= 0){
		// skip all white space
		while ( front >= 0 && isspace(s[front]) ){ --front; }
		if (front == -1) break; // no more tokens to add
		back = front; // set token end marker

		// skip all non-white space
		while ( front >= 0 && !isspace(s[front]) ){ --front; }
		res += s.substr(front+1, back-front) + " ";
	}

	if (!res.empty()) res.erase(--res.end()); // erase last space

	return res;
}




int main(){
	string s;	

	s = "well howdy  hello   world";
	dlog( std::quoted(reverseWords(s)) );

	s = "   ";
	dlog( std::quoted(reverseWords(s)) );

	
	return 0;
}



