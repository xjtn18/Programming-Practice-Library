//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;




string other(int nu, int de) {
        
        if (nu == 0)  return "0";
        string res;
        unordered_map<long long int, int> mp;
        bool flag = ((nu < 0 && de >= 0) || (nu >= 0 && de < 0));
        long long numerator = nu;
        long long denominator = de;
        numerator = abs(numerator);
        denominator = abs(denominator);
        
        long long dividend = numerator/denominator;
        long long rem = numerator%denominator;
        res = std::to_string(dividend);
        
        if(rem == 0)
            return (flag ? '-' + res : res);
        
        res.push_back('.');


			say(res);
			say(numerator);
			say(denominator);


        while(rem != 0)
        {
            numerator = rem*10;
            if(mp.find(numerator) != mp.end())
            {
                int p = mp[numerator];
                res = res.substr(0,p) + '(' + res.substr(p) + ')';
                break;
            }
            
            mp[numerator] = res.size();
            dividend = numerator/denominator;
            res.push_back(dividend+'0');
            rem = numerator%denominator;
        }
        
        if(flag)
            res.insert(res.begin(), '-');
        return res;
    }




string to_decimal(int numerator, int denominator){
	long long div = 1LL * numerator / denominator;
	long long rem = abs(1LL * numerator) % denominator;

	string ans;
	if (div == 0 && numerator / (1.L * denominator) < 0) ans += '-';
	ans += to_string(div);
	if (rem == 0) return ans;
	ans += '.';
	long long numer = numerator;
	long long denom = denominator;
	numer = abs(numer);
	denom = abs(denom);

	unordered_map<long long, int> m;
	// This stores previous remainders.
	// Key is the remainder and value is position in the answer
	// 	that we got this remainder.


	while (rem != 0){
		numer = rem * 10;
		if (m.count(rem)){
			ans = ans.substr(0, m[rem]) + '(' + ans.substr(m[rem]) + ')';
			break;
		}
		m[rem] = ans.length();

		div = numer / denom;
		ans += ('0' + div); // convert div to char
		rem = numer % denom;
	}

	return ans;
}




int main(){
	dlog(to_decimal(0,-7));
	dlog(to_decimal(1,7));
	dlog(to_decimal(5,22));
	dlog(to_decimal(50,7));
	dlog(to_decimal(-2147483648, -1));
	dlog(to_decimal(-50, 80));
	dlog(to_decimal(-5, 3));
	dlog(to_decimal(5, -3));
	dlog(to_decimal(-7, 8));
	dlog(to_decimal(-1, -2147483648));
	//dlog(other(-1, -2147483648));



	return 0;
}




