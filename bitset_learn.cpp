#include <iostream>
#include <bitset>

#define LIMIT 32

int main(int argc, char** argv);

int main(int argc, char** argv) {
	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "Binary source: " << argv[0] << endl << endl;
	cout << "Example of Standard Template Library Bitset." << endl << endl;

	bitset<LIMIT> bset1;				// An empty bitset.
	bitset<LIMIT> bset2(7);				// Binary set of number 7.
	bitset<LIMIT> bset3(string("1101"));	// String representation of binary 13.

	cout << "Empty bitset: " << bset1 << endl;
	cout << "Bitset representing number 7: " << bset2 << endl;
	cout << "Bitset of 13(Represented with string): " << bset3 << endl << endl;

     bitset<8> bset8b;

     bset8b[0] = 1;		// 00000001;
     bset8b.set(4, 1);	// 00010001; Alternative: bitset<LIMIT> set(pos, b) { *this[pos] = b; return *this; }

     cout << bset8b << endl;

     size_t numb1 = bset8b.count();

     cout << "bset8b has " << numb1 << " set(1) and " << (bset8b.size() - numb1) << " unset(0)." << endl << endl;

     if(!bset1.any())
		cout << "bset1 has no set(1) bits." << endl;

	if(!bset2.none())
		cout << "bset2 has at least 1 bit set(1)." << endl;

	cout << endl << "After setting all the bits in bset1..." << endl;
	cout << bset1.set() << endl;

	cout << endl << "Reseting all the bits of bset8b." << endl;
	cout << bset8b.reset() << endl << endl;

	// reset(pos, b) and reset(pos) does the opposite of set(pos, b) and set(pos).

	cout << "A Decimal: " << 100 << ", Binary representation: " << bitset<8>(100) << endl << endl;

	cout << "\tLOGICAL OPERATIONS" << endl << endl;

	bitset<4> bsetm(9); // bset1 contains 1001
	bitset<4> bsetn(3); // bset2 contains 0011

	// comparison operator
	cout << (bsetm == bsetn) << endl; // false 0
	cout << (bsetm != bsetn) << endl; // true  1

	// left and right shifting
	cout << (bsetm << 2) << endl; // 1100
	cout << (bsetm >> 1) << endl; // 0110

	// not operator
	cout << (~bsetn) << endl; // 1100

	// bitwise operator
	cout << (bsetm & bsetn) << endl; // 0010
	cout << (bsetm | bsetn) << endl; // 0111
	cout << (bsetm ^ bsetn) << endl; // 0101

     return 0;
}
