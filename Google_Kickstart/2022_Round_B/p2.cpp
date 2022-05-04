#include <mystd.h>


////////  Solution  ////////

#include <bits/stdc++.h>
using namespace std;



bool isPalindrome(long n){
	string number = to_string(n);
	int x = 0, y = number.length()-1;
	
	while (x < y){
		if (number[x] != number[y]){
			return false;
		}
		x++;
		y--;
	}

	return true;
}


int solve(long number){
	static unordered_set<long> palins;
	int cnt = 0;
	long root = sqrt(number);

	for (long j = 1; j <= root; ++j){
		if (number % j == 0){
			if (palins.count(j) || isPalindrome(j)){
				cnt++;
				palins.insert(j);
				long i = number / j;
				if (i != j && (palins.count(i) || isPalindrome(i))) {
					cnt++;
					palins.insert(i);
				}
			}
		}
	}

	return cnt;
}



int main(){
	ifstream cin("tests.txt"); //NOTE: Comment this line before submission

	int T; cin >> T; // the number of testcases
	// declare other input variables here
	
	for (int i = 1; i < T+1; ++i){
		long number;
		cin >> number;
		int ans = solve(number); // pass input variables to 'solve'

		printf("Case #%d: %d\n", i, ans);

	}

	return 0;
}



///////////////////////////

