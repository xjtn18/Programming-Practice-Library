#include <mystd.h>


////////  Solution  ////////

#include <bits/stdc++.h>
using namespace std;




double area_circle(int R){
	return M_PI * pow(R, 2);
}


double solve(int R, int A, int B){
	double total_area = 0;

	// draw circle at radius R first
	total_area += area_circle(R);

	bool a = true;

	while (R != 0){
		if (a) R *= A;
		else R /= B;
		total_area += area_circle(R);
		a = !a;
	}

	return total_area;
}



int main(){
	ifstream cin("tests.txt"); //NOTE: Comment this line before submission

	int T; cin >> T; // the number of testcases
	// declare other input variables here
	
	for (int i = 1; i < T+1; ++i){
		int R, A, B;
		cin >> R;
		cin >> A;
		cin >> B;

		double ans = solve(R, A, B); // pass input variables to 'solve'

		printf("Case #%d: %f\n", i, ans);
	}

	return 0;
}



///////////////////////////

