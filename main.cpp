#include <iostream>
#include <vector>
#include <unordered_map>
#include "solution.h"

using namespace std;
using namespace sol1485;

/*
Input: root = [[1,null],null,[4,3],[7,0]]
Output: [[1,null],null,[4,3],[7,0]]

tree is: [1,null,4,7]

tree[0] has left in tree[2] and right in tree[3]
tree[2] has left in tree[3]

tree[0] has no random as [1,null] - note the tree[0] node value is 1
trree[2] has radome in tree[3] as [4,3]

    1
     \
      4
     /
   7
*/

Node *testFixture1()
{
  /* build the tree first */
  auto *tree = new Node(1);
  tree->right = new Node(4);
  tree->right->left = new Node(7);

  /* set the random */
  /* 4 -> 7 */
  /* random points to a descendant */
  tree->right->random = tree->right->left;
  /* 7 -> 1 */
  /* random points to an ancestor */
  auto temp = tree;
  tree->right->left->random = temp;

  return tree;
}

/*
   Input: root = [[1,4],null,[1,0],null,[1,5],[1,5]]
   Output: [[1,4],null,[1,0],null,[1,5],[1,5]]
   Explanation: The random pointer of a node can be the node itself.

   tree: [1,null,1,null,1,1]
   1
    \
     1
      \
       1
      /
     1
*/

Node *testFixture2()
{
  /* build the tree first */
  auto *tree = new Node(1);
  tree->right = new Node(1);
  tree->right->right = new Node(1);
  tree->right->right->left = new Node(1);

  /* set the random */
  tree->random = tree->right->right;
  tree->right->random = tree;
  tree->right->right->random = tree->right->right->left;
  /* point to itself */
  tree->right->right->left->random = tree->right->right->left;

  return tree;
}
/*
 Input: root = [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]
 Output: [[1,6],[2,5],[3,4],[4,3],[5,2],[6,1],[7,0]]

 tree = [1,2,3,4,5,6,7]

*/
Node *testFixture3()
{
  /* skip this one */
  return nullptr;
}

Node *testFixture4()
{
  /* build the tree */
  auto *tree = new Node(1);
  tree->left = new Node(2);
  tree->right = new Node(3);

  /* set the random */
  /* left child points to right child */
  tree->left->random = tree->right;
  /* right child points to the left child */
  tree->right->random = tree->left;

  return tree;
}

void test1()
{
  Solution sol;
  auto fixture = testFixture1();
  cout << "Test 1 - expect to see a cloned tree" << endl;
  auto cloned = sol.deepClone(fixture);
  cout << "result: use debugger to verify" << endl;
}

void test2()
{
  Solution sol;
  auto fixture = testFixture2();
  sol.deepClone(fixture);
  cout << "Test 2 - expect to see a cloned tree" << endl;
  cout << "result: use debugger to verify" << endl;
}

main()
{
  test1();
  test2();

  return 0;
}