//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


char slowestKey(vector<int>& releaseTimes, string keysPressed){
	char key;
	int time;
	char slowest = keysPressed[0];
	int longest = releaseTimes[0];

	for (int i = 1; i < keysPressed.length(); ++i){
		key = keysPressed[i];
		time = releaseTimes[i] - releaseTimes[i-1];
		if (time > longest){
			longest = time;
			slowest = key;
		} else if (time == longest){
			slowest = std::max(key, slowest);
		}
	}

	return slowest;
}



int main(){
	vector<int> rt;
	string kp;

	rt = {40,80};
	kp = "bc";
	dlog( slowestKey(rt, kp) );

	return 0;
}



