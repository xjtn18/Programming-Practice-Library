#include <speed.hpp>

using namespace std;


#define ull unsigned long long


struct Monkey {
	queue<ull> items;
	std::function<ull(ull)> operation;
	ull test;
	ull T, F;
	ull inspected = 0;
};






// ------------ Solution ------------ //


record<Monkey> create_monkeys() {
	record<Monkey> m(8);

	m[0].items = queue<ull>({59, 74, 65, 86});
	m[0].operation = [](ull old){ return old * 19; };
	m[0].test = 7;
	m[0].T = 6;
	m[0].F = 2;

	m[1].items = queue<ull>({62, 84, 72, 91, 68, 78, 51});
	m[1].operation = [](ull old){ return old + 1; };
	m[1].test = 2;
	m[1].T = 2;
	m[1].F = 0;

	m[2].items = queue<ull>({78, 84, 96});
	m[2].operation = [](ull old){ return old + 8; };
	m[2].test = 19;
	m[2].T = 6;
	m[2].F = 5;

	m[3].items = queue<ull>({97, 86});
	m[3].operation = [](ull old){ return old * old; };
	m[3].test = 3;
	m[3].T = 1;
	m[3].F = 0;

	m[4].items = queue<ull>({50});
	m[4].operation = [](ull old){ return old + 6; };
	m[4].test = 13;
	m[4].T = 3;
	m[4].F = 1;

	m[5].items = queue<ull>({73, 65, 69, 65, 51});
	m[5].operation = [](ull old){ return old * 17; };
	m[5].test = 11;
	m[5].T = 4;
	m[5].F = 7;

	m[6].items = queue<ull>({69, 82, 97, 93, 82, 84, 58, 63});
	m[6].operation = [](ull old){ return old + 5; };
	m[6].test = 5;
	m[6].T = 5;
	m[6].F = 7;

	m[7].items = queue<ull>({81, 78, 82, 76, 79, 80});
	m[7].operation = [](ull old){ return old + 3; };
	m[7].test = 17;
	m[7].T = 3;
	m[7].F = 4;

	return m;
}


void part_1(){
	record<Monkey> monkeys = create_monkeys();

	// max_stress
	ull max_stress = 1;
	for (Monkey &m : monkeys){
		max_stress *= m.test;
	}

	for (ull i = 0; i < 10000; ++i){
		for (Monkey &m : monkeys){
			m.inspected += m.items.size();
			while (!m.items.empty()){
				ull item = m.items.front();
				item = m.operation(item) % max_stress;
				if (item % m.test == 0){
					monkeys[m.T].items.push(item);
				} else {
					monkeys[m.F].items.push(item);
				}
				m.items.pop();
			}
		}
	}

	std::sort(monkeys.begin(), monkeys.end(), 
			  [](const Monkey & a, const Monkey & b) -> bool { 
				  return a.inspected > b.inspected; 
			  });

	c_log(monkeys);

	ull ans = monkeys[0].inspected * monkeys[1].inspected;
	cout << "Part 1 - Answer is: " << ans << endl;
}


std::ostream& operator<<(std::ostream& o, const Monkey &m){
	o << m.inspected;
	return o;
}


void part_2(){

	
	cout << "Part 2 - Answer is: " << "" << endl;
}

// ----------------------------------- //




int main(int argc, char *argv[]){
	string input_path = "input/" + string(1, argv[0][0]) + ".input";
	auto lines = read_lines(input_path);

	part_1();
	part_2();
}


