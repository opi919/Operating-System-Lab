#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

struct Page {
    int id;               
    int reference_bit;    
};

int main() {
    int num_frames;
    string ref_str;
    cout << "Enter the number of page frames: ";
    cin >> num_frames;
    cout << "Enter the reference string: ";
    cin >> ref_str;
    int n = ref_str.length();

    queue<Page> frames;
    unordered_map<int, Page> mp;

    int page_faults = 0;

    for (int i = 0; i < n; i++) {
        int page_id = ref_str[i] - '0';

        // If the page is not in the map, it's a page fault
        if (mp.find(page_id) == mp.end()) {
            // Create a new Page object with a reference bit of 1
            Page page = {page_id, 1};

            // If all the page frames are full, remove the oldest page with a reference bit of 0
            if (frames.size() == num_frames) {
                while (true) {
                    // Get the oldest page in the frames queue
                    Page p = frames.front();
                    frames.pop();

                    // If the reference bit is 0, remove the page from the map and break out of the loop
                    if (p.reference_bit == 0) {
                        mp.erase(p.id);
                        break;
                    }
                    // If the reference bit is 1, set it to 0 and add the page back to the frames queue and map
                    else {
                        p.reference_bit = 0;
                        frames.push(p);
                        mp[p.id] = p;
                    }
                }
            }

            frames.push(page);
            mp[page_id] = page;
            page_faults++;
        }
        // If the page is already in the map, set its reference bit to 1
        else {
            Page page = mp[page_id];
            page.reference_bit = 1;
            mp[page_id] = page;
        }
    }

    cout << "Number of page faults: " << page_faults << endl;
    return 0;
}
