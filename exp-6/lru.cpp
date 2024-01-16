#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
private:
    int capacity;
    list<int> recentList;                      // List to maintain the order of recently used pages
    unordered_map<int, list<int>::iterator> pageMap; // Map to store page numbers and their positions in the list
    int pageFaults;

public:
    LRUCache(int cap) : capacity(cap), pageFaults(0) {}

    void refer(int pageNum) {
        // If page is not in the cache
        if (pageMap.find(pageNum) == pageMap.end()) {
            // Check if the cache is full
            if (recentList.size() == capacity) {
                int leastRecent = recentList.back();
                recentList.pop_back();
                pageMap.erase(leastRecent);
                cout << "Page " << leastRecent << " is replaced by Page " << pageNum << " (Page Fault)\n";
            }
            ++pageFaults;
        } else {
            // If the page is in the cache, remove it from the current position
            recentList.erase(pageMap[pageNum]);
        }

        // Add the page to the front of the list and update its position in the map
        recentList.push_front(pageNum);
        pageMap[pageNum] = recentList.begin();
        cout << "Page " << pageNum << " is loaded into memory (Page Fault)\n";
    }

    int getPageFaults() const {
        return pageFaults;
    }
};

int main() {
    int capacity;
    cout << "Enter the capacity of the memory: ";
    cin >> capacity;

    LRUCache lruCache(capacity);

    int n;
    cout << "Enter the number of reference string elements: ";
    cin >> n;

    cout << "Enter the reference string elements:\n";
    for (int i = 0; i < n; ++i) {
        int pageNum;
        cin >> pageNum;
        lruCache.refer(pageNum);
    }

    cout << "Total Page Faults: " << lruCache.getPageFaults() << endl;

    return 0;
}