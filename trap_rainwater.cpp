#include <iostream>
#include <vector>
using namespace std;

int rain_water(vector<int> vec) {
    int n = vec.size(), temp = 0;
    int prev = vec[0], prev_index = -1, water = 0;

    for(int i = 0; i < n; i++) {
        if(vec[i] >= prev) {
            prev = arr[i];
            prev_index = i;
            temp = 0;
        }
        else {
            water +=  prev - vec[i];
            temp += prev - vec[i];
        }
    }

    if(prev_index < size) {
        water -= temp;
        prev = vec[n-1];

        for(int i = n-1; i >= prev_index; i--) {
            if(arr[i] >= prev)
                prev = arr[i];
            else
                water += prev - arr[i];
        }
    }
    return water;
}

int main() {
    vector<int> vec = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout<< rain_water(vec);
    return 0;
}
