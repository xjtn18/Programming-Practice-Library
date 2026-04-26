//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/8/22
//  File type: C++ source file
//  Description: Given an array of stock prices corresponding to each day,
//  	return the maximum profit you can make buying and selling during that period.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;





int maxProfit(vector<int> &prices){
	int max_profit = 0;
	int minn = INT_MAX;
	int maxx = 0;

	for (int &price : prices){
		maxx = std::max(maxx, price);
		if (price < minn){
			minn = price;
			maxx = 0;
		}
		max_profit = std::max(max_profit, maxx-minn);
	}

	return max_profit;
}



int main(){
	vector<int> prices;


	prices = {7,1,5,3,6,4};
	dlog(maxProfit(prices));

	prices = {7,3,5,6,10,1};
	dlog(maxProfit(prices));

	return 0;
}



