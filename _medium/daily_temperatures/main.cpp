//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



/*
We will traverse backwards down the list of temps.
Answer[last] will be set to zero; it will always be zero.
When we see than the temperature in the following day was higher that the temp in the current day,
	we will set answer[current] = 1.
Else, if the following day was the same temp or cooler, we will use the answers array to jump
	to each day that was hotter than that following day.
	For each hotter day, we will see if that day was hotter than the day we are currently evaluating.
	If we never find a hotter day while jumping to the end, then we set answer[current] = 0.
	Else if we do find a hotter day while jumping, then the answer[current] will equal the index difference
		between the current day the next hottest day we found.
Using the answer array to make jumps is a little shortcut we can use to find the next hottest day (if it exists)
rather than just doing a linear search down the array to find it.
We can prove that doing the jumps will not skip over potential answers because of the following:
	Let temp(y) represent the temp of the 'y'th day.
	Let C = the current day we are evaluating.
	Let D = the day after the current day.
	Let X = the number of days after D before we saw a temp higher than temp(D).

	We only make a jump when we know that temp(C) is hotter than temp(D).
	Therefore, since we also know that the X days after D were cooler than temp(D), then using the transitve
	property, C > D > (D through D+X).
	So we can safely assume that from C to D+X (exclusive), there exists no day in which a temp higher than
		temp(C) was recorded.

	It's best to think of this problem as a dynamic programming problem.
*/




vector<int> dailyTemperatures(vector<int>& temperatures){
	int n = temperatures.size();
	vector<int> answer(n);
	answer[n-1] = 0; // last value will always be 0: there can't be a hotter day after.
	int temp = temperatures[n-1];
	int cnt = 0;

	for (int i = n-2; i >= 0; --i){
		if (temperatures[i] < temperatures[i+1]){
			answer[i] = 1;
		} else {
			int j = i+1;
			while (temperatures[i] >= temperatures[j] && answer[j] != 0){
				j += answer[j];
			}
			answer[i] = (temperatures[i] < temperatures[j]) ? j-i : 0;
		}
	}

	return answer;
}




int main(){
	vector<int> t;

	t = {73,74,75,71,69,72,76,73};
	c_log(dailyTemperatures(t));

	t = {5};
	c_log(dailyTemperatures(t));

	t = {1,1};
	c_log(dailyTemperatures(t));

	t = {1,2};
	c_log(dailyTemperatures(t));

	t = {2,1};
	c_log(dailyTemperatures(t));

	t = {2,1,3};
	c_log(dailyTemperatures(t));
	t = {4,1,3};
	c_log(dailyTemperatures(t));

	return 0;
}



