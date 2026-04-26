#include <mystd.h>
#include <windows.h>



//////////////////////////////////////////////////////////////////
// Debugging

void sleep(float seconds){
	Sleep(seconds * 1000);
}
// ------------------------------------------------------------ //



//////////////////////////////////////////////////////////////////
// Math

int mod(int a, int b){
	return (a%b+b) % b;
}

template <typename T>
T sigma(std::vector<T> v){
	return std::reduce(v.begin(), v.end(), 0);
}

template <typename T>
T pi(std::vector<T> v){
	return std::reduce(v.begin(), v.end(), 1, std::multiplies<T>());
}
// ------------------------------------------------------------ //



//////////////////////////////////////////////////////////////////
// Graph

// s2 (scalar 2 dimensions) point on a Cartesian plane
struct s2 {
	int x, y;

	s2() : x(int()), y(int()) { }
	s2(int x, int y) : x(x), y(y) { }

	s2 operator+(const s2& other) const {
		return s2(x + other.x, y + other.y);
	}

	s2 operator-(const s2& other) const {
		return s2(x - other.x, y - other.y);
	}

	s2 operator+=(const s2 &rhs){
		this->x += rhs.x;
		this->y += rhs.y;
		return *this;
	}

	s2 operator-=(const s2 &rhs){
		this->x -= rhs.x;
		this->y -= rhs.y;
		return *this;
	}

	bool operator==(const s2 &rhs) const {
		return (this->x == rhs.x && this->y == rhs.y);
	}
};

// Make s2 printable
std::ostream &operator<<(std::ostream &out, const s2 &_s2){
	out << "(" << _s2.x << ", " << _s2.y << ")";
	return out;
}



// Make s2 hashable
namespace std {

	template <>
	struct hash<s2> {
		std::size_t operator()(const s2& p) const {
			using std::size_t;
			using std::hash;
			using std::string;

			// Compute individual hash values for first,
			// second and third and combine them using XOR
			// and bit shifting:

			return ((hash<int>()(p.x)
					 ^ (hash<int>()(p.y) << 1)) >> 1);
		}
	};
}

//////////////////////////////////////////////////////////////////



//////////////////////////////////////////////////////////////////
// String manip

std::vector<std::string> split(std::string s, std::string delim=" "){
	std::vector<std::string> tokens;
	size_t pos, splt = -1;
	do {
		pos = splt+1;
		splt = s.find(delim, pos);
		tokens.push_back(s.substr(pos, splt-pos));
	} while (splt != std::string::npos);

	return tokens;
}

std::string join(std::vector<std::string> vs, std::string sep=" "){
	std::string res;

	for (auto s : vs){
		res += s + sep;
	}

	res.erase(res.length()-sep.length());

	return res;
}
// ------------------------------------------------------------ //



//////////////////////////////////////////////////////////////////
// File reading

std::vector<std::string> read_lines(std::string filepath){
	std::fstream file;
	file.open(filepath, std::ios::in);

	std::vector<std::string> lines;
	std::string line;
	while (std::getline(file, line)){
		lines.push_back(line);
	}

	file.close();
	return lines;
}
// ------------------------------------------------------------ //



//////////////////////////////////////////////////////////////////
// Other

// Override of unordered_map index operator to achieve 'defaultdict' behavior.
// NOTE(jacob 12/8/22) This is the default behavior of unordered_map now....
template <typename K, typename V>
struct default_map : public std::unordered_map<K, V> {

	V default_value;

	default_map<K, V>(V dv = V()){
		default_value = dv;
	}

	V &operator[](K key){
		std::unordered_map<K, V>::emplace(key, default_value);
		return std::unordered_map<K, V>::at(key);
	}
};


// Override of std::vector index operator to achieve modulo indexing.
template <typename T>
struct record : public std::vector<T> {

	// Constructor
	record<T>(int sz = 0, T init = T()) : std::vector<T>(sz, init) { }

	// Initializer list constructor
	record(std::initializer_list<T> l) {
		std::vector<T>::operator=(l);
	}

	T &operator[](int index){
		int sz = std::vector<T>::size();
		return std::vector<T>::at( (index >= -sz && index < 0)
								  ? index + sz : index);
	}
};



// Variadic reference assignment mapping from a vector of elements.
namespace {
	template <typename T>
	void assign(int index, std::vector<T> &l){ }

	template <typename T, typename... Ts>
	void assign(int index, std::vector<T> &l, T &head, Ts&... tail){
		if (index == l.size()) return;
		head = std::move(l[index]);
		assign(++index, l, tail...);
	}
}

template <typename T, typename... Ts>
void assign(std::vector<T> &l, Ts&... all){
	assign(0, l, all...);
}
//////////////////////////////////////////////////////////////////
