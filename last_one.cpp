#include <iostream>
#include <string>
using namespace std;

int last_one(string s) {
    int n = s.size(), index = -1;
    for(int i = n-1; i >= 0; i++) {
        if(s[i] == '1') {
            index = i;
            break;
        }
    }
    return index;
}

int main() {
    string s = "010101010101010100";
    cout<<last_one(s);
    return 0;
}

