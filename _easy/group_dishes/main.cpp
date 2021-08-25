//////////////////////////////////////////////////////
//  Author: Jacob Nardone
//  Date created: 8/22/21
//  File type: C++ source file
//  Description: Given a matrix that shows what ingredients and in each dish,
//  					return a matrix that shows what dishes contain each ingredient (if ingredient in 2 or more dishes)
//////////////////////////////////////////////////////

//
// Idea:
// Use a ordered map where the key is the ingredient and the value is a vector of dishes
// Iterate through the 2d array
// map[vec[i][j]].push_back(vec[i][0])  -  this adds this dish to this ingredient's list of dishes
//



#include <mystd.h>


template <typename T>
using vec2D = std::vector<std::vector<T>>;



vec2D<std::string> groupingDishes(vec2D<std::string> dishes) {
	vec2D<std::string> vec;	
	std::map<std::string, std::vector<std::string>> dict;
	
	for (int i = 0; i < dishes.size(); ++i){
		for (int j = 1; j < dishes[i].size(); ++j){
			std::string ingredient = dishes[i][j];
			std::string dish = dishes[i][0];
			dict.emplace(ingredient, std::vector<std::string>()); // this is needed to get Pythons 'default_dict' behavior
			auto lower = std::lower_bound(dict[ingredient].begin(), dict[ingredient].end(), dish); // insert into vector sorted lexo
			dict[ingredient].insert(lower, dish);
		}
	}

	// create the result matrix
	for (auto it = dict.begin(); it != dict.end(); ++it){
		std::vector<std::string> row = {it->first};
		row.insert(row.end(),
				std::make_move_iterator(it->second.begin()),
				std::make_move_iterator(it->second.end()));
		// NOTE: move iterators will destroy whatever it->second, but we dont need the dictionary past this point, so its ok.
		//
		if (row.size() > 2){ // only show ingredients that appear in atleast 2 dishes.
			vec.push_back(std::move(row)); // will transfer row to vec; no copying
		}
	}

	return vec;
}



int main(){
	vec2D<std::string> input;
	vec2D<std::string> ans;

	input = {{"Salad","Tomato","Cucumber","Salad","Sauce"}, 
	 {"Pizza","Tomato","Sausage","Sauce","Dough"}, 
	 {"Quesadilla","Chicken","Cheese","Sauce"}, 
	 {"Sandwich","Salad","Bread","Tomato","Cheese"}};
	ans = groupingDishes(input);

	for (auto& r : ans){
		c_log(r);
	}
	
	return 0;
}



