#include <iostream>
#include <string>
#include <queue>

// ######### HELPERS ####################
struct val
{
	val() : _a(0) , _name("") {};
	val(int a , std::string name) : _a(a) , _name(name) {};
	private:	
		int _a;
		std::string _name;
	friend std::ostream &operator<<(std::ostream& os , val const& v);
};

std::ostream &operator<<(std::ostream& os , val const& v)
{
	return os << "Val : " << v._a << " : " << v._name << std::endl;
}

void insert(std::queue<val>& q, int num)
{
	char s = '^';
	for(int x = 0 ; x < num ; ++x)
	{
		q.push(val(x , std::string(x , s)));
	}
}

inline void _process(val v)
{
	std::cout << v << std::endl;
}

void process(std::queue<val>&q , int num)
{
	for(int x = 0 ; x < num ; ++x)
	{
		_process(q.front());
		q.pop();		
	}
}

// ############# DOOM AND CHAOS ##############


int main()
{
	std::queue<val> val_q; // queue adds elements to the back and pops it from the front
	val_q.push(val(9,"blah"));
	val_q.push(val());
	val_q.push(val(10,"blah2"));

	std::cout << "front " << val_q.front() << " back " << val_q.back() << std::endl;
}
