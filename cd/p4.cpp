#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Parser {
public:
  int n, nt = 0, t = 0, m[20][20];
  string p[30], N[20], T[20], f[20], fl[20];

  int findN(char c) {
    for (int i = 0; i < nt; i++)
      if (N[i][0] == c)
        return i;
    return -1;
  }

  int findT(char c) {
    for (int i = 0; i < t; i++)
      if (T[i][0] == c)
        return i;
    return -1;
  }

  void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> p[i];
  }

  void process() {
    for (int i = 0; i < n; i++)
      if (findN(p[i][0]) == -1)
        N[nt++] = p[i].substr(0, 1);

    for (int i = 0; i < n; i++)
      for (int j = 3; j < p[i].size(); j++)
        if (p[i][j] != 'e' && findN(p[i][j]) == -1 && findT(p[i][j]) == -1)
          T[t++] = string(1, p[i][j]);

    T[t++] = "$";
    memset(m, -1, sizeof(m));

    for (int i = 0; i < nt; i++)
      cin >> f[i];
    for (int i = 0; i < nt; i++)
      cin >> fl[i];

    for (int i = 0; i < n; i++) {
      int lhs = findN(p[i][0]);
      char rhs = p[i][3];

      if (int ti = findT(rhs); ti != -1)
        m[lhs][ti] = i;
      else if (int ni = findN(rhs); ni != -1)
        for (char c : f[ni])
          if (int ti = findT(c); ti != -1)
            m[lhs][ti] = i;

      if (rhs == 'e')
        for (char c : fl[lhs])
          if (int ti = findT(c); ti != -1)
            m[lhs][ti] = i;
    }

    print();
  }

  void print() {
    cout << "\nParsing Table:\n\t";
    for (int i = 0; i < t; i++)
      cout << T[i] << "\t";
    cout << "\n";

    for (int i = 0; i < nt; i++) {
      cout << N[i];
      for (int j = 0; j < t; j++)
        cout << "\t" << (m[i][j] != -1 ? p[m[i][j]] : "-");
      cout << "\n";
    }
  }
};

int main() {
  freopen("input.txt", "r", stdin); // Read from file
  Parser p;
  p.input();
  p.process();
}
