#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <climits>

using namespace std;

int optimalPageReplacement(const vector<int>& referenceString, int capacity) {
    unordered_map<int, int> pageNextUse;  // Maps page numbers to their next use index
    int pageFaults = 0;

    for (int i = 0; i < referenceString.size(); ++i) {
        int currentPage = referenceString[i];

        // Check if the page is in memory
        if (pageNextUse.find(currentPage) != pageNextUse.end()) {
            cout << "Page " << currentPage << " is already in memory (Page Hit)\n";
        } else {
            // Page fault: page is not in memory
            ++pageFaults;

            // Check if the memory is full
            if (pageNextUse.size() == capacity) {
                // Find the page with the furthest next use, check the map
                int pageToReplace = -1;
                int furthestNextUse = -1;

                for (const auto& entry : pageNextUse) {
                    int nextUseIndex = entry.second;
                    auto futureUseIt = find(referenceString.begin() + i, referenceString.end(), entry.first);

                    if (futureUseIt == referenceString.end()) {
                        // If a page will not be used in the future, select it for replacement
                        pageToReplace = entry.first;
                        break;
                    }

                    int distanceToNextUse = distance(referenceString.begin() + i, futureUseIt);
                    
                    if (distanceToNextUse > furthestNextUse) {
                        furthestNextUse = distanceToNextUse;
                        pageToReplace = entry.first;
                    }
                }

                // Remove the page with the furthest next use
                pageNextUse.erase(pageToReplace);
                cout << "Page " << pageToReplace << " is replaced by Page " << currentPage << " (Page Fault)\n";
            }

            // Add the current page to memory with its next use index
            auto nextUseIt = find(referenceString.begin() + i, referenceString.end(), currentPage);
            pageNextUse[currentPage] = (nextUseIt == referenceString.end()) ? INT_MAX : distance(referenceString.begin(), nextUseIt);

            cout << "Page " << currentPage << " is loaded into memory (Page Fault)\n";
        }
    }

    return pageFaults;
}

int main() {
    int capacity;
    cout << "Enter the capacity of the memory: ";
    cin >> capacity;

    int n;
    cout << "Enter the number of reference string elements: ";
    cin >> n;

    vector<int> referenceString(n);
    cout << "Enter the reference string elements:\n";
    for (int i = 0; i < n; ++i) {
        cin >> referenceString[i];
    }

    int pageFaults = optimalPageReplacement(referenceString, capacity);

    cout << "Total Page Faults: " << pageFaults << endl;

    return 0;
}