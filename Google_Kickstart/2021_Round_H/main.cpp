//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 11/13/21
//  File type: C++ source file
//  Description: Google Kickstart Round H 2021
//////////////////////////////////////////////////////


#include <mystd.h>
#include <fstream>
using namespace std;


////// Problem 1

void _solve(string S, string F){
	int ans = 0;

	for (int i = 0; i < S.length(); ++i){
		int dist = INT_MAX;
		for (int j = 0; j < F.length(); ++j){
			int diff = abs(F[j] - S[i]);
			int new_dist = min(diff, 26 - diff);
			dlog(new_dist);
			dist = min(new_dist, dist);
		}
		ans += dist;
	}

	cout << ans << endl;
}


////// Problem 2


map<char,set<char>> combos = {
	{'R', {'R'}},
	{'Y', {'Y'}},
	{'B', {'B'}},
	{'O', {'R', 'Y'}},
	{'P', {'R', 'B'}},
	{'G', {'Y', 'B'}},
	{'A', {'R', 'Y', 'B'}},
};


void __solve(int N, string P){
	int ans = 0;
	
	// use each color once
	for (auto &brush : {'R', 'Y', 'B'}){
		for (int i = 0; i < P.size(); ++i){
			if (P[i] == 'U') continue;
			bool stroke_started = false;
			while (i < P.size() && combos[P[i]].count(brush)){
				stroke_started = true;
				i++;
			}
			ans += stroke_started;
		}
	}

	cout << ans << endl;
}




////// Problem 3

unordered_map<string, string> m = {
	{"01", "2"},
	{"12", "3"},
	{"23", "4"},
	{"34", "5"},
	{"45", "6"},
	{"56", "7"},
	{"67", "8"},
	{"78", "9"},
	{"89", "0"},
	{"90", "1"}
};


void solve(int N, string S){
	string ans = "";

}


int main(){
	int T; cin >> T;
	int N;
	string S;
	for (int i = 1; i < T+1; i++){
		cin >> N;
		cin >> S;
		cout << "Case #" << i << ": ";
		solve(N, S);
	}

	return 0;
}



