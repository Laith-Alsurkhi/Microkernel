#include <iostream>
using namespace std;
int main(int argc, char* argv[]) {
	string vrUserName = (argc > 1 ? argv[1] : "Anonymous");
	string vrTimestamp = (argc > 2 ? argv[2] : "Unknown");
	cout << "[Echo] Hi " << vrUserName << "! Time: " <<
		vrTimestamp << "\n";
	return 0;
}
