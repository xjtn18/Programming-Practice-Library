///////////////////////////////////////////////
// Author: Jacob Nardone
// Description: Priority class that is mutable, meaning the priorities of the specific nodes can be modified and will reposition
// 					themselves correctly in the heap.
///////////////////////////////////////////////
#pragma once

#include "../../debug.h"
#include <queue>
#include <limits>
#include <algorithm>
#include <functional>


template <typename C>
class MutablePQ {

	std::vector<Vertex> vec;
	int size;
	C comparator;

	void siftUp(int index){
		while (index > 0){
			int parent = (index - 1) / 2; // int vars always rounds down, so this is safe.
			if (this->comparator(vec[parent].getTotalWeight(), vec[index].getTotalWeight())){
				std::swap(vec[index], vec[parent]);
				std::swap(index, parent);
			} else { // we dont need to sift up anymore
				break;
			}
		}
	}


public:
	
	MutablePQ() : size(0) {}

	void push(const Vertex vtex){
		vec.push_back(vtex);
		std::push_heap(vec.begin(), vec.end(), this->comparator); // O(dlog n)
		size++;
	}

	const Vertex& top() const {
		return vec[0];
	}

	Vertex pop(){
		Vertex ret = vec[0]; // min element
		std::pop_heap(vec.begin(), vec.end(), this->comparator); // moves max to bottom and keeps heap invariant
		vec.pop_back(); // actually removes the max, which was just pushed to the back
		size--;
		return ret;
	}

	
	void update(int key, int newVal){
		int index = find(key);
		if (index == -1){
			return;
		}
		vec[index].setTotalWeight(newVal);
		siftUp(index);
	}


	bool empty() const {
		return vec.empty();
	}


	void print() const {
		for (const Vertex& v : vec){
			std::cout << v.getID() << " ";
		}
		std::cout << "\n";
	}

};


