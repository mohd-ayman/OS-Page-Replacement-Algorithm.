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
    void runFIFO() {
        cout << "\n\n=== FIFO Algorithm Simulation ===\n";
        printHeader();

        vector<int> frames;
        int pageFaults = 0;
        int hitCount = 0;
        int insertIndex = 0;

        for (int i = 0; i < pages.size(); i++) {
            int currentPage = pages[i];
            bool hit = false;

            for (int f : frames) {
                if (f == currentPage) {
                    hit = true;
                    hitCount++;
                    break;
                }
            }

            if (!hit) {
                if (frames.size() < numFrames) {
                    frames.push_back(currentPage);
                } else {
                    frames[insertIndex] = currentPage;
                    insertIndex = (insertIndex + 1) % numFrames;
                }
                pageFaults++;
            }
            printFrameState(i + 1, currentPage, frames, hit);
        }
        printStats(pageFaults, hitCount);
    }

    void runLRU() {
        cout << "\n\n=== LRU Algorithm Simulation ===\n";
        printHeader();

        vector<int> frames;
        int pageFaults = 0;
        int hitCount = 0;

        for (int i = 0; i < pages.size(); i++) {
            int currentPage = pages[i];
            bool hit = false;
            int hitIndex = -1;

            for (int j = 0; j < frames.size(); j++) {
                if (frames[j] == currentPage) {
                    hit = true;
                    hitIndex = j;
                    hitCount++;
                    break;
                }
            }

            if (hit) {
                frames.erase(frames.begin() + hitIndex);
                frames.push_back(currentPage);
            } else {
                pageFaults++;
                if (frames.size() < numFrames) {
                    frames.push_back(currentPage);
                } else {
                    frames.erase(frames.begin());
                    frames.push_back(currentPage);
                }
            }
            printFrameState(i + 1, currentPage, frames, hit);
        }
        printStats(pageFaults, hitCount);
    }
    void runOptimal() {
        cout << "\n\n=== Optimal Algorithm Simulation ===\n";
        printHeader();

        vector<int> frames;
        int pageFaults = 0;
        int hitCount = 0;

        for (int i = 0; i < pages.size(); i++) {
            int currentPage = pages[i];
            bool hit = false;

            for (int f : frames) {
                if (f == currentPage) {
                    hit = true;
                    hitCount++;
                    break;
                }
            }

            if (!hit) {
                pageFaults++;
                if (frames.size() < numFrames) {
                    frames.push_back(currentPage);
                } else {
                    int farthestIndex = -1;
                    int frameToReplace = -1;

                    for (int j = 0; j < frames.size(); j++) {
                        int currentFrameVal = frames[j];
                        int nextUseIndex = -1;

                        for (int k = i + 1; k < pages.size(); k++) {
                            if (pages[k] == currentFrameVal) {
                                nextUseIndex = k;
                                break;
                            }
                        }

                        if (nextUseIndex == -1) {
                            frameToReplace = j;
                            break; 
                        }

                        if (nextUseIndex > farthestIndex) {
                            farthestIndex = nextUseIndex;
                            frameToReplace = j;
                        }
                    }
                    if (frameToReplace == -1) frameToReplace = 0;
                    frames[frameToReplace] = currentPage;
                }
            }
            printFrameState(i + 1, currentPage, frames, hit);
        }
        printStats(pageFaults, hitCount);
    }
    void printStats(int faults, int hits) {
        int total = faults + hits;
        cout << "+------+------+";
        for (int i = 0; i < numFrames; i++) cout << "-----+";
        cout << "------+" << endl;
        cout << "Total Page Faults: " << faults << endl;
        cout << "Total Page Hits: " << hits << endl;
        cout << "Hit Ratio: " << fixed << setprecision(2) << ((double)hits / total) * 100 << "%" << endl;
    }
};

int main() {
    cout << "OS Project Initialized..." << endl;
    return 0;
}
