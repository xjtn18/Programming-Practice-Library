//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


int getMaxVisitableWebpages(int N, vector<int> L) {
  int maxvis = INT_MIN;
  vector<int> depth(N, 0);
  
  for (int i = 0; i < N; ++i){
    if (depth[i]) continue;

    vector<bool> reachable(N, false);
    int count = 0;
    int j = i;
    while (!reachable[j]){
      reachable[j] = 1;
      count++;
		if (count <= depth[j]){
			break;
		} else {
			depth[j] = count;
			j = L[j]-1; // subtract 1 because the pages are 1-base indexed
		}
    }

    maxvis = max(maxvis, count);
  }

  return maxvis;
}



int main(){
	vector<int> L;

	L = {4,3,4,5,3};
	//   1,2,3,4,5
	L = {3,3,4,3};
	dlog(getMaxVisitableWebpages(L.size(), L));

	return 0;
}



