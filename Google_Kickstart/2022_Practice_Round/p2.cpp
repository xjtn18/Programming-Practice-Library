#include <mystd.h>


////////  Solution  ////////

#include <bits/stdc++.h>
using namespace std;


const set<char> VOWELS = {'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};


string solve(string kingdom){
	if (kingdom.back() == 'y' || kingdom.back() == 'Y'){
		return "nobody";
	} else if (VOWELS.count(kingdom.back())){
		return "Alice";
	} else {
		return "Bob";
	}

}



int main(){
	ifstream cin("tests.txt"); //NOTE: Comment this line before submission

	int T; cin >> T; // the number of testcases
	// declare other input variables here
	
	string kingdom;
	for (int i = 1; i < T+1; ++i){
		cin >> kingdom;
		string ans = solve(kingdom); // pass input variables to 'solve'
		printf("Case #%d: %s is ruled by %s.\n", i, kingdom.c_str(), ans.c_str());

	}

	return 0;
}



///////////////////////////

