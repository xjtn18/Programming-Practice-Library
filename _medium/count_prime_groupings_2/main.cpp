//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <iostream>
#include <Debug.hpp>

using namespace std;


bool is_prime(string n_str){
	int n = stoi(n_str);
	if (n==2){
		return true;
	} else if (n==1 || n%2==0){
		return false;
	} else {
		int j = 3;
		while (j < n/2){
			if (n%j==0) return false;
			j+=2;
		}
		return true;
	}
}



int count_prime_groups(string s){
	// Count the number of unique groupings of a
	// number s such that each group represents a prime number, leaving order the same.
	// This function uses DP:
	// Assume for a string of length N, we have a value P 
	// that stores the correct number of prime groupings 
	// of substring s(0, N-1). Then this means our answer 
	// to the number of prime groupings in the total string.
	
	int n = s.length();
	if (n==0) return 0;
	vector<int> memo(n, 0); // memo[i] represents the number of prime groupings in the substring s[0] to s[i];

	for (int i = 0; i < n; ++i){
		for (int j = 0; j < i+1; ++j){
			string tail = s.substr(j, (i-j)+1);
			int sub_int = stoi(tail);
			if (j != i && sub_int%2 == 0){ // small optimization
				j = i-1; // send to loop the end becuase last digit might be 2, which is prime by itself.
				continue;
			}
			bool prime_tail = is_prime(tail);
			if (j != 0){
				memo[i] += memo[j-1] * prime_tail;
			} else {
				memo[i] += prime_tail;
			}
		}
	}
	return memo[n-1];
}



int main(){
	dlog(count_prime_groups("323")); // 2
	return 0;
}



