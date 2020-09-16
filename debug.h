#pragma once
#include <unistd.h>
#include <thread>
#include <vector>
#include <iostream>

#define PRINT_DEBUG 1 // set this to 0 if you dont want to see any of your debug prints

//declarations


// this template prints anything (singular value)
template <typename T>
void log(T x, bool nl = true, uint sleeptime = 5){
	if (!PRINT_DEBUG)
		return;
	std::cout << x;
	if (nl)
		std::cout << "\n";
	usleep(sleeptime * 100000);
}


// this template prints arrays
template <typename T>
void log(T* x, int len){
	for (int y = 0; y < len; y++){
		log(x[y], false);
		if (y != len-1){
			log(", ", false);
		}
	}
	log("");

}

template <typename T>
void log(std::vector<T> v){
	std::cout << '[';
	for (int i = 0; i < v.size(); ++i){
		std::cout << v[i];
		if (i != v.size()-1)
			std::cout << ", ";
	}
	std::cout << ']' << std::endl;
}

template <typename T>
void buffer(T input){
	std::cout << input << std::endl;
	std::string _;
	std::getline(std::cin, _);
}






