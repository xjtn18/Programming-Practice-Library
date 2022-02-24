#include <mystd.h>


////////  Solution  ////////

#include <bits/stdc++.h>
using namespace std;



int h_index(vector<int> &counts, const int &start){
	int i;
	for (i = start; i > 0; --i){
		if (counts[i] >= i) break;
	}
	return i;
}

void remove(vector<int> &counts, const int &start){
	for (int i = start; i > 0; --i){
		counts[i]--;
	}
}

vector<int> solve(int N, vector<int> citations){
	vector<int> h(N), counts(N+2, 0);
	// bucket sort, linear time
	for (int i = N - 1; i >= 0; --i){
		counts[min(citations[i], N)]++;
	}

	// update counts
	for (int i = N; i > 0; --i){
		counts[i] += counts[i+1];
	}

	h[N-1] = h_index(counts, N);
	remove(counts, min(citations[N-1], N));

	for (int i = N-2; i >= 0; --i){
		h[i] = (citations[i+1] >= h[i+1]) ? h_index(counts, h[i+1]) : h[i+1];
		// remove this value from the counts array
		remove(counts, min(citations[i], N));
	}

	return h;
}


////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////
// Optimal solution, using a min heap

vector<int> _solve(int N, vector<int> &A){
	vector<int> h(N);
	int hindex = 0;
	min_heap<int> minheap;

	for (int i = 0; i < N; ++i){
		if (A[i] > hindex) minheap.push(A[i]);
		while (!minheap.empty() && minheap.top() <= hindex){
			minheap.pop();
		}
		hindex += (minheap.size() > hindex);
		h[i] = hindex;
	}

	return h;
}



int main(){
	ifstream cin("tests.txt"); //NOTE: Comment this line before submission

	int T; cin >> T; // the number of testcases
	// declare other input variables here
	
	for (int i = 1; i < T+1; ++i){
		int num_papers;
		cin >> num_papers;

		vector<int> citations(num_papers);

		int num_citations;
		for (int i = 0; i < num_papers; ++i){
			cin >> num_citations;
			citations[i] = num_citations;
		}

		vector<int> ans = _solve(num_papers, citations); // pass input variables to 'solve'

		cout << "Case #" << i << ":";
		for (int i = 0; i < num_papers; ++i){
			cout << " " << ans[i];
		}
		cout << "\n";
	}

	return 0;
}



///////////////////////////

