//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



double getMaxExpectedProfit(int N, vector<int> V, int C, double S) {
	double profit = 0.0;
	double room_value = 0.0;
	const double not_S = 1-S;

	for (int i = 0; i < N; ++i){
		double robbed = V[i] * S;
		double safe = (room_value + V[i]) * not_S;
		dlog(i+1);
		dlog(robbed);
		dlog(safe);

		if (i == 1 || i == 4 || i == 3 || i == 5){ // we open the room
			//dlog(i+1);
			profit += room_value + V[i] - C;
			room_value = 0.0;
			
		} else { // we skip the room
			room_value = max(robbed, safe);
		}
	}
  
	return profit;
}



int main(){
	vector<int> mail;

	mail = {10, 2, 8, 6, 4};
	dlog(getMaxExpectedProfit(mail.size(), mail, 3, 0.5));

	return 0;
}



