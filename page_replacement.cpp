#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

using namespace std;

class PageReplacementSimulator {
private:
    vector<int> pages;
    int numFrames;

    void printFrameState(int step, int page, const vector<int>& frames, bool hit) {
        cout << "| " << setw(4) << step << " | " << setw(4) << page << " | ";
        for (int i = 0; i < numFrames; i++) {
            if (i < frames.size()) {
                cout << setw(3) << frames[i] << " |";
            } else {
                cout << "  -  |";
            }
        }
        if (hit) cout << " Hit  |" << endl;
        else     cout << " Miss |" << endl;
    }


    void printHeader() {
        cout << "+------+------+";
        for (int i = 0; i < numFrames; i++) cout << "-----+";
        cout << "------+" << endl;
        
        cout << "| Step | Page |";
        for (int i = 0; i < numFrames; i++) cout << " F" << i + 1 << "  |";
        cout << " Stat |" << endl;

        cout << "+------+------+";
        for (int i = 0; i < numFrames; i++) cout << "-----+";
        cout << "------+" << endl;
    }

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
