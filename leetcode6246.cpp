#include <iostream>
#include <string>
using namespace std;

int appendCharacters(string s, string t) {
  int si = 0, ti = 0;
  while (si < s.size() && ti < t.size()) {
    if (s[si] == t[ti]) {
      ++si;
      ++ti;
    } else {
      ++si;
    }
  }
  return t.size() - ti;
}

int main() {
  string s;
  string t;
  do {
    cin >> s;
    cin >> t;
    cout << appendCharacters(s, t) << "\n";
  } while (s != "");
  return 0;
}
