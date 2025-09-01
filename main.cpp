#include <bits/stdc++.h>
#include "json.hpp"
using namespace std;
using json = nlohmann::json;

__int128 convertToDecimal(const string &value, int base) {
    __int128 result = 0;
    for (char c : value) {
        int digit;
        if (isdigit(c)) digit = c - '0';
        else digit = 10 + (tolower(c) - 'a');
        result = result * base + digit;
    }
    return result;
}

void print128(__int128 x) {
    if (x == 0) { cout << "0"; return; }
    string s;
    bool neg = false;
    if (x < 0) { neg = true; x = -x; }
    while (x > 0) {
        int d = x % 10;
        s.push_back('0' + d);
        x /= 10;
    }
    if (neg) cout << "-";
    reverse(s.begin(), s.end());
    cout << s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string input, line;
    while (getline(cin, line)) input += line;
    json j = json::parse(input);

    int n = j["keys"]["n"];
    int k = j["keys"]["k"];

    vector<__int128> roots;
    for (int i = 1; i <= n && (int)roots.size() < k; i++) {
        if (j.contains(to_string(i))) {
            int base = stoi(j[to_string(i)]["base"].get<string>());
            string val = j[to_string(i)]["value"];
            roots.push_back(convertToDecimal(val, base));
        }
    }

    vector<__int128> poly = {1};
    for (__int128 r : roots) {
        vector<__int128> newPoly(poly.size() + 1, 0);
        for (size_t i = 0; i < poly.size(); i++) {
            newPoly[i] += -r * poly[i];
            newPoly[i + 1] += poly[i];
        }
        poly = newPoly;
    }

    for (size_t i = 0; i < poly.size(); i++) {
        print128(poly[i]);
        if (i + 1 < poly.size()) cout << " ";
    }
    cout << "\n";

    return 0;
}
