//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <iostream>
#include <queue>
#include <mystd.h>
#include <runner.hpp>



// IDEA:
// 
//
// Time Complexity:
// 	Assuming there are minimal people arriving simultaneously at any given moment, the algorithm is linear time.
// 	Assuming the worst case scenario where everyone arrives at the same time, the algorithm is 2n.




std::vector<int> single_door(std::vector<int> arrival_times, std::vector<int> directions){
	int n = arrival_times.size();
	std::queue<int> enter_q, exit_q;
	std::vector<int> res(n, -1);
	int latest_use_time = -1;
	
	// pop prioritized then secondary queue
	auto pop_queues = [&](int j) -> void {
		// determine who has priority
		auto *priority = &exit_q, *secondary = &enter_q; // set priority to exit by default
		if (j-1 >= 0 && arrival_times[j-1] == arrival_times[j]-1 && directions[j-1] == 0){ // if someone entered the previous second
			std::swap(priority, secondary);
		}
		for (auto q : {priority, secondary}){ // O(2)
			while (!q->empty()){ // O(n) with the n dispersed evenly, leaving total algorithm running time as 2n.
				int pid = q->front();
				q->pop();
				res[pid] = std::max(arrival_times[pid], latest_use_time + 1);
				latest_use_time = std::max(res[pid], latest_use_time);
			}
		}
	};

	int j = 0;
	for (int i = 0; i < n; ++i){
		if (i > 0 && arrival_times[i] != arrival_times[i-1]){ // pop the queues
			pop_queues(j);
			j = i;
		}

		// populate the queues
		if (directions[i] == 0){
			enter_q.push(i);
		} else {
			exit_q.push(i);
		}
	}
	pop_queues(j);
	return res;
}



int main(){
	//c_log(single_door({0,0,0,0,0,0,3}, {0,0,0,0,1,1,0}));
	run_tests<std::vector<int>(std::vector<int>, std::vector<int>)>(single_door);
	return 0;
}




