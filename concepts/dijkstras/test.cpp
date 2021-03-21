#include <iostream>

class test {
	int aa, bb;
public:
	test(int a, int b): aa(a), bb(b) {}
};

int main(){
	test t = test(1,2);
	return 0;
}

