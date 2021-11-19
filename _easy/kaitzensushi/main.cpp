//////////////////////////////////////////////////////
//	Author: Jacob Nardone
//	Date created:
//	File type: C++ source file
//	Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



int getMaximumEatenDishCount(int N, vector<int> D, int K) {
	// Write your code here
	int eat = 0;
	int skipped = 0;
	unordered_map<int, int> last_eaten;
  
	for (int i = 0; i < N; i++){
		if (!last_eaten.count(D[i]) || i - last_eaten[D[i]] - skipped > K){
			//cout << D[i] << " : " << last_eaten[D[i]] << endl;
			last_eaten[D[i]] = i;
			eat++;
		} else {
			skipped++;
		}
	}
	return eat;
}



int main(){

	//dlog(getMaximumEatenDishCount(20, {1,2,1,1,1,1,1,2,5,4,3,2,3,1,2,1,2,3,2,1}, 1)); // expect 16
	vector<int> in = {1,1,5,1,5};
	dlog(getMaximumEatenDishCount(in.size(), in, 1)); // expect 2


	return 0;
}



