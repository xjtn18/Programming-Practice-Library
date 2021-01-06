//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 1/3/2021
//  File type: C++ source file
//  Description:
//
//////////////////////////////////////////////////////


#include <iostream>
#include "../debug.h"

using namespace std;



int trap(vector<int>& height){
	int water = 0, left = 0, right = height.size() - 1;
	int left_max = 0, right_max = 0;

	while (left < right){
		if (height[left] < height[right]){
			if (height[left] > left_max){
				left_max = height[left];
			} else {
				water += left_max - height[left];
			}
			left++;
		} else {
			if (height[right] > right_max){
				right_max = height[right];
			} else {
				water += right_max - height[right];
			}
			right--;
		}
	}
	return water;
}


int main(){
	vector<int> v;
	
	v = {4,2,0,3,2,5};
	log(trap(v)); // ans: 9

	v = {0,1,0,2,1,0,1,3,2,1,2,1,2};
	log(trap(v)); // ans: 7

	v = {2,0,1,0,1,0,2};
	log(trap(v)); // ans: 8
	

	v = {2,0,1,0,2,0,2};
	log(trap(v)); // ans: 7

	v = {2,0,1};
	log(trap(v)); // ans: 1

	v = {};
	log(trap(v)); // ans: 0
	return 0;
}





