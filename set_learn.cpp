#include <iostream>
#include <set>

int main(int argc, char** argv);

int main(int argc, char** argv) {
	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "Binary source: " << argv[0] << endl << endl;
	cout << "Example of Standard Template Library Set." << endl << endl;

	set<int, greater<int>> set1;		// Set with "compare" template argument.

	set1.insert(10);
	set1.insert(20);
	set1.insert(30);
	set1.insert(40);
	set1.insert(50);
	set1.insert(50);		// Only one 50 will be added.

	cout << "Printing all the values using iterator." << endl << "Numbs: ";

	for(set<int, greater<int>>::iterator it = set1.begin(); it != set1.end(); it++)
		cout << *it << " ";

	cout << endl << endl << "Printing using constant reverse iterator (Reversed elements)." << endl << "Numbs: ";

	for(set<int, greater<int>>::const_reverse_iterator it = set1.crbegin(); it != set1.crend(); it++)
		cout << *it << " ";

	cout << endl << endl;

	cout << "Size: " << set1.size() << endl;
	cout << "Max size: " << set1.max_size() << endl << endl;

	cout << "The set is ";

	if(set1.empty())
		cout << "empty." << endl;
	else cout << "not empty." << endl;

	cout << endl;

	cout << "Adding an element with .insert() method with a pointed iterator." << endl;

	set1.insert(set1.end(), 60);

	cout << endl << endl << "Printing values after using the iterator insert() method." << endl << "Numbs: ";

	for(set<int, greater<int>>::const_reverse_iterator it = set1.crbegin(); it != set1.crend(); it++)
		cout << *it << " ";

	cout << endl << endl;

	set<int, greater<int>>::iterator result = set1.find(30);

	if(result != set1.end())
		cout << "Found the number 30." << endl;
	else cout << "The number 30 not found!" << endl;

	cout << endl;

	cout << "Erasing 60 from set1." << endl;
	set1.erase(60);

	cout << "The lower bound of 30: " << *set1.lower_bound(30) << endl;
	cout << "The lower bound of 60 (Which is not present): " << *set1.upper_bound(60) << endl;

	cout << "Using emplace() method to add an element uniquely." << endl;
	set1.emplace(100);

	result = set1.emplace_hint(--set1.end(), 70);

	cout << endl << endl << "Printing values after using the emplace() and emplace_hint() method." << endl << "Numbs: ";

	for(set<int, greater<int>>::const_reverse_iterator it = set1.crbegin(); it != set1.crend(); it++)
		cout << *it << " ";

	cout << endl << endl;

	set<int, greater<int>> set2 = { 1, 2, 3, 4, 5 };

	cout << endl << endl << "Elements of set2." << endl << "Numbs: ";

	for(set<int, greater<int>>::const_reverse_iterator it = set2.crbegin(); it != set2.crend(); it++)
		cout << *it << " ";

	cout << endl << endl;

	set1.swap(set2);

	cout << endl << endl << "Printing values after using the swap() method on set1 with set2." << endl << "Numbs(set1): ";

	for(set<int, greater<int>>::const_reverse_iterator it = set1.crbegin(); it != set1.crend(); it++)
		cout << *it << " ";

	cout << endl << "Numbs(set2): ";

	for(set<int, greater<int>>::const_reverse_iterator it = set2.crbegin(); it != set2.crend(); it++)
		cout << *it << " ";

	cout << endl;

	// Removing all the elements.
	set1.clear();

     return 0;
}
