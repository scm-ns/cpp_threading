#include <iostream>
#include <string>
#include <queue>
#include <thread> // Link the pthread libs to make it work

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

inline void _process(std::queue<val>& q)
{
	std::cout << q.front() << std::endl;
	q.pop();
}

void process(std::queue<val>&q , int num)
{
	for(int x = 0 ; x < num ; ++x)
	{
		_process(q);
	}
}

void call_from_thread()
{
	std::cout << " Doom is taking time " << std::endl;
}


// ############# DOOM AND CHAOS ##############


int main()
{
	std::thread t(call_from_thread);
	t.join();
}
