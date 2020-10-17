#include <iostream>
#include <vector>
using namespace std;

int kadane(vector<int> vec) {
    int n = vec.size();
    int max_so_far = INT_MIN, max_till_i = 0;

    for(int i = 0; i < n; i++) {
        max_till_i += vec[i];
        max_so_far = max(max_so_far, max_till_i);
        max_till_i = (max_till_i < 0) ? 0 : max_till_i;
    }
    return max_so_far;
}

int main(){
    vector<int> vec = {-2, -3, 4, -1, -2, 1, 5, -3};
    cout<<kadane(vec);
    return 0;
}
