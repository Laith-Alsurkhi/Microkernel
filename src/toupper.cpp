
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main(int argc, char* argv[]) {
    string user = (argc > 1 ? argv[1] : "Anonymous");
    string ts = (argc > 2 ? argv[2] : "Unknown");

    cout << "[ToUpper] Hello " << user << " (" << ts << ")\n";
    cout << "Enter text: ";

    string s;
    getline(cin, s);

    for (char& ch : s) {
        ch = (char)toupper((unsigned char)ch);
    }

    cout << "Uppercase: " << s << "\n";
    return 0;
}
