

#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using namespace std;
namespace sol1485
{
    struct Node
    {
        int val;
        Node *left;
        Node *right;
        Node *random;
        Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
        Node(int val) : val(val), left(nullptr), right(nullptr), random(nullptr) {}
        Node(int val, Node *left, Node *right, Node *random) : val(val), left(left), right(right), random(random) {}
    };
    class Solution
    {
    public:
        Node *deepClone(Node *root);
    };
}
#endif