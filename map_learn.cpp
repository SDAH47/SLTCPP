#include <iostream>
#include <map>
#include <utility>

int main(int argc, char** argv);

int main(int argc, char** argv) {
	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "Binary source: " << argv[0] << endl << endl;
	cout << "Example of Standard Template Library Map." << endl << endl;

	map<int, int> map1;

	map1.insert(pair<int, int>(1, 10));
	map1.insert(pair<int, int>(2, 20));
	map1.insert(pair<int, int>(3, 30));
	map1.insert(pair<int, int>(4, 40));
	map1.insert(pair<int, int>(5, 50));

	cout << "Printing all the values using iterator." << endl;

	cout << "KEY:\tVALUE:" << endl;
	for(map<int, int>::iterator it = map1.begin(); it != map1.end(); it++)
		cout << it -> first << "\t" << it -> second << endl;

	cout << endl << "Printing all the values using constant reverse iterator." << endl;

	cout << "KEY:\tVALUE:" << endl;
	for(map<int, int>::const_reverse_iterator it = map1.crbegin(); it != map1.crend(); it++)
		cout << it -> first << "\t" << it -> second << endl;

	// Removing first 3 elements.
	map1.erase(map1.begin(), map1.find(4));

	cout << endl << "Printing all the values after removing first 3 elements." << endl;

	cout << "KEY:\tVALUE:" << endl;
	for(map<int, int>::const_iterator it = map1.cbegin(); it != map1.cend(); it++)
		cout << it -> first << "\t" << it -> second << endl;

	cout << endl << "Size: " << map1.size() << endl;
	cout << "Max size: " << map1.max_size() << endl;

	cout << endl;

	cout << "The map is ";

	if(map1.empty())
		cout << "empty." << endl;
	else cout << "not empty." << endl;

	map<int, int>::iterator result = map1.find(2);

	if(result != map1.end())
		cout << "Found the number element on index 2." << endl;
	else cout << "The element of index 2 not found!" << endl;

	cout << endl;

     cout << "The key 1 is ";

     if(map1.count(1))
		cout << "present." << endl;
	else cout << "absent." << endl;

     map1.emplace_hint(map1.begin(), pair<int, int>(3, 30));
     map1.emplace_hint(map1.begin(), pair<int, int>(2, 20));
     map1.emplace_hint(map1.begin(), pair<int, int>(1, 10));

     cout << endl << "Printing all the values after using emplace_hint() method." << endl;

	cout << "KEY:\tVALUE:" << endl;
	for(map<int, int>::const_iterator it = map1.cbegin(); it != map1.cend(); it++)
		cout << it -> first << "\t" << it -> second << endl;

	cout << "Element at key 3: " << map1.at(3) << endl << endl;

	cout << "map1.lower_bound(5) : "
		<< "\tKEY = ";
	cout << map1.lower_bound(5)->first << '\t';
	cout << "\tELEMENT = "
		<< map1.lower_bound(5)->second << endl;
	cout << "map1.upper_bound(5) : "
		<< "\tKEY = ";
	cout << map1.upper_bound(5)->first << '\t';
	cout << "\tELEMENT = "
		<< map1.upper_bound(5)->second << endl;

	return 0;
}
