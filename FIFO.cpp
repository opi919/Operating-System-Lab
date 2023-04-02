#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

int fifo(int num_frames, string ref_str) {
    int n = ref_str.length();
    queue<char> frames;
    unordered_set<char> s;
    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        char page = ref_str[i];

        // If page is not present in the set, it's a page fault
        if (s.find(page) == s.end()) {
            // If all the page frames are full, remove the oldest page from the queue
            if (frames.size() == num_frames) {
                s.erase(frames.front());
                frames.pop();
            }
            // Add the new page to the set and the back of the queue
            s.insert(page);
            frames.push(page);
            page_faults++;
        }
    }

    return page_faults;
}

int main() {
    int num_frames;
    string ref_str;
    cout << "Enter the number of page frames: ";
    cin >> num_frames;
    cout << "Enter the reference string: ";
    cin >> ref_str;
    
    int page_faults = fifo(num_frames, ref_str);

    cout << "Number of page faults: " << page_faults << endl;
    return 0;
}
