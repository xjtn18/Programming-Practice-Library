//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 12/10/21
//  File type: C++ source file
//  Description: Given a list of transactions, return all transactions that exceed $1000
//  					or occurred in another city in less that or exactly 60 minutes after
//  					a previous transaction by the same person.
//////////////////////////////////////////////////////


#include <mystd.h>
#define umap unordered_map
using namespace std;



struct Transaction {
	int index;
	string name;
	int time;
	int amount;
	string city;

	Transaction(int _index, string str)
		: index(_index)
	{
		stringstream ss(str);
		string s;
		int i = 0;
		while (getline(ss, s, ',')){
			if (i == 0) 		name = s;
			else if (i == 1) 	time = stoi(s);
			else if (i == 2) 	amount = stoi(s);
			else if (i == 3) 	city = s;
			++i;
		}
	}


	bool operator <(const Transaction &other) const {
		return this->time < other.time;
	}

};



bool fraudulent(vector<Transaction> &trans, int i){
	int j = i-1; // search previous transactions
	while (j >= 0 && trans[i].time - trans[j].time <= 60){
		if (trans[i].city != trans[j].city){
			return true;
		}
		--j;
	}

	j = i+1; // search future transactions
	while (j < trans.size() && trans[j].time - trans[i].time <= 60){
		if (trans[i].city != trans[j].city){
			return true;
		}
		++j;
	}
	return false;
}



vector<string> invalidTransactions(vector<string>& transactions){
	umap<string, vector<Transaction>> m;
	vector<string> invalid;

	for (int j = 0; j < transactions.size(); ++j){
		Transaction t(j, transactions[j]);
		auto &trans = m[t.name];
		trans.insert(lower_bound(trans.begin(), trans.end(), t), t);
	}


	// now, scan all transactions to invalidate any possible fraudulent ones
	for (auto [_, trans] : m){
		for (int i = 0; i < trans.size(); ++i){
			Transaction &t = trans[i];
			if (t.amount > 1000 || fraudulent(trans, i)){
				invalid.push_back(transactions[t.index]);
			}
		}

	}

	return invalid;
}






int main(){
	vector<string> ts;

	ts = {"alice,20,800,mtv", "alice,50,100,beijing"};
	c_log(invalidTransactions(ts));

	ts = {"alice,20,800,mtv","alice,50,100,mtv","alice,51,100,frankfurt"};
	c_log(invalidTransactions(ts));

	return 0;
}



