//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 10/3/21
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;

#define say cout <<
#define shut << endl

typedef unsigned int uint;


int firstBadVersion(int n, function<bool(int)> isBadVersion){
	// standard binary search problem
	int low = 1, high = n;
	while (low < high){
		int mid = ((uint)low + (uint)high) >> 1;
		if (isBadVersion(mid)){
			if (!isBadVersion(mid-1)){
				return mid;
			}
			high = mid-1;
		} else if (!isBadVersion(mid)){
			if (isBadVersion(mid+1)){
				return mid+1;
			}
			low = mid+1;
		}
	}
	return 1;
}



// My original solution:
// When setting a value for an index, if the current snap_id is greater
// than the length of that values snapshot array, then that means
// we didnt change that value in the last snap_id - arr[index].size()
// snaps, so we itaratively add the last value in that array that many times
// before adding the new value. Still runs much better than adding to every 
// cells value array every time we snap; uses less time and space, but optimal 
// would be to use a map shown further below.

class SnapshottArray {
public:
	int sid = 0;
	vector<vector<int>> arr;

	SnapshottArray(int length)
		: arr(length, vector<int>({0}))
	{ }

	void set(int index, int val){
		if ((int)arr[index].size() == sid+1){
			arr[index][sid] = val;

		} else {
			while ((int)arr[index].size() < sid){
				arr[index].push_back(arr[index][arr[index].size()-1]);
			}
			arr[index].push_back(val);
		}
	}

	int snap(){
		return sid++;
	}

	int get(int index, int snap_id){
		return arr[index][min(snap_id, (int)arr[index].size()-1)];
	}

};



//
// OPTIMAL
//

class SnapshotArray {
public:
	unordered_map<int, map<int, int>> a;
	int sid = 0;

	SnapshotArray(int length){
		// length doenst really matter since we're using maps
	}

	int snap(){
		return sid++;
	}

	void set(int index, int val) { 
		a[index][sid] = val; 
	}

	int get(int index, int snap_id) {
		auto it = a[index].upper_bound(snap_id);
		return it == a[index].begin() ? 0 : prev(it)->second;
	}
};




int main(){
#if 0
	function<bool(int)> f;
	
	f = [](int x){ return x >= 4; };
	dlog( firstBadVersion(5, f) ); // expecting 4

	f = [](int x){ return x >= 8; };
	dlog( firstBadVersion(13, f) ); // expecting 8

	f = [](int x){ return x >= 1; };
	dlog( firstBadVersion(13, f) ); // expecting 1

	f = [](int x){ return x >= 1702766719; };
	dlog( firstBadVersion(2126753390, f) );

	f = [](int x){ return x >= 1; };
	dlog( firstBadVersion(1, f) );
#endif

	// Problem 2

	//["SnapshotArray","set","snap","set","get"]
	//[[3],[0,5],[],[0,6],[0,0]]
	SnapshotArray ssa(3);
	ssa.set(0,5);
	ssa.snap();
	ssa.set(0,6);
	ssa.set(0,7);
	say ssa.get(0,1) shut;



	m2log(ssa.a);

	return 0;
}



