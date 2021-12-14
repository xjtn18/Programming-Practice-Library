//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 11/28/21
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;




vector<string> reorderLogFiles(vector<string> &logs){
	vector<string> result;
	vector<int> digitLogIndexes;
	vector<pair<string,string>> letterLogs;

	for (int i = 0; i < logs.size(); ++i){
		size_t split = logs[i].find(' ');
		string id = logs[i].substr(0, split);
		string content = logs[i].substr(split + 1);

		if (isdigit(content[0])) digitLogIndexes.push_back(i);
		else letterLogs.push_back({id, content});
	}

	sort(letterLogs.begin(), letterLogs.end(), [](auto &a, auto &b){
			return (a.second == b.second) ? a.first < b.first : a.second < b.second;
	});


	for (auto &p : letterLogs) result.push_back(p.first + " " + p.second);
	for (int &i : digitLogIndexes) result.push_back(logs[i]);

	return result;
}



int main(){
	c_log(reorderLogFiles({"dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"}));
	return 0;
}



