// sum with out error handling
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    string vrUserName = (argc > 1 ? argv[1] : "Anonymous");
    string vrTimestamp = (argc > 2 ? argv[2] : "Unknown");

    cout << "[Sum] Hello " << vrUserName << " (" << vrTimestamp << ")\n";
    cout << "Enter two integers: ";

    int vrNum1, vrNum2;

    if (!(cin >> vrNum1 >> vrNum2)) {
        cerr << "[Sum] ERROR: Bad input. Please enter two integers only.\n";
        return 1;
    }

    cout << "Result: " << (vrNum1 + vrNum2) << "\n";
    return 0;
}
