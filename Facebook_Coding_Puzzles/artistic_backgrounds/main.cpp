//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description: Given a string that represents positions of Photographers, Actors, and Backgrounds,
//  					count the total # of unique artistic photos possible such that the distance between
//  					each of 3 objects in the shot is >= X and <= Y.
//////////////////////////////////////////////////////


//
// Solution
//
// The optimal solution can run in linear time and is as follows:
// Create 4 arrays with the same length as the input string.
// 1st array will store the number of photographers found prior to and including A[i];
// 2nd array will store the number of photographers found after and including A[i];
// 3rd array will store the number of backgrounds found prior to and including A[i];
// 4th array will store the number of backgrounds found after and including A[i];
// Pass through the string 2 times.
// The first pass we count the number of artistic photographs taken from left to right.
// We do this by stopping at every actor and multiplying the number of photographers
// more than X spaces away prior to the actor (which is stored in p_left[i-X]) and
// less that Y spaces away prior to the actor (which is the difference between p_left[i-X]
// and p_left[i-Y-1] (too include the Yth photographer) BY the likewise backgrounds post
// the actor. The product is the number of possible combinations (artitstic shots) that 
// can be taken with this actor. Add this product to your total sum and return your answer.
// Make sure to also consider photos taken from right to left.
//



#include <mystd.h>
using namespace std;




long long getArtisticPhotographCount(int N, string C, int X, int Y) {
	// Write your code here
	long long photos = 0;
  
	vector<long long> p_left(N), b_left(N), p_right(N), b_right(N);
	p_left[0] = (C[0] == 'P');
	b_left[0] = (C[0] == 'B');
	p_right[N-1] = (C[N-1] == 'P');
	b_right[N-1] = (C[N-1] == 'B');

	for (int i = 1; i < N; ++i){
		p_left[i] = p_left[i-1] + (C[i] == 'P');
		b_left[i] = b_left[i-1] + (C[i] == 'B');
	}

	for (int i = N-2; i >= 0; --i){
		p_right[i] = p_right[i+1] + (C[i] == 'P');
		b_right[i] = b_right[i+1] + (C[i] == 'B');
	}

	// bounds check
	auto SI = [](const vector<long long> &v, const int index) -> long long {
		if (index < 0 || index >= v.size()) return 0;
		else return v[index];
	};

	for (int i = 0; i < N; ++i){
		if (C[i] == 'A'){
			photos += (SI(p_left, i-X) - SI(p_left, i-Y-1)) * \
						 (SI(b_right, i+X) - SI(b_right, i+Y+1)) + \
						 (SI(p_right, i+X) - SI(p_right, i+Y+1)) * \
						 (SI(b_left, i-X) - SI(b_left, i-Y-1));
		}
	}

	return photos;
}



int main(){
	string input;

	input = "PAAB.ABA.P.";
		//	  "PA.B.......";
		//	  "P.AB.......";
		//	  "PA....B.....";
		//	  "P.A...B.....";
		//	  "P....AB.....";
		//	  "......BA..P.";
		//	  "...B...A..P.";
		//	  "...B.A....P.";
	dlog(getArtisticPhotographCount(input.length(), input, 1, 10));

	return 0;
}



