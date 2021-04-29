#include <string>
#include <iostream>
#include <vector>
#include "../../debug.h"

using namespace std;

string readLongest(vector< vector<int> > memo, string a, string b, int x, int y){
	string s = "";
	while (x > 0 && y > 0 && memo[x][y] > 0){
		s.insert(s.begin(), a[x-1]); // insert at front of string
		x--; y--;
	}
	return s;
}


string longestCommonSubstring(string a, string b){
	//int** memo = new memo[a.length()][b.length()]
	vector< vector<int> > memo(a.length() + 1, vector<int>(b.length() + 1, 0));
	int x = 0, y = 0; // indicees to the end of our longest substring
	int maxx = 0;

	for (int i = 1; i < a.length() + 1; ++i){
		for (int j = 1; j < b.length() + 1; ++j){

			memo[i][j] = (a[i-1] == b[j-1]) ? memo[i-1][j-1] + 1 : 0;
			if (memo[i][j] > maxx){
				x = i;
				y = j;
				maxx = memo[i][j]; // update max
			}
		}
	}

	dlog(memo);

	return readLongest(memo, a, b, x, y);

}



int main(){
	dlog(longestCommonSubstring("cart", "art"));

	std::cout << ".";
	dlog(longestCommonSubstring("", ""), false);
	std::cout << ".\n";


	std::cout << ".";
	dlog(longestCommonSubstring("   ", "  "), false);
	std::cout << ".\n";

	dlog(longestCommonSubstring("agvgeeks", " vgek"));
	dlog(longestCommonSubstring(" skate", "board"));
	dlog(longestCommonSubstring("avacadopleasethanks", "acadoleaset"));

	return 0;
}


