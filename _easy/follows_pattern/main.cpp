//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created:
//  File type: C++ source file
//  Description:
//////////////////////////////////////////////////////


#include <mystd.h>

//#define is_in(x,y) y.find(x) != y.end()
//#define not_in(x,y) y.find(x) == y.end()


bool valid(std::map<std::string, std::string>& m, std::string key, std::string val){
	if ( is_in(key, m) ){ // we have a mapping for this strings pattern already
		if ( val != m[key]){ // if it doesnt equal the previous mapping, return false
			return false;
		}
	} else {
		m[key] = val;
	}
	return true;
}


bool areFollowingPatterns(std::vector<std::string> strings, std::vector<std::string> patterns) {
	// two maps ensures there wont be any collision issues with a string that is equivalent to a pattern
	std::map<std::string, std::string> smap;
	std::map<std::string, std::string> pmap;

	for (int i = 0; i < strings.size(); ++i){
		if (!valid(smap, strings[i], patterns[i]) || !valid(pmap, patterns[i], strings[i])){
			return false;
		}
	}
	return true;
}



int main(){
	std::vector<std::string> strings;
	std::vector<std::string> patterns;

	strings = {"cat", "cat", "doggy"};
	patterns = {"a", "b", "c"};
	assert( areFollowingPatterns(strings, patterns) == false);

	strings = {"cat", "cat", "doggy"};
	patterns = {"a", "a", "c"};
	assert( areFollowingPatterns(strings, patterns) == true);

	strings = {"apple"};
	patterns = {"a"};
	assert( areFollowingPatterns(strings, patterns) == true);

	strings = {"ap", "ba", "ki"};
	patterns = {"a", "b", "c"};
	assert( areFollowingPatterns(strings, patterns) == true);

	return 0;
}



