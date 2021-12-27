//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;

int numPairsDivisibleBy60(vector<int>& time){
	int sigma = 0;
	vector<int> m(60); // 0 - 59

	for (int &t : time){
		sigma += m[ceil(t/60.) * 60 - t];
		m[t % 60]++;
	}
	return sigma;
}


// Initial non-optimal solution
int _numPairsDivisibleBy60(vector<int>& time) {
	  unordered_map<int,int> m;
	  int max_time = INT_MIN;
	  for (int i = 0; i < time.size(); ++i){
			max_time = max(time[i], max_time);
			m[time[i]]++;
	  }
	  
	  int pairs = 0;
	  for (int i = 0; i < time.size(); ++i){
			int j = ceil(time[i]/60) * 60 - time[i];
			while (j <= max_time){
				 if (j != time[i]) pairs += m[j];
				 else pairs += m[j]-1;
				 j += 60;
			}
	  }
	  
	  
	  return pairs/2;
 }




int main(){
	vector<int> time;

	time = {30,20,150,100,40};
	cout << numPairsDivisibleBy60(time) << endl;

	return 0;
}



