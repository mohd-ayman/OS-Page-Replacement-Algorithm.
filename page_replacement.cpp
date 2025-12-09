#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class PageReplacementSimulator {
private:
    vector<int> pages;
    int numFrames;

public:
    void input() {
        int n, val;
        cout << "\n=== Input Configuration ===\n";
        cout << "Enter number of Frames: ";
        cin >> numFrames;
        cout << "Enter number of Pages in reference string: ";
        cin >> n;
        cout << "Enter the reference string (space-separated): ";
        for (int i = 0; i < n; i++) {
            cin >> val;
            pages.push_back(val);
        }
    }
    void runFIFO() {}
    void runLRU() {}
    void runOptimal() {}
};

int main() {
    cout << "OS Project Initialized..." << endl;
    return 0;
}
