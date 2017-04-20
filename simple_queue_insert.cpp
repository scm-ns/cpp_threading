#include <iostream>
#include <string>
#include <queue>
#include <thread> // Link the pthread libs to make it work
#include <mutex>
#include <vector>
#include <functional>

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

void insert(std::queue<val>& q, int num , int start)
{
	char s = '^';
	for(int x = 0 ; x < num ; ++x)
	{
		q.push(val(start , std::string(start , s)));
		++start;
	}
}

inline void _process(std::queue<val>& q)
{
	if(q.empty()) return;
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

void call_from_thread(int tid)
{
	std::cout << " Doom is taking time ; sponsored by : " << tid << std::endl;
	
}



// ############# DOOM AND CHAOS ##############

// global var but it is all going to hell so who cares!
std::vector<std::thread> threads;

void create_threads(std::function<void(int)> f , int num_thr)
{
	for( int x_  = 0 ; x_ < num_thr; ++x_)
	{
		threads.push_back(std::thread(f, x_));
	}
}

void join_threads()
{
	for( std::size_t x_  = 0 ; x_ < threads.size() ; ++x_)
	{
		if(threads[x_].joinable())
			threads[x_].join();
	}
}


int main()
{
	std::cout << "# Threads supported " << std::thread::hardware_concurrency() << std::endl;
	std::queue<val> q;
	std::mutex mtx;
	create_threads([&q , &mtx](const int& tid)
	{
		std::lock_guard<std::mutex> lock(mtx);
		insert(q , 10, tid * 10);	
	} , 3 );

	create_threads([&q](const int& tid)
	{
		process(q, 10);
	} , 1);
	

	join_threads();
	std::cout << __func__ << std::endl;
	

}
