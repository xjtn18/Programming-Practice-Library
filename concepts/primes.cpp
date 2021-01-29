#include <iostream>
#include <set>


std::set<int> primes;


bool isPrime(int num){
	if (primes.find(num) != primes.end())
		return true;
	if (num == 0 || num == 1)
		return false;
	if (num == 2)
		return true;
	if (num % 2 == 0)
		return false;

	for (int j = 3; j < num / 2; j+=2){
		if (num % j == 0)
			return false;
	}

	primes.insert(num);
	return true;
}



int main(){
	for (int i = 0; i < 24; i++){
		std::cout << i << " " << isPrime(i) << std::endl;
	}

	return 0;
}
