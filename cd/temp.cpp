#include <cstring>
#include <iostream>
#include <string>
using namespace std;

class Parse {
  int nt, t, m[20][20], i, s, n, p1, q, k, j;
  string p[30], n1[20], t1[20], f[30],
      fl[30]; // Use string arrays for better handling
public:
  int scant(char);
  int scannt(char);
  void process();
  void input();
  void printTable();
};

int Parse::scannt(char a) {
  int c = -1;
  for (int i = 0; i < nt; i++) {
    if (n1[i][0] == a) {
      return i;
    }
  }
  return c;
}

int Parse::scant(char b) {
  int c1 = -1;
  for (int j = 0; j < t; j++) {
    if (t1[j][0] == b) {
      return j;
    }
  }
  return c1;
}

void Parse::input() {
  cout << "Enter the number of productions: ";
  cin >> n;
  cout << "Enter the productions one by one (e.g., E->TA):\n";
  for (i = 0; i < n; i++) {
    cin >> p[i];
  }
  nt = 0;
  t = 0;
}

void Parse::process() {
  // Identify non-terminals
  for (i = 0; i < n; i++) {
    if (scannt(p[i][0]) == -1) {
      n1[nt++] = p[i].substr(0, 1); // Only first character for non-terminal
    }
  }

  // Identify terminals
  for (i = 0; i < n; i++) {
    for (j = 3; j < p[i].length();
         j++) { // Start from 3rd character (right side of ->)
      if (p[i][j] != 'e') {
        if (scannt(p[i][j]) == -1) {
          if (scant(p[i][j]) == -1) {
            t1[t++] = p[i].substr(j, 1); // Terminal
          }
        }
      }
    }
  }

  t1[t++] = "$"; // Add the end symbol

  // Initialize parsing table with -1
  for (i = 0; i < nt; i++) {
    for (j = 0; j < t; j++) {
      m[i][j] = -1;
    }
  }

  // Input FIRST and FOLLOW sets
  for (i = 0; i < nt; i++) {
    cout << "Enter first[" << n1[i] << "]: ";
    cin >> f[i];
  }

  for (i = 0; i < nt; i++) {
    cout << "Enter follow[" << n1[i] << "]: ";
    cin >> fl[i];
  }

  // Fill the parsing table
  for (i = 0; i < n; i++) {
    p1 = scannt(p[i][0]);
    if ((q = scant(p[i][3])) != -1) {
      m[p1][q] = i;
    }
    if ((q = scannt(p[i][3])) != -1) {
      for (j = 0; j < f[q].length(); j++) {
        m[p1][scant(f[q][j])] = i;
      }
    }
    if (p[i][3] == 'e') {
      for (j = 0; j < fl[p1].length(); j++) {
        m[p1][scant(fl[p1][j])] = i;
      }
    }
  }

  // Print the parsing table
  printTable();
}

void Parse::printTable() {
  // Print headers
  cout << "\nParsing Table:\n";
  for (i = 0; i < t; i++) {
    cout << "\t" << t1[i];
  }
  cout << endl;

  // Print each row
  for (j = 0; j < nt; j++) {
    cout << n1[j]; // Non-terminal in the first column
    for (i = 0; i < t; i++) {
      cout << "\t";
      if (m[j][i] != -1) {
        cout << p[m[j][i]]; // Print production rule
      } else {
        cout << "-"; // Placeholder for empty entries
      }
    }
    cout << endl;
  }
}

int main() {
  Parse p;
  p.input();
  p.process();
  return 0;
}

/*output
Enter the number of productions: 8
Enter the productions one by one (e.g., E->TA):
E->TA
A->+TA
A->e
T->FB
B->e
T->FB
B->e
B->*FB
F->(E)
F->i
Enter first[E]: (i
Enter first[A]: +e
Enter first[T]: (i
Enter first[B]: *e
Enter first[F]: (i
Enter follow[E]: $)
Enter follow[A]: $)
Enter follow[T]: +)$
Enter follow[B]: +)$
Enter follow[F]: +*)$

Parsing Table:
        +       *       (                      )i       $
E       -       -       E->TA                  -E->TA   -
A       A->+TA  -       -                      A->e     -       A->e
T       -       -       T->FB                  -T->FB   -
B       B->e    B->*FB  -                      B->e     -       B->e
F       -       -       F->(E)                 -F->i    -
*/
