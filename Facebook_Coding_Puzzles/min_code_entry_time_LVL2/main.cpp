//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


long long min_rotation_time(int N, int next, int pos){
  long long t1 = abs(next - pos);
  long long t2 = (next > pos) ? N - next + pos : N - pos + next;
  return min(t1, t2);
}


long long getMinCodeEntryTime(int N, int M, vector<int> C) {
  //long long t1 = C[0] - 1;
  //long long t2 = N - C[0] + 1;
  //long long time = min(t1, t2);
  long long t1, t2;
  long long time = 0;
  int wheel1 = 1, wheel2 = 1;
  
  for (int i = 0; i < M; ++i){
    t1 = min_rotation_time(N, C[i], wheel1);
    t2 = min_rotation_time(N, C[i], wheel2);
    if (t1 < t2){
      wheel1 = C[i];
      time += t1;
    } else if (t1 > t2){
      wheel2 = C[i];
      time += t2;
    } else { // if both clock are equidistant from the next C[i] in the code
		 // move the clock that will give us a quicker time to the digit 2 spots ahead in the code
		 if (i == N-1) return time + t1; // or t2, doesnt matter
		 long long t1p, t2p;
		 t1p = min_rotation_time(N, C[i+1], C[i]); // pretend me moved wheel 1
		 t2p = min_rotation_time(N, C[i+1], wheel2);
		 long long min1 = min(t1p, t2p);
		 t1p = min_rotation_time(N, C[i+1], wheel1);
		 t2p = min_rotation_time(N, C[i+1], C[i]); // pretend me moved wheel 2
		 long long min2 = min(t1p, t2p);
		if (min1 < min2){
			wheel1 = C[i];
		} else {
			wheel2 = C[i];
		}
		time += t1; // or t2
	 }
	  dlog(wheel1);
	  dlog(wheel2);
	  dlog("Time : " + to_string(time));
	  dlog("");
  }
  
  return time;
}



int main(){
	vector<int> code;

	code = {4,6,2,6}; // 6
	code = {9,4,4,8}; // 6
	dlog(getMinCodeEntryTime(10, code.size(), code));

	return 0;
}



