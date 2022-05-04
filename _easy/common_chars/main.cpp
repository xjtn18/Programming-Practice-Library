//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



vector<string> commonChars(vector<string>& words) {
	  vector<string> commons;
	  vector<int> global_count(26, INT_MAX);
	  
	  // for the all the words in the front of the list
	  for (int i = 0; i < words.size() - 1; ++i){
			vector<int> word_count(26, 0);
			for (auto& c : words[i]) word_count[c - 'a'] += 1;
			
			// for each char in first word, see if they are in this word 
			for (int i = 0; i < 26; ++i)
				 global_count[i] = min(global_count[i], word_count[i]);
	  }
	  
	  // get the counts of the last word
	  for (auto& c : words[words.size()-1]){
			if (global_count[c - 'a'] > 0){
				 global_count[c - 'a'] -= 1;
				 commons.push_back(string() + c);
			}
	  }
		
	  return commons;
 }



int main(){
	vector<string> words = {"belal", "hello", "belly"};
	c_log ( commonChars(words) );


	return 0;
}



