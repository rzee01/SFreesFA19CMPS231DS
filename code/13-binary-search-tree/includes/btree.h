#include <list>
#include <iostream>
class node
{
public:
    node(node *left, node *right, int value) : left(left), right(right), value(value) {}
    ~node()
    {
        if (left != nullptr)
            delete left;
        if (right != nullptr)
            delete right;
    }
    node *left;
    node *right;
    int value;
};

class BSTree
{
public:
    BSTree()
    {
        root = nullptr;
    }
    ~BSTree()
    {
        // This might look weird... because clearly the root node likely
        // has children.  However, the node's destructor itself deletes
        // it's own left and right.  A recursive destructor!
        if (root != nullptr)
        {
            delete root;
        }
    }
    void insert(int value)
    {
        // NEVER expose a method that requires one of your internal
        // member variables as a parameter!  We must kick off a recursive
        // call to insert at the node, but the user doesn't have access to
        // root - so we wrap the private, recursive _insert call in a public
        // one.
        _insert(root, value);
    }
    bool find(int value)
    {
        // notice the pattern - as with insert, we wrap a recursive function
        // with a public one that starts the process.
        return _find(root, value);
    }

    void remove(int value)
    {
        _remove(root, value);
    }

    // This creates a list, that can be traversed, representing the
    // values in ascending order.  It's primarily for debugging, but
    // could be the start of an iterator implementation...
    std::list<int> as_list()
    {
        std::list<int> traversal;
        _as_list(traversal, root);
        return traversal;
    }

private:
    node *root;
    // This is a recursive function, called internally by the public
    // insert method.  Notice that the tree parameter is a pointer, but
    // is also passed by reference.  This method CHANGES what tree points
    // to in it's base case - which creates a new node.  That change
    // must happen on the pointer within the general data structure, not
    // a locally copied parameter variable!
    void _insert(node *&tree, int value)
    {
        if (tree == nullptr)
        {
            tree = new node(nullptr, nullptr, value);
        }
        else if (tree->value > value)
        {
            _insert(tree->left, value);
        }
        else if (tree->value < value)
        {
            _insert(tree->right, value);
        }
        else
        {
            // duplicate
            return;
        }
    }

    bool _find(node *tree, int value)
    {
        if (tree == nullptr)
            return false;

        else if (tree->value == value)
        {
            return true;
        }
        else if (tree->value > value)
        {
            return _find(tree->left, value);
        }
        else
        {
            return _find(tree->right, value);
        }
    }

    void _as_list(std::list<int> &list, node *tree)
    {
        if (tree == nullptr)
            return;
        _as_list(list, tree->left);
        list.push_back(tree->value);
        _as_list(list, tree->right);
    }

    void _remove(node *&tree, int value)
    {
        if (tree == nullptr)
        {
            // We didn't find the value anywhere... just return
            return;
        }
        else if (tree->value > value)
        {
            _remove(tree->left, value);
        }
        else if (tree->value < value)
        {
            _remove(tree->right, value);
        }
        else
        {
            // this is the node to delete
            if (tree->left == nullptr && tree->right == nullptr)
            {
                // leaf node.
                delete tree;
                tree = nullptr;
            }
            else if (tree->left != nullptr && tree->right != nullptr)
            {
                // tricky case, two children.
                tree->value = remove_and_return_minimum(tree->right);
            }
            else if (tree->left != nullptr)
            {
                // save a reference to the node "tree" points to so we
                // can delete it in a moment...
                node *tmp = tree;
                tree = tree->left;

                // Important:  tmp has a left pointer.
                //             if we call it's destructor right now, it's destructor
                //             will in turn call the destructor on the left child - which
                //             is VERY BAD.  So let's be sure we set it to null first.

                // set the pointer to now point to the node to the left,
                // bypassing the node we are going to delete
                tmp->left = nullptr;
                // remove the node
                delete tmp;
            }
            else
            {
                // save a reference to the node "tree" points to
                node *tmp = tree;
                // set the pointer to now point to the node to the right,
                // bypassing the node we are going to delete
                tree = tree->right;
                tmp->right = nullptr;
                // remove the node
                delete tmp;
            }
        }
    }

    int remove_and_return_minimum(node *&tree)
    {
        if (tree == nullptr)
        {
            throw std::runtime_error("remove_and_return_minimum called on null tree");
        }
        if (tree->left == nullptr)
        {
            // this is the minimum
            int tmp = tree->value;
            node *right = tree->right; // note - this could be null...
            delete tree;
            tree = right; // the pointer originally pointing to "node" now points
                          // to the node on its right
            return tmp;
        }
        else
        {
            return remove_and_return_minimum(tree->left);
        }
    }
};