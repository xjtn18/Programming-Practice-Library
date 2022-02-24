#include <mystd.h>


////////  Solution  ////////

#include <bits/stdc++.h>
using namespace std;



int solve(int N, vector<int> bags){
	int total = 0;
	for (int &num_candies : bags){
		total += num_candies;
	}

	return total % N;
}



int main(){
	ifstream cin("tests.txt"); //NOTE: Comment this line before submission

	int T; cin >> T; // the number of testcases
	// declare other input variables here
	
	for (int i = 1; i < T+1; ++i){
		int M, N;
		cin >> M;
		cin >> N;

		vector<int> bags(M);

		int cnt;
		for (int i = 0; i < M; ++i){
			cin >> cnt;
			bags[i] = cnt;
		}

		int ans = solve(N, bags); // pass input variables to 'solve'

		printf("Case #%d: %d\n", i, ans);
	}

	return 0;
}



///////////////////////////

