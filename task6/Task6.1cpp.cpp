#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
void printVector(const vector<int>& v) {
    cout << "Vector: ";
    for (int num : v) cout << num << " ";
    cout << endl;
}
void reverse_in_place(vector<int>& v) {
    for (size_t i = 0; i < v.size() / 2; i++) {
        swap(v[i], v[v.size() - 1 - i]);
    }
}
void countFrequency(const vector<int>& v) {
    map<int, int> freq;
    for (int num : v) freq[num]++;

    cout << "Frequencies of elements:\n";
    for (auto& pair : freq) {
        cout << pair.first << " -> " << pair.second << endl;
    }
}
void findSecondLargest(const vector<int>& v) {
    if (v.size() < 2) {
        cout << "Not enough elements.\n";
        return;
    }
    vector<int> temp = v;
    sort(temp.begin(), temp.end());
    cout << "Second largest element: " << temp[temp.size() - 2] << endl;
}
void removeDuplicates(vector<int>& v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    cout << "After removing duplicates: ";
    printVector(v);
}
int main() {
    vector<int> v = { 1, 2, 2, 3, 3, 4, 5 };
    cout << "Original vector:\n";
    printVector(v);
    cout << "\n---- Reverse in place ----\n";
    reverse_in_place(v);
    printVector(v);
    cout << "\n---- Count of occurrences ----\n";
    countFrequency(v);
    cout << "\n---- Find second largest ----\n";
    findSecondLargest(v);
    cout << "\n---- Remove duplicates ----\n";
    removeDuplicates(v);
    return 0;
}
