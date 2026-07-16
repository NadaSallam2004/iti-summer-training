#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;
int main() {
    string s1 = "Hello";
    string s2 = "World";
    cout << "len(s1) = " << s1.length() << endl;
    string s3 = s1 + " " + s2;
    cout << "concat = " << s3 << endl;
    size_t pos = s3.find("World");
    if (pos != string::npos) {
        cout << "found 'World' at idx " << pos << endl;
    }
    string sub = s3.substr(0, 5); 
    cout << "substr = " << sub << endl;
    s3.replace(0, 5, "Hi");
    cout << "replace = " << s3 << endl;
    string up = s1;
    for (char& c : up) c = toupper(c);
    cout << "upper = " << up << endl;
    string low = s2;
    for (char& c : low) c = tolower(c);
    cout << "lower = " << low << endl;
    if (s1.compare(s2) == 0)
        cout << "s1 == s2" << endl;
    else
        cout << "s1 != s2" << endl;

    return 0;
}
