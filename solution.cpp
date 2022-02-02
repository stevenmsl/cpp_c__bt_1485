#include "solution.h"

#include <functional>
#include <unordered_map>
using namespace sol1485;
using namespace std;

/* takeaways
   - visit the tree and copy it at the same time
     - the key is to make sure the subtree already
       is copied before setting up a node's random
      in the copied tree

   - use an ordered map to mark which node has
     been visited and to map the visited node
     to the copied node.

    - this is needed as we might be jumping
      around while visiting the tree - scenario 4.

   - visit the tree top-down, left-to-right.
     if the left child's random points to
     a right sub-tree, go ahead and build
     that right tree first before going
     back up to the node's root

   - there are four scenarios how the random is set up
     - pointing from an ancestor down to a descendant
       - we are building the tree top-down first
         before setting up the random of a node.
         The descendant should already exist.

     - pointing from a descendant back to an ancestor
       - the tree is copied top-down. The ancestor
         should have existed already

     - pointing from a right child to a left child
       - the tree is copied left-to-right so the left
         child should have existed already

     - pointing from a left child over to a right child
       - we will then copy the right child first
         before setting up the random of the left
         in the copied tree
       - we are fine even though it seems
         the order of visiting is out-of-sync;
         later when we visit the parent of the
         right child we won't visit the right
         child again thanks to the fact that
         the map already recorded the right child
         been visited
*/

Node *Solution::deepClone(Node *root)
{
  /*
    - used to mark which node has been visited
      in the original tree
    - this is needed as we might be jumping
      around while visiting the tree - scenario 4.

  */
  unordered_map<Node *, Node *> cloned;

  function<Node *(Node * node)> copy =
      [&copy, &cloned](Node *node)
  {
    if (node == nullptr)
      /* C++
         - don't return nullptr directly
           or the code will fail to compile
      */
      return node;

    /* we have not visited this node yet*/
    if (cloned.find(node) == cloned.end())
    {
      cloned[node] = new Node(node->val);
      cloned[node]->left = copy(node->left);
      cloned[node]->right = copy(node->right);
      /*
         - this might also trigger copying a subtree
         - for scenario 4
      */
      cloned[node]->random = copy(node->random);
    }
    return cloned[node];
  };

  copy(root);
  /*
    - return the root of the cloned tree
  */
  return cloned[root];
}