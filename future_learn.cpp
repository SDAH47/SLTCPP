#include <iostream>
#include <future>
#include <chrono>

int main(int argc, char** argv);
bool isPrime(int);

void sayHello(int);

class OBJ {
	public:
		void operator()(int n) {
			for(register int i = 0; i < n; i++)
				std::cout << "An Object operator." << std::endl;
		}
};

int main(int argc, char** argv) {
	using namespace std;

	cout << "Binary source: " << argv[0] << endl << endl;
	cout << "Example of Standard Template Library Future." << endl << endl;

	cout << "Asynchronous function calls." << endl << endl;

	int num = 444444443;

	future<bool> futs = async(isPrime, num);

	cout << "Checking, please wait" << endl;

	while(futs.wait_for(chrono::milliseconds(200)) == future_status::timeout)
		cout << "." << flush;

	cout << num << " " << (futs.get() ? "is" : "is not") << " prime." << endl;

	cout << endl << "THREAD EXAMPLE" << endl << endl;

	thread t1(sayHello, 10);
	thread t2(OBJ(), 10);
	thread t3([](int n) {
		for(register int i = 0; i < n; i++)
			cout << "A lambda expression." << endl;
	}, 10);

	t1.join();
	t2.join();
	t3.join();

	return 0;
}

bool isPrime(int n) {
	for(register int i = 2; i < n; i++)
		if(n % i == 0)
			return false;

	return true;
}

void sayHello(int n) {
	for(register int i = 0; i < n; i++)
		std::cout << "A Regular function." << std::endl;
}
