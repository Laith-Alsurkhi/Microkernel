//Plug-in: Reverse

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    string vrUserName = (argc > 1 ? argv[1] : "Anonymous");
    string vrTimestamp = (argc > 2 ? argv[2] : "Unknown");
    cout << "[Reverse] Hello " << vrUserName << " (" << vrTimestamp << ")\n";
    cout << "Enter text: ";
    string vrText;
    getline(cin, vrText);
    reverse(vrText.begin(), vrText.end());
    cout << "Reversed: " << vrText << "\n";
    return 0;
}
