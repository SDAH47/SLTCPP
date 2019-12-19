#include <iostream>
#include <variant>
#include <string>
#include <cassert>

int main(int argc, char** argv);

int main(int argc, char** argv) {
	using namespace std;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cout << "Binary source: " << argv[0] << endl << endl;
	cout << "Example of Standard Template Library Variant." << endl << endl;

    variant<int, string> v1, v2;

    v1 = 100;
    v2 = "SDAH";
    v1 = get<string>(v2);
    v2 = 100;

    cout << "V1 holds: " << get<string>(v1) << ", V2 holds: " << get<int>(v2) << endl;

    // Bad_variant_access...
    try {
	    get<int>(v1);
    } catch(bad_variant_access&) {}

    using namespace string_literals;

    // Example of void const* with string.

    variant<string, void const*> anVar("SDAH");

    assert(holds_alternative<void const*>(anVar));	// Will succeed.

    // Conversion constructor.
    anVar = "SDAH"s;

    assert(holds_alternative<string>(anVar));		// Will succeed.

    return 0;
}
