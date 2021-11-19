//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 11/13/21
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


double getMaxExpectedProfit(int N, vector<int> V, int C, double S) {
	double exp_profit = 0.0;
	double max_profit = 0.0;
	int opens = 0, skips = 0;

	for (int i = 0; i < N; ++i){
		if (V[i] > C || i == N-1){ // if we can only make profit by opening the mail room
			exp_profit += V[i];
			opens++;
		} else {
			max_profit += V[i];
			skips++;
		}
	}
	
	return exp_profit - (opens * C);
}



int main(){
	vector<int> in;

	in = {10,2,8,6,4};
	dlog(getMaxExpectedProfit(in.size(), in, 3, 0.5));



	return 0;
}



