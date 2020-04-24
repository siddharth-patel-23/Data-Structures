#include <algorithm>
#include <iostream>
#include <vector>
#include <climits>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

struct Node {
  int key;
  int left;
  int right;

  Node() : key(0), left(-1), right(-1) {}
  Node(int key_, int left_, int right_) : key(key_), left(left_), right(right_) {}
};

void inorder(vector<Node> v, int i, long long int &pre, bool &f)
{
    if (v[i].left!=-1) inorder(v, v[i].left, pre, f);
    if (pre>v[i].key)
    {
        f=true;
        return;
    }
    pre=v[i].key;
    if (v[i].right!=-1) inorder(v, v[i].right, pre, f);
}



int main() {
  int nodes;
  cin >> nodes;
  vector<Node> tree;
  for (int i = 0; i < nodes; ++i) {
    int key, left, right;
    cin >> key >> left >> right;
    tree.push_back(Node(key, left, right));
  }
  bool f=false;
  if (nodes>0)
  {
      long long int pre=LONG_MIN;
      inorder(tree, 0, pre, f);
  }
  if (!f) {
    cout << "CORRECT" << endl;
  } else {
    cout << "INCORRECT" << endl;
  }
  return 0;
}
