//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 11/28/21
//  File type: C++ source file
//  Description: Convert a roman numeral to its integer value.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;
#define umap unordered_map

umap<char, int> cmap = {
	{'I',             1},
	{'V',             5},
	{'X',             10},
	{'L',             50},
	{'C',             100},
	{'D',             500},
	{'M',             1000}
};

bool is_subtraction(char i, char j){
	return ((i == 'I' && (j == 'V' || j == 'X'))
			|| (i == 'X' && (j == 'L' || j == 'C'))
			|| (i == 'C' && (j == 'D' || j == 'M')));
}


int romanToInt(string s){
	int value = 0;
	int i = 0;
	while (i < s.length()){
		if (i < s.length()-1 && is_subtraction(s[i], s[i+1])){ // if its a subtraction case
			value += cmap[s[i+1]] - cmap[s[i]];
			i+=2;
		} else { // simply add the char value
			value += cmap[s[i]];
			i++;
		}
	}

	return value;
}


int main(){
	dlog(romanToInt("III")); // 3
	dlog(romanToInt("IV")); // 4
	dlog(romanToInt("XIV")); // 14
	dlog(romanToInt("I")); // 14
	dlog(romanToInt("VIII")); // 14
	dlog(romanToInt("XCIX")); // 90

	return 0;
}



