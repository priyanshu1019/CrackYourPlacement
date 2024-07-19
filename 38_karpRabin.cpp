#include <bits/stdc++.h>
using namespace std;

int PRIME = 101;

long long calculateHash(string str) {
    long long hash = 0;
    long long primePower = 1;
    for (int i = 0; i < str.size(); i++) {
        hash = hash + str[i] * primePower;
        primePower *= PRIME;
    }
    return hash;
}

long long updateHash(long long prevHash, char oldChar, char newChar, int patLength) {
    long long newHash = (prevHash - oldChar) / PRIME;
    long long primePower = 1;
    for (int i = 1; i < patLength; i++) {
        primePower *= PRIME;
    }
    newHash = newHash + newChar * primePower;
    return newHash;
}

void search(string str, string pat) {
    int n = str.size();
    int m = pat.size();
    long long strHash = calculateHash(str.substr(0, m));
    long long patHash = calculateHash(pat);

    for (int i = 0; i <= n - m; i++) {
        if (strHash == patHash) {
            if (str.substr(i, m) == pat) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        if (i < n - m) {
            strHash = updateHash(strHash, str[i], str[i + m], m);
        }
    }
}

int main() {
    string str = "prianshubipingoutampinpinpin";
    string pat = "pinpin";
    search(str, pat);
    return 0;
}
