//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 2/14/22
//  File type: C++ source file
//  Description: Given 2 strings that represent numbers, return the product of those numbers.
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;


/*
 * Solution:
 * 	Since strings can store arbitrarily large numbers that we cant contain in any single integer
 * 	variable, I went ahead and wrote up the code that simulates what multiplication by by hand
 * 	would look like. Iterated backwards through both numbers, multiplied all the digits to get
 * 	their partial product, and then summed all the partials together. Finally, I reversed the
 * 	answer (so we could save time pushing to the end of the strings) and then trimmed any leading
 * 	zeros.
 *
 * 	(M = length of num1, N = length of num2)
 * 	TC = O(M*N), nested linear interation through both numbers.
 * 	SC = O(M*N), allocating space for M partial products of length N.
 *
 * 	@Note: A faster and more space efficient way of solving this problem exists.
*/


string remove_leading_zeros(string number){
	auto start = number.find_first_not_of('0');
	return (start != string::npos) ? number.substr(start) : "0";
}


string multiply(string num1, string num2) {
	string result;
	vector<string> partials;

	for (int i = num1.length()-1; i >= 0; --i){
		string partial = "";
		int carry = 0;
		int bottom = num1[i] - '0';

		for (int j = num2.length()-1; j >= 0; --j){
			int top = num2[j] - '0';
			int product = top * bottom + carry;
			carry = product / 10;
			int remainder = product % 10;
			partial.push_back('0' + remainder);
		}
		if (carry) partial.push_back('0' + carry); // add any remaining carry
		partials.push_back(partial);
	}

	int len = partials[partials.size()-1].length() + partials.size()-1;

	int carry = 0;
	for (int i = 0; i < len; ++i){
		int sum = 0;
		for (int j = 0; j < min((int)partials.size(), i+1); ++j){
			if (i < partials[j].size()+j){
				sum += partials[j][i-j] - '0';
			}
		}
		sum += carry;
		carry = sum / 10;
		int remainder = sum % 10;
		result.push_back('0' + remainder);
	}
	if (carry) result.push_back('0' + carry);

	std::reverse(result.begin(), result.end());
	return remove_leading_zeros(result);
}



int main(){
	dlog(multiply("2", "3"));
	dlog(multiply("123", "456"));
	dlog(multiply("12", "10"));
	dlog(multiply("12", "3"));
	dlog(multiply("12", "0"));
	dlog(multiply("2", "1001"));
	dlog(multiply("3", "3"));
	dlog(multiply("0", "3"));
	dlog(multiply("2493", "132"));

	return 0;
}



