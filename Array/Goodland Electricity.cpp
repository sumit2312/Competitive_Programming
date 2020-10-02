// https://www.hackerrank.com/challenges/pylons/problem

int pylons(int k, vector<int> arr) {
    int stations = 0;
    for (int i = 0; i < arr.size(); ) {
        bool found = false;
        for (int j = min(i + k - 1, (int)arr.size() - 1); j >= max(0, i - k + 1); --j) {
            if (arr[j] == 1) {
                found = true;
                stations += 1;
                i = j + k;
                break;
            }
        }
        if (!found) return -1;
    }
    return stations;    
}
