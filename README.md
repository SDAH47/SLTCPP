# Use of STL(Standard Template Library)
Hello there! It's SD Asif Hossein. Today I am going to talk about the use of STL  aka Standard Template Library of C++. See, C++ has a very powerful, robust Library system which allows us to do lots of magical stuffs like holding multiple data types in one variable, multi-threading, Dynamic Array manipulation etc. In this amazing world of C++ STL, let's know some of them deeply and clearly.

## Dynamic Array Manipulation with std::vector
At first lets talk about one of favorite STL, the std::vector. **Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.** Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

Let's consider following example...

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
Output of the above code is...

    Binary source: ./vector_learn.obj

	Example of Standard Template Library Vector.

	Vector to get the elements via iterator.
	Numbs: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20

	Elements using the reverse iterator.
	Numbs: 20 19 18 17 16 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1

	Size:20
	Capacity: 32
	Max size: 1073741823
	The vector is not empty.

	Curtailing the vector using the .resize() method.
	Numbs: 1 2 3 4 5 6 7 8 9 10

	Extending the vector using .resize() method.
	Numbs: 1 2 3 4 5 6 7 8 9 10 5 5 5 5 5 5 5 5 5 5

	Using the shrink_to_fit() method.
	Capacity: 20

### Short description of std::vector methods
**Capacity:** Used to manipulate the capacity of a certain vector.

1.  [size()](https://en.cppreference.com/w/cpp/container/vector/size)  – Returns the number of elements in the vector.
2.  [max_size()](https://en.cppreference.com/w/cpp/container/vector/max_size)  – Returns the maximum number of elements that the vector can hold.
3.  [capacity()](https://en.cppreference.com/w/cpp/container/vector/capacity)  – Returns the size of the storage space currently allocated to the vector expressed as number of elements.
4.  [empty()](https://en.cppreference.com/w/cpp/container/vector/empty)  – Returns whether the container is empty.
5.  [shrink_to_fit()](https://en.cppreference.com/w/cpp/container/vector/shrink_to_fit)  – Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.

**Element Access:** Used to access elements from a certain vector.
6.  [operator []](https://en.cppreference.com/w/cpp/container/vector/operator_at)  – Returns a reference to the element at position ‘g’ in the vector.
7.  [at(g)](https://en.cppreference.com/w/cpp/container/vector/at)  – Returns a reference to the element at position ‘g’ in the vector.
8.  [front()](https://en.cppreference.com/w/cpp/container/vector/front)  – Returns a reference to the first element in the vector.
9.  [back()](https://en.cppreference.com/w/cpp/container/vector/back)  – Returns a reference to the last element in the vector.
10.  [data()](https://en.cppreference.com/w/cpp/container/vector/data)  – Returns a direct pointer to the memory array used internally by the vector to store its owned elements.

**Modifiers:** Used to modify a certain vector.
11.  [assign()](https://www.geeksforgeeks.org/vector-assign-in-c-stl/) – It assigns new value to the vector elements by replacing old ones.
12.  [push_back()](https://en.cppreference.com/w/cpp/container/vector/push_back)  – It push the elements into a vector from the back.
13.  [pop_back()](https://en.cppreference.com/w/cpp/container/vector/pop_back)  – It is used to pop or remove elements from a vector from the back.
14.  [insert()](https://en.cppreference.com/w/cpp/container/vector/insert)  – It inserts new elements before the element at the specified position.
15.  [erase()](https://en.cppreference.com/w/cpp/container/vector/erase)  – It is used to remove elements from a container from the specified position or range.
16. [resize(n)](https://en.cppreference.com/w/cpp/container/vector/resize) – Resizes the container so that it contains ‘n’ elements. 
17.  [swap()](https://en.cppreference.com/w/cpp/container/vector/swap)  – It is used to swap the contents of one vector with another vector of same type. Sizes may differ.
18.  [clear()](https://en.cppreference.com/w/cpp/container/vector/clear)  – It is used to remove all the elements of the vector container.
19.  [emplace()](https://en.cppreference.com/w/cpp/container/vector/emplace)  – It extends the container by inserting new element at position.
20.  [emplace_back()](https://en.cppreference.com/w/cpp/container/vector/emplace_back)  – It is used to insert a new element into the vector container, the new element is added to the end of the vector.
