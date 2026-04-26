//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>
using namespace std;



vector<vector<string>> groupAnagrams(vector<string>& strs){
	if (strs.size() == 1) return {{strs[0]}};
        
	vector<vector<string>> ans;
	unordered_map<string, vector<string>> M;

	for (int i = 0; i < strs.size(); i++){
		string str = strs[i];
		sort(strs[i].begin(), strs[i].end()); // Sorting the string
		M[strs[i]].push_back(std::move(str));  // Sorted string is the key and the value is the string
	}

	for (auto &p : M) ans.push_back(std::move(p.second));
	return ans;
}



int main(){
	vector<string> strs;


	strs = {"eat","tea","tan","ate","nat","bat"};
	hlog(groupAnagrams(strs));

	return 0;
}



