
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string getTimestamp() {
    time_t vrNow = time(nullptr);
    tm vrTm{};
    localtime_s(&vrTm, &vrNow);  // MSVC-safe
    char vrBuffer[64];
    strftime(vrBuffer, sizeof(vrBuffer), "%Y-%m-%d %H:%M:%S", &vrTm);
    return vrBuffer;
}

int main() {
    string vrUserName;
    cout << "Enter your name: ";
    getline(cin, vrUserName);
    if (vrUserName.empty()) vrUserName = "Anonymous";

    string vrTimestamp = getTimestamp();
    cout << "Hello, " << vrUserName << "! (" << vrTimestamp << ")\n\n";

    ifstream vrRegistryFile("registry_windows.txt");
    if (!vrRegistryFile) {
        cerr << "Registry file not found!\n";
        return 1;
    }

    vector<string> vrPlugins;
    string vrLine;
    while (getline(vrRegistryFile, vrLine)) {
        if (!vrLine.empty()) vrPlugins.push_back(vrLine);
    }

    while (true) {
        cout << "\n=== Menu ===\n";
        for (size_t i = 0; i < vrPlugins.size(); ++i) {
            cout << (i + 1) << ") " << vrPlugins[i] << "\n";
        }
        cout << "0) Exit\nChoose: ";

        int vrChoice;
        if (!(cin >> vrChoice)) return 0;
        cin.ignore();

        if (vrChoice == 0) break;
        if (vrChoice < 1 || vrChoice >(int)vrPlugins.size()) {
            cout << "Invalid choice.\n";
            continue;
        }

        string vrPlugin = vrPlugins[vrChoice - 1];
        // Ensure .exe if the registry doesn't include it
        if (vrPlugin.size() < 4 || vrPlugin.substr(vrPlugin.size() - 4) != ".exe") {
            vrPlugin += ".exe";
        }

        string vrCommand = ".\\" + vrPlugin +
            " \"" + vrUserName + "\" \"" + vrTimestamp + "\"";
        system(vrCommand.c_str());
    }
    return 0;
}
