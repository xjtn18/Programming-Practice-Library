//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


vector <int> CountSubarrays(vector <int> arr) {
  // Write your code here
  const int N = arr.size();
  vector<int> answer(N);
  vector<int> left(N);
  vector<int> right(N);
  c_log(arr);
  
  int maxx = arr[0];
  for (int i = 0; i < arr.size(); ++i){
    if (arr[i] > maxx){
      left[i] = i;
      maxx = max(maxx, arr[i]); // update max
    } else { // find where the next biggest element is
      int cnt = 0;
      for (int j = i-1; j >= 0 && arr[j] < arr[i]; --j){
        cnt++;
      }
      left[i] = cnt;
    }
  }
  
  maxx = arr[N-1];
  for (int i = N-1; i >= 0; --i){
    if (arr[i] > maxx){
      right[i] = N-i-1;
      maxx = max(maxx, arr[i]); // update max
    } else { // find where the next biggest element is
      int cnt = 0;
      for (int j = i+1; j < N && arr[j] < arr[i]; ++j){
        cnt++;
      }
      right[i] = cnt;
    }
  }
  
  // tally up the total for both directions
  for (int i = 0; i < N; ++i){
    answer[i] = left[i] + right[i] + 1; // plus 1 to include the subarray of just itself
  }
  
  return answer;
}



int main(){
	vector<int> arr;

	arr = {3, 4, 1, 6, 2};
	c_log(CountSubarrays(arr));

	return 0;
}



