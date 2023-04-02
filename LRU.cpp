#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

int lru(int num_frames, string ref_str)
{
    int n = ref_str.length();

    list<char> frames;
    unordered_map<char, list<char>::iterator> mp;
    int page_faults = 0;

    for (int i = 0; i < n; i++)
    {
        char page = ref_str[i];

        // If page is not present in the map, it's a page fault
        if (mp.find(page) == mp.end())
        {
            // If all the page frames are full, remove the least recently used page from the list and the map
            if (frames.size() == num_frames)
            {
                char last = frames.back();
                frames.pop_back();
                mp.erase(last);
            }
            // Add the new page to the front of the list and the map
            frames.push_front(page);
            mp[page] = frames.begin();
            page_faults++;
        }
        // If page is already present in the map, move its node to the front of the list
        else
        {
            frames.erase(mp[page]);
            frames.push_front(page);
            mp[page] = frames.begin();
        }
    }
    return page_faults;
}

int main()
{
    int num_frames;
    string ref_str;
    cout << "Enter the number of page frames: ";
    cin >> num_frames;
    cout << "Enter the reference string: ";
    cin >> ref_str;

    int page_faults = lru(num_frames, ref_str);
    cout << "Number of page faults: " << page_faults << endl;
    return 0;
}
