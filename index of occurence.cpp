#include <iostream>
using namespace std;

void check(string A, string B){
  int pos = A.find(B);

  while(pos != string::npos){
    cout << "Found at position: " << pos << endl;
    break;
  }
}

int main() {
  string A = "abcddbc";
  string B = "cd";
  check(A, B);
  return 0;
}
