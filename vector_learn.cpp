#include <iostream>
#include <vector>

int main(int argc, char** argv);

int main(int argc, char** argv) {
	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "Binary source: " << argv[0] << endl << endl;
	cout << "Example of Standard Template Library Vector." << endl << endl;

	vector<int> vec;

	for(register int i = 1; i <= 20; i++)
		vec.push_back(i);

	cout << "Vector to get the elements via iterator." << endl << "Numbs: ";

	for(vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
		// Dereferencing the iterator.
		cout << *it << " ";

	cout << endl << endl;

	// Reverse iterator.
	cout << "Elements using the reverse iterator." << endl << "Numbs: ";

	// Constant reverse iterator.
	for(vector<int>::const_reverse_iterator it = vec.crbegin(); it != vec.crend(); it++)
		cout << *it << " ";

	cout << endl << endl;

	cout << "Size:" << vec.size() << endl;
	cout << "Capacity: " << vec.capacity() << endl;
	cout << "Max size: " << vec.max_size() << endl;

	// Checking the emptiness.

	cout << "The vector is ";

	if(vec.empty())
		cout << "empty." << endl;
	else cout << "not empty." << endl;

	cout << endl;

	// Resizing the vector.

	cout << "Curtailing the vector using the .resize() method." << endl;

	vec.resize(10);

	cout << "Numbs: ";

	// Using constant iterator.

	for(vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";

	cout << endl << endl << "Extending the vector using .resize() method." << endl;

	vec.resize(20, 5);

	cout << "Numbs: ";

	// Using constant iterator.

	for(vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); it++)
		cout << *it << " ";

	cout << endl << endl << "Using the shrink_to_fit() method." << endl;

	vec.shrink_to_fit();

	cout << "Capacity: " << vec.capacity() << endl;

	return 0;
}
