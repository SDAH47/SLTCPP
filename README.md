
# Use of STL(Standard Template Library)
Hello there! It's SD Asif Hossein. Today I am going to talk about the use of STL  aka Standard Template Library of C++. See, C++ has a very powerful, robust Library system which allows us to do lots of magical stuffs like holding multiple data types in one variable, multi-threading, Dynamic Array manipulation etc. In this amazing world of C++ STL, let's know some of them deeply and clearly.

## Dynamic Array Manipulation with std::vector
At first let's talk about one of favorite STL class, the std::vector. **Vectors are same as dynamic arrays with the ability to resize itself automatically when an element is inserted or deleted, with their storage being handled automatically by the container.** Vector elements are placed in contiguous storage so that they can be accessed and traversed using iterators. In vectors, data is inserted at the end. Inserting at the end takes differential time, as sometimes there may be a need of extending the array. Removing the last element takes only constant time because no resizing happens. Inserting and erasing at the beginning or in the middle is linear in time.

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

    Binary source: ./vector_learn

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
***std::vector***

    template <class T, class Alloc = allocator<T>> class vector; // generic template
***Description of template parameters:***
1. **T:** Type of the elements.  
Only if  T  [is guaranteed to not throw while moving](http://www.cplusplus.com/is_nothrow_move_constructible), implementations can optimize to move elements instead of copying them during reallocations.  
Aliased as member type  vector::value_type.

2. **Alloc:**  Type of the allocator object used to define the storage allocation model. By default, the  [allocator](http://www.cplusplus.com/allocator)  class template is used, which defines the simplest memory allocation model and is value-independent.  
Aliased as member type  vector::allocator_type.

### Short description of std::vector methods
**Capacity:** Used to operate the capacity of a certain vector.

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

**Iterators:** Used to work with the vector iterators.

21.  [begin()](http://www.cplusplus.com/reference/vector/vector/begin/)  – Returns an iterator pointing to the first element in the vector
22.  [end()](http://www.cplusplus.com/reference/vector/vector/end/)  – Returns an iterator pointing to the theoretical element that follows the last element in the vector
23.  [rbegin()](http://www.cplusplus.com/reference/vector/vector/rbegin/)  – Returns a reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
24.  [rend()](http://www.cplusplus.com/reference/vector/vector/rend/)  – Returns a reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
25.  [cbegin()](http://www.cplusplus.com/reference/vector/vector/cbegin/)  – Returns a constant iterator pointing to the first element in the vector.
26.  [cend()](http://www.cplusplus.com/reference/vector/vector/cend/)  – Returns a constant iterator pointing to the theoretical element that follows the last element in the vector.
27.  [crbegin()](http://www.cplusplus.com/reference/vector/vector/crbegin/)  – Returns a constant reverse iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
28.  [crend()](http://www.cplusplus.com/reference/vector/vector/crend/)  – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)

**Allocator:** Used for dynamic allocation.

29. [get_allocator()](http://www.cplusplus.com/reference/vector/vector/get_allocator/) - Returns a copy of the allocator object associated with the [vector](http://www.cplusplus.com/vector).

## Unique Dynamic Array Manipulation with std::set
The reason I am calling it an unique dynamic array manipulation is, you can't add same values on set. That means if I already have number 6 in a set, then my set won't be adding 6 again. **Sets are a type of associative containers in which each element has to be unique, because the value of the element identifies it.** The value of the element cannot be modified once it is added to the set, though it is possible to remove and add the modified value of that element.

Let's consider following example of set...

    #include <iostream>
	#include <set>

	int main(int argc, char** argv);

	int main(int argc, char** argv) {
		using namespace std;

		ios_base::sync_with_stdio(false);
		cin.tie(NULL);

		cout << "Binary source: " << argv[0] << endl << endl;
		cout << "Example of Standard Template Library Set." << endl << endl;

		set<int, greater<int>> set1; // Set with "compare" template argument.

		set1.insert(10);
		set1.insert(20);
		set1.insert(30);
		set1.insert(40);
		set1.insert(50);
		set1.insert(50); // Only one 50 will be added.

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

The output of the above example is...

    Binary source: ./set_learn

	Example of Standard Template Library Set.

	Printing all the values using iterator.
	Numbs: 50 40 30 20 10

	Printing using constant reverse iterator (Reversed elements).
	Numbs: 10 20 30 40 50

	Size: 5
	Max size: 214748364

	The set is not empty.

	Adding an element with .insert() method with a pointed iterator.

	Printing values after using the iterator insert() method.
	Numbs: 10 20 30 40 50 60

	Found the number 30.

	Erasing 60 from set1.
	The lower bound of 30: 30
	The lower bound of 60 (Which is not present): 50
	
	Using emplace() method to add an element uniquely.
	
	Printing values after using the emplace() and emplace_hint() method.
	Numbs: 10 20 30 40 50 70 100

	Elements of set2.
	Numbs: 1 2 3 4 5

	Printing values after using the swap() method on set1 with set2.
	Numbs(set1): 1 2 3 4 5
	Numbs(set2): 10 20 30 40 50 70 100
   
   ***std::set***

    template <class T,                        // set::key_type/value_type
	          class Compare = less<T>,        // set::key_compare/value_compare
              class Alloc = allocator<T>      // set::allocator_type
            > class set;
***Description of template parameters:***
1. **T:** Type of the elements. Each element in a  set  container is also uniquely identified by this value (each value is itself also the element's key).  
Aliased as member types  set::key_type  and  set::value_type.

2. **Compare:**  A binary predicate that takes two arguments of the same type as the elements and returns a  bool. The expression  comp(a,b), where  _comp_  is an object of this type and  _a_  and  _b_  are key values, shall return  true  if  _a_  is considered to go before  _b_  in the  _strict weak ordering_  the function defines.  
The  set  object uses this expression to determine both the order the elements follow in the container and whether two element keys are equivalent (by comparing them reflexively: they are equivalent if  !comp(a,b) && !comp(b,a)). No two elements in a  set  container can be equivalent.  
This can be a function pointer or a function object (see  [constructor](http://www.cplusplus.com/set::set)  for an example). This defaults to  [less](http://www.cplusplus.com/less)<T>, which returns the same as applying the  _less-than operator_  (a<b).  
Aliased as member types  set::key_compare  and  set::value_compare.

3. **Alloc:** Type of the allocator object used to define the storage allocation model. By default, the  [allocator](http://www.cplusplus.com/allocator)  class template is used, which defines the simplest memory allocation model and is value-independent.  
Aliased as member type  set::allocator_type.

### Short description of std::set methods
**Capacity:** Used to operate on the capacity of a certain set.

1. [size()](http://www.cplusplus.com/reference/set/set/size/)  – Returns the number of elements in the set.
2. [max_size()](http://www.cplusplus.com/reference/set/set/max_size/)  – Returns the maximum number of elements that the set can hold.
3. [empty()](http://www.cplusplus.com/reference/set/set/empty/)  – Returns whether the set is empty.

**Modifiers:** Used to modify a certain set.

4. [insert(const g)](http://www.cplusplus.com/reference/set/set/insert/)  – Adds a new element ‘g’ to the set.
5. [insert (iterator position, const g)](http://www.cplusplus.com/reference/set/set/insert/)  – Adds a new element ‘g’ at the position pointed by iterator.
6. [erase(iterator position)](http://www.cplusplus.com/reference/set/set/erase/)  – Removes the element at the position pointed by the iterator.
7. [erase(const g)](http://www.cplusplus.com/reference/set/set/erase/)– Removes the value ‘g’ from the set.
8. [clear()](http://www.cplusplus.com/reference/set/set/clear/)  – Removes all the elements from the set.
9. [swap()](http://www.cplusplus.com/reference/set/set/swap/)– This function is used to exchange the contents of two sets but the sets must be of same type, although sizes may differ.
10. [emplace()](http://www.cplusplus.com/reference/set/set/emplace/)– This function is used to insert a new element into the set container, only if the element to be inserted is unique and does not already exists in the set.
11. [emplace_hint()](http://www.cplusplus.com/reference/set/set/emplace_hint/)– Returns an iterator pointing to the position where the insertion is done. If the element passed in the parameter already exists, then it returns an iterator pointing to the position where the existing element is.

**Iterators:**  Used to work with the set iterators.

12.  [begin()](http://www.cplusplus.com/reference/set/set/begin/)  – Returns an iterator pointing to the first element in the set.
13.  [end()](http://www.cplusplus.com/reference/set/set/end/)  – Returns an iterator pointing to the theoretical element that follows the last element in the set.
14.  [rbegin()](http://www.cplusplus.com/reference/set/set/rbegin/)  – Returns a reverse iterator pointing to the last element in the set (reverse beginning). It moves from last to first element
15.  [rend()](http://www.cplusplus.com/reference/set/set/rend/)  – Returns a reverse iterator pointing to the theoretical element preceding the first element in the set (considered as reverse end).
16.  [cbegin()](http://www.cplusplus.com/reference/set/set/cbegin/)  – Returns a constant iterator pointing to the first element in the set.
17.  [cend()](http://www.cplusplus.com/reference/set/set/cend/)  – Returns a constant iterator pointing to the theoretical element that follows the last element in the set.
18.  [crbegin()](http://www.cplusplus.com/reference/set/set/crbegin/)  – Returns a constant reverse iterator pointing to the last element in the set (reverse beginning). It moves from last to first element
19.  [crend()](http://www.cplusplus.com/reference/set/set/crend/)  – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the set (considered as reverse end).

**Observers:** Used to do observations such as comparing.

20. [key_comp()](http://www.cplusplus.com/reference/set/set/key_comp/) - Returns the object that determines how the keys in the set are ordered (‘<‘ by default).
21. [value_comp()](http://www.cplusplus.com/reference/set/set/value_comp/) – Returns the object that determines how the elements in the set are ordered (‘<‘ by default).

**Operations:** Used to do certain operations on the set.

22. [find(const g)](http://www.cplusplus.com/reference/set/set/find/)  – Returns an iterator to the element ‘g’ in the set if found, else returns the iterator to end.
13. [count(const g)](http://www.cplusplus.com/reference/set/set/count/)  – Returns 1 or 0 based on the element ‘g’ is present in the set or not.
24. [lower_bound(const g)](http://www.cplusplus.com/reference/set/set/lower_bound/)  – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the set.
25. [upper_bound(const g)](http://www.cplusplus.com/reference/set/set/upper_bound/)  – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will go after the element ‘g’ in the set.
26. [equal_range()](http://www.cplusplus.com/reference/set/set/equal_range/)– The function returns an iterator of pairs. (key_comp). The pair refers to the range that includes all the elements in the container which have a key equivalent to k.

> **Note:** Set does not have element access functions.

**Allocator:** Used for dynamic allocation.

27. [get_allocator()](http://www.cplusplus.com/reference/set/set/get_allocator/)– Returns the copy of the allocator object associated with the set.

## std::map The Dictionary Set
In C++ if I talk about a map like dictionary, the STL feature let's me to do it is std::map. **Maps are associative containers that store elements in a mapped fashion.** Each element has a key value and a mapped value. No two mapped values can have same key values.

Let's consider the following example...

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
The result of above example is...

    Binary source: ./map_learn

	Example of Standard Template Library Map.

	Printing all the values using iterator.
	KEY:    VALUE:
	1       10
	2       20
	3       30
	4       40
	5       50

	Printing all the values using constant reverse iterator.
	KEY:    VALUE:
	5       50
	4       40
	3       30
	2       20
	1       10
	
	Printing all the values after removing first 3 elements.
	KEY:    VALUE:
	4       40
	5       50

	Size: 2
	Max size: 178956970

	The map is not empty.
	The element of index 2 not found!

	The key 1 is absent.

	Printing all the values after using emplace_hint() method.
	KEY:    VALUE:
	1       10
	2       20
	3       30
	4       40
	5       50
	Element at key 3: 30

	map1.lower_bound(5) :   KEY = 5         ELEMENT = 50
	map1.upper_bound(5) :   KEY = 5         ELEMENT = 1
***std::map***

    template <class Key,                                     // map::key_type
              class T,                                       // map::mapped_type
              class Compare = less<Key>,                     // map::key_compare
              class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
            > class map;
***Description of template parameters:***
1. **Key: ** Type of the  _keys_. Each element in a  map  is uniquely identified by its key value.  
Aliased as member type  map::key_type.

2. **T:** Type of the mapped value. Each element in a  map  stores some data as its mapped value.  
Aliased as member type  map::mapped_type.

3. **Compare:** A binary predicate that takes two element keys as arguments and returns a  bool. The expression  comp(a,b), where  _comp_  is an object of this type and  _a_  and  _b_  are key values, shall return  true  if  _a_  is considered to go before  _b_  in the  _strict weak ordering_  the function defines.  
The  map  object uses this expression to determine both the order the elements follow in the container and whether two element keys are equivalent (by comparing them reflexively: they are equivalent if  !comp(a,b) && !comp(b,a)). No two elements in a  map  container can have equivalent keys.  
This can be a function pointer or a function object (see  [constructor](http://www.cplusplus.com/map::map)  for an example). This defaults to  [less](http://www.cplusplus.com/less)<T>, which returns the same as applying the  _less-than operator_  (a<b).  
Aliased as member type  map::key_compare.

4. **Alloc:** Type of the allocator object used to define the storage allocation model. By default, the  [allocator](http://www.cplusplus.com/allocator)  class template is used, which defines the simplest memory allocation model and is value-independent.  
Aliased as member type  map::allocator_type.

> **Note:** Use [std::pair]([http://www.cplusplus.com/reference/utility/pair/?kw=pair) to add elements with key in std::map.

### Short description of std::map methods
**Capacity:** Used to operate on capacity of a certain map.

1. [size()](http://www.cplusplus.com/reference/map/map/size/)– Returns the number of elements in the map.
2. [empty()](http://www.cplusplus.com/reference/map/map/empty/)– Returns whether the map is empty.
3. [max_size()](http://www.cplusplus.com/reference/map/map/max_size/)– Returns the maximum number of elements a map container can hold.

**Element Access:** Used to access a particular element.

4. [at()](http://www.cplusplus.com/reference/map/map/at/)– **at()** function is used to return the reference to the element associated with the key k.
5. [operator[]](http://www.cplusplus.com/reference/map/map/operator[]/)– This operator is used to reference the element present at position given inside the operator.

**Modifiers:** Used to modify certain map.

6. [insert()](https://www.geeksforgeeks.org/map-insert-in-c-stl/)– Insert elements with a particular key in the map container.
7. [erase()](http://www.cplusplus.com/reference/map/map/erase/)– Used to erase element from the container.
8. [swap()](http://www.cplusplus.com/reference/map/map/swap/)– **swap()** function is used to exchange the contents of two maps but the maps must be of same type, although sizes may differ.
9. [clear()](http://www.cplusplus.com/reference/map/map/clear/)– Removes all the elements from the map.
10. [emplace()](http://www.cplusplus.com/reference/map/map/emplace/)– Inserts the key and its element in the map container. 
11. [emplace_hint()](http://www.cplusplus.com/reference/map/map/emplace_hint/)– Inserts the key and its element in the map container with a given hint.

**Iterators:**  Used to work with the map iterators.

12.  [begin()](http://www.cplusplus.com/reference/map/map/begin/)  – Returns an iterator pointing to the first element in the map.
13.  [end()](http://www.cplusplus.com/reference/map/map/end/)  – Returns an iterator pointing to the theoretical element that follows the last element in the map.
14.  [rbegin()](http://www.cplusplus.com/reference/map/map/rbegin/)  – Returns a reverse iterator pointing to the last element in the map (reverse beginning). It moves from last to first element
15.  [rend()](http://www.cplusplus.com/reference/map/map/rend/)  – Returns a reverse iterator pointing to the theoretical element preceding the first element in the map (considered as reverse end).
16.  [cbegin()](http://www.cplusplus.com/reference/map/map/cbegin/)  – Returns a constant iterator pointing to the first element in the map.
17.  [cend()](http://www.cplusplus.com/reference/map/map/cend/)  – Returns a constant iterator pointing to the theoretical element that follows the last element in the map.
18.  [crbegin()](http://www.cplusplus.com/reference/map/map/crbegin/)  – Returns a constant reverse iterator pointing to the last element in the map (reverse beginning). It moves from last to first element
19.  [crend()](http://www.cplusplus.com/reference/map/map/crend/)  – Returns a constant reverse iterator pointing to the theoretical element preceding the first element in the map (considered as reverse end).

**Observers:** Used to do observations such as comparing.

20. [key_comp()](http://www.cplusplus.com/reference/map/map/key_comp/) - Returns the object that determines how the keys in the map are ordered (‘<‘ by default).
21. [value_comp()](http://www.cplusplus.com/reference/map/map/value_comp/) – Returns the object that determines how the elements in the map are ordered (‘<‘ by default).

**Operations:** Used to do certain operations on the map.

22. [find(const g)](http://www.cplusplus.com/reference/map/map/find/)  – Returns an iterator to the element ‘g’ in the map if found, else returns the iterator to end.
13. [count(const g)](http://www.cplusplus.com/reference/map/map/count/)  – Returns 1 or 0 based on the element ‘g’ is present in the map or not.
24. [lower_bound(const g)](http://www.cplusplus.com/reference/map/map/lower_bound/)  – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will not go before the element ‘g’ in the map.
25. [upper_bound(const g)](http://www.cplusplus.com/reference/map/map/upper_bound/)  – Returns an iterator to the first element that is equivalent to ‘g’ or definitely will go after the element ‘g’ in the map.
26. [equal_range()](http://www.cplusplus.com/reference/map/map/equal_range/)– The function returns an iterator of pairs. (key_comp). The pair refers to the range that includes all the elements in the container which have a key equivalent to k.

**Allocator:** Used for dynamic allocation.

27. [get_allocator()](http://www.cplusplus.com/reference/map/map/get_allocator/)– Returns the copy of the allocator object associated with the map.

## Binary manipulation with std::bitset
