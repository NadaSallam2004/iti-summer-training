#include <iostream>
#include <vector>
#include <algorithm> // for sort, erase, etc.
using namespace std;

int main() {
    // Create vector with initializer list
    vector<int> v = { 1, 2, 3, 4, 5 };

    // Capacity-related functions
    cout << "Size: " << v.size() << endl;
    cout << "Capacity: " << v.capacity() << endl;
    cout << "Max size: " << v.max_size() << endl;

    // Reserve and shrink_to_fit
    v.reserve(20);
    cout << "Capacity after reserve(20): " << v.capacity() << endl;
    v.shrink_to_fit();
    cout << "Capacity after shrink_to_fit: " << v.capacity() << endl;

    // Access functions
    cout << "Front: " << v.front() << endl;
    cout << "Back: " << v.back() << endl;
    cout << "At(2): " << v.at(2) << endl;
    cout << "Operator[](3): " << v[3] << endl;

    // Data pointer
    int* rawData = v.data();
    cout << "First element via data(): " << *rawData << endl;

    // Modifiers
    v.push_back(6);              // add element at end
    v.emplace_back(7);           // construct element at end
    v.insert(v.begin() + 2, 10); // insert element at position
    v.insert(v.end(), { 8, 9 });   // insert multiple elements
    v.pop_back();                // remove last element
    v.erase(v.begin() + 1);      // erase element at position
    v.erase(v.begin(), v.begin() + 2); // erase range
    v.resize(5);                 // resize vector
    v.assign(3, 42);             // assign new values
    vector<int> v2 = { 100, 200 };
    v.swap(v2);                  // swap contents
    v.clear();                   // clear all elements

    // Iterators
    v = { 1, 2, 3, 4, 5 };
    cout << "Iterating with begin/end: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout << endl;

    cout << "Iterating with rbegin/rend: ";
    for (auto rit = v.rbegin(); rit != v.rend(); ++rit)
        cout << *rit << " ";
    cout << endl;

    // Comparison operators
    vector<int> v3 = { 1, 2, 3, 4, 5 };
    cout << "v == v3? " << (v == v3 ? "true" : "false") << endl;
    cout << "v < v3? " << (v < v3 ? "true" : "false") << endl;

    // Allocator
    auto alloc = v.get_allocator();
    int* p = alloc.allocate(5); // allocate raw memory
    alloc.deallocate(p, 5);     // deallocate raw memory

    // Final print
    cout << "Final vector elements: ";
    for (int n : v)
        cout << n << " ";
    cout << endl;

    return 0;
}
