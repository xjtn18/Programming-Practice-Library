//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/21/21
//  File type: C++ source file
//  Description: Create a stack that returns the mode of a stream
//  					of integers.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



#define umap unordered_map


class FreqStack {
	umap<int,int> freq;
	umap<int,stack<int>> m;
	int max_freq = 0;

public:

	void push(int x){
		max_freq = max(++freq[x], max_freq);
		m[freq[x]].push(x);
	}


	int pop(){
		int x = m[max_freq].top();
		m[max_freq].pop();
		if (m[max_freq].empty()) max_freq--;
		freq[x]--;
		return x;
	}

};





int main(){
	FreqStack fs;
	fs.push(1);
	fs.push(1);
	fs.push(2);
	fs.push(2);
	fs.push(2);
	fs.push(3);

	cout << fs.pop() << endl; // 2
	cout << fs.pop() << endl; // 2
	cout << fs.pop() << endl; // 1
	cout << fs.pop() << endl; // 3
	cout << fs.pop() << endl; // 2
	cout << fs.pop() << endl; // 1

	return 0;
}



