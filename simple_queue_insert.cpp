#include <iostream>
#include <string>
#include <queue>

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


int main()
{
	std::queue<val> val_q; // queue adds elements to the back and pops it from the front
	val_q.push(val(9,"blah"));
	val_q.push(val());
	val_q.push(val(10,"blah2"));

	std::cout << "front " << val_q.front() << " back " << val_q.back() << std::endl;
}




