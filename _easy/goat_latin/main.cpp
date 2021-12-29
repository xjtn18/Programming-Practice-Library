//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


bool is_vowel(const char &c){
	return c == 'a' || c == 'e' || c == 'i' ||
		c == 'o' || c == 'u' || c == 'A' ||
		c == 'E' || c == 'I' || c == 'O' ||
		c == 'U';
}


string toGoatLatin(string sentence) {
	int n = sentence.length();
	string translation = "";
	int word = 1;

	for (int i = 0; i < n; ++i){
		 string new_word = "";
		 int start = i;
		 while (i < n && !isspace(sentence[i])) i++;
		 
		 if (is_vowel(sentence[start])){
			  new_word = sentence.substr(start, i - start);
			  new_word += "ma";
		 } else {
			  new_word = sentence.substr(start+1, i - start - 1);
			  new_word += string(1,sentence[start]) + "ma";
		 }
		 for (int j = 0; j < word; ++j) new_word += 'a';
		 translation += new_word + ' ';
		 word++;
	}

	return translation;
}







