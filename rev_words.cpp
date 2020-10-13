#include <iostream>
#include <string>
using namespace std;

string rev_words(string s) {
    int n = s.size(), start = 0;
    for(int end = 0; end < n; end++) {
        if(s[end] == ' ') {
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
    }
    reverse(s.begin() + start, s.end());
    reverse(s.begin(), s.end());
    return s;
}

int main() {
    string s = "The quick brown fox jumps over the wooden fence";
    cout<< rev_words(s);
    return 0;
}

