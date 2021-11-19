//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


long long getMaxAdditionalDinersCount(long long N, long long K, int M, vector<long long> S) {
	sort(S.begin(), S.end());

	long long dividend = S[0] - 1 - K;
	long long divisor = K + 1;
	auto f = [&]() { return (dividend + divisor - 1) / divisor; };
	long long allowed = f();
	say(allowed);

	for (int i = 1; i < M; ++i){
   	int spots_between = S[i] - S[i-1] - 1;
		dividend = spots_between - K*2;
		allowed += f();
	}
	say(allowed);

	dividend = N - S[M-1] - K;
	allowed += f();
	say(allowed);

	return allowed;
}




int main(){
	dlog(getMaxAdditionalDinersCount(6, 1, 2, {3,6}));
	dlog(getMaxAdditionalDinersCount(6, 1, 2, {3}));

	return 0;
}



